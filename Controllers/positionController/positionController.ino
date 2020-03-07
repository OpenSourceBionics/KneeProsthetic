/*
 * Auth: Justin Francis
 * Date: 2/21/20
 * Ver: 0.1
 * Sum: Finite state machine: Stance (binary), Swing (PID). 
 * Mod:
 *    
*/

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>



#define ABSPIN 10 //abs enc cs pin
#define ANGLECOM 0x3FFF //abs enc register that returns measured angle with dynmic angle err compensation
//empirically determined speed curve (x = thetaDotDes [rad/s], y = command voltage[rad/s])
#define MOT_CONTROL_CURVE (0.67 - 0.148*log(abs(thetaDotDes))) 

//teensy 3.2 limits
#define DAC_RES 1023 //10 bit
#define DAC_MAX 3.3 //[V]
#define MOT_MIN_CMD 3.3 //[V]
//as read from abs enc
#define EXTENSION_MAX 298.2 //[deg]
#define FLEXION_MAX 10 //[deg]
#define INPUT_MAX 1.20 //[rad]

SPISettings kneeSettings(10e6, MSBFIRST, SPI_MODE1);

//IMU stuff
const int IMU = 0x68; //i2c addy
const int ACCEL_XOUT_H = 0x3B; //x accelerometer addy
const int ACCEL_RES = 16384.0; //14 bits

float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;
float roll, pitch, yaw;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;

//control vars
float P = 30; //proportional gain K_u ~= 35
float k; //conversion factor for theta dot to voltage for the controller output
float motCmd; //value to output to motor controller
float err; //controller error
float thetaDes = 0; //desire joint position [rad]
float theta, thetaDotDes; //joint position [rad], desire joint velocity [rad/s]

//motor vars
const int DAC_Pin = A14; //motor speed pin
const int directionPin = 5; 
const int enablePin = 4;

//fn prototypes
void MotorDrive(float thetaDotDes);
int8_t finiteStateMachine(float *GRF, float *IMU, uint32_t incEnc);
void stanceController(void);


void setup()
{
    Serial.begin(115200);
    //enable motor
    pinMode(DAC_Pin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    pinMode(enablePin, OUTPUT);

    
    //this is needed for the motor startup sequence
    digitalWrite(enablePin, LOW);
    delay(2);

    //enable spi
    SPI.begin(); //this inits all spi pins on teensy and pulls sck/mosi low and ss HIGH
    pinMode(ABSPIN, OUTPUT);
    digitalWrite(ABSPIN, HIGH);

    //enable IMU
    Wire.begin();   // Initialize comunication
    Wire.setClock(4e5); //fast mode                   
    Wire.beginTransmission(IMU);       // Start communication with IMU6050 // IMU=0x68
    Wire.write(0x6B);                  // Talk to the register 6B
    Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
    Wire.endTransmission(true);        //end the transmission

}



unsigned int absData = 0;
float angle;
void loop()
{
    //read abs enc
    SPI.beginTransaction(kneeSettings);
    digitalWrite(ABSPIN, LOW);
    absData = SPI.transfer16(ANGLECOM);
    digitalWrite(ABSPIN,HIGH);
    
    //convert data to angle 
    absData = (absData & (0x3FFF)); 
    angle = ( (float) absData * 360.0 / 16384.0); //[deg]
    //angle conditioning
    if(angle >= EXTENSION_MAX){
        angle -= EXTENSION_MAX;
    }
    else if(angle <= FLEXION_MAX){
        angle += (360.0 - EXTENSION_MAX);
    }
    else{
        while(1){
            //TODO: need to program some sort of reset or get the other encoder working
            //stop motor
            MotorDrive(0.0);
        }
    }
    //convert to rad
    theta = angle * PI/180; //[rad]
    Serial.print("angle: ");Serial.println(theta);


    // === Read acceleromter data === //
    Wire.beginTransmission(IMU);
    Wire.write(ACCEL_XOUT_H); // Start with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission();
    Wire.requestFrom(IMU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
    //For a range of +-2g, we need to divide the raw values by 16384, according to the datasheet
    AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
    AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
    AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value

    float IMUdata[] = {AccX, AccY, AccZ};
    float GRF[3];
    uint16_t incEnd = 0;
    Serial.print("state: ");Serial.println(finiteStateMachine(IMUdata, GRF, incEnc));

}

/*
 * function to control the motor, takes in a desired velocity and commands the motor
 * no return
*/
void MotorDrive(float thetaDotDes)
{
    if(thetaDotDes >= 0.0)
    {
        digitalWrite(directionPin, HIGH);
    }
    else
    {
        digitalWrite(directionPin, LOW);
    }
    
    digitalWrite(enablePin, HIGH);
    motCmd = MOT_CONTROL_CURVE; //[V]
    Serial.print("Motcmd: ");Serial.println(motCmd);
    motCmd = constrain(motCmd, 0.0, MOT_MIN_CMD); //anything outside of this voltage range cause the controller to pause

    analogWrite(DAC_Pin, (int)(motCmd*DAC_RES/DAC_MAX)); //convert command into voltage
}

/*
 * takes in GRF, IMU, and returns the state
 * stance == 0
 * swing == 1
 * undef == -1
*/
int8_t finiteStateMachine(float *GRF, float *IMU, uint16_t incEnc){
    //indices to trigger around
    const uint8_t antGRF = 0;
    const uint8_t postGRF = 1;
    const uint8_t deadGRF = 2;
    //will only need 1
    const uint8_t sagAcc = 0;
    const uint8_t transAcc = 1;
    const uint8_t coronAcc = 2;
    const float stanceThres = 0.174533; //[rad]
    //will only need 1
    const uint8_t sagGyro = 0;
    const uint8_t transGyro = 1;
    const uint8_t coronGyro = 2;


    //find thigh angle
    float thighAngle = atan(IMU[coronAcc]/IMU[transAcc]); //[rad]

    // if thigh angle <= Stance, return stance 
    if(thighAngle <=  standThres){
        return 1;
    }
    else{return 0;}
    //else return swing

}



/*
 * tightens knee to full extension end stop 
 */
void stanceController(void){
    
}