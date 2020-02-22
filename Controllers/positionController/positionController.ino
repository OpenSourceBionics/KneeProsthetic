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
uint8_t finiteStateMachine(float *GRF, float *accel, float *gyro);
void stanceController(void);


void setup()
{
    Serial.begin(115200);
    pinMode(DAC_Pin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    pinMode(enablePin, OUTPUT);

    
    //this is needed for the motor startup sequence
    digitalWrite(enablePin, LOW);
    delay(2);

    SPI.begin(); //this inits all spi pins on teensy and pulls sck/mosi low and ss HIGH
    pinMode(ABSPIN, OUTPUT);
    digitalWrite(ABSPIN, HIGH);


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
*/
uint8_t finiteStateMachine(float *GRF, float *accel, float *gyro){
    //values to trigger around
    const float antGRF;
    const float postGRF;
    const float deadGRF;
    //will only need 1
    const float xAcc;
    const float yAcc;
    const float zAcc;
    //will only need 1
    const float xGyro;
    const float yGyro;
    const float zGyro;

    // if thigh angle <= Stance, return stance 
    //else return swing

}

/*
 * tightens knee to full extension end stop 
 */
void stanceController(void){
    
}