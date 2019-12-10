   /*
 * Auth: Justin Francis
 * Date: 11/27/19
 * Ver: 1.0
 * Sum: this is a position P-controller for the Open source powered prosthetic leg,
 *      it oscillates the leg back and forth between 5 deg and 85 deg from vertical,
 *      or it can be controlled with a potentiometer remotely.
 *      written for teensy 3.2
 * 
 * Mod:
 *    
*/

#include <Arduino.h>
#include <Encoder.h>

//empirically determined speed curve (x = thetaDotDes [rad/s], y = command voltage[rad/s])
#define MOT_CONTROL_CURVE (0.67 - 0.148*log(abs(thetaDotDes))) 
#define MOT_MIN_CMD 2.5

//teensy 3.2 limits
#define DAC_RES 1023 //10 bit
#define DAC_MAX 3.3 //[V]

//incremental encoder interrupt pins
#define IncEncA 2
#define IncEncB 3

//use this for potentiometer control
// #define POT_CTRL

//use this for plotting
// #define PLOTTING

//use this for use with battery pack, comment out if using a current limited power supply
//the reason being, the battery pack can supply enough power to tear the leg apart if a signal
//is being processed incorrectly, this keeps that from happening.
#define TRIAL 

//control vars
float P = 30; //proportional gain K_u ~= 35
float k; //conversion factor for theta dot to voltage for the controller output
float motCmd; //value to output to motor controller
float err; //controller error
float thetaDes = 0; //desire joint position [rad]
float theta, thetaDotDes; //joint position [rad], desire joint velocity [rad/s]

#ifdef POT_CTRL
float inputV; //potentiometer voltage [V]
const int POT_PIN = 14; //potentiometer pin
#endif

//motor vars
const int DAC_Pin = A14; //motor speed pin
const int directionPin = 5; 
const int enablePin = 4;

//incremental Encoder
Encoder inc(IncEncA,IncEncB); //interrupt attach to digital pins 2 and 3
int counts, countsOld = 0; 
const float INC_RES = 4096.0; //resolution of encoder [cpr]

void setup()
{
    Serial.begin(115200); //turn on serial port (display) at 115200 baud
    //set ports
    pinMode(DAC_Pin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    pinMode(enablePin, OUTPUT);

    #ifdef POT_CTRL
    pinMode(POT_PIN, INPUT);
    #endif

    //this is needed for the motor startup sequence
    digitalWrite(enablePin, LOW);
    delay(200);
    
    #ifdef PLOTTING
    Serial.println("theta thetaDes");
    #endif
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
    motCmd = constrain(motCmd, 0.0, MOT_MIN_CMD); //anything outside of this voltage range cause the controller to pause

    analogWrite(DAC_Pin, (int)(motCmd*DAC_RES/DAC_MAX)); //convert command into voltage
}

float i = 0; //used for oscillations
void loop()
{
    //read sensor
    counts = inc.read();

    //potentiometer control
    #ifdef POT_CTRL
    inputV = analogRead(POT_PIN) * (3.3/1024); //[V]
    #endif

    //standard oscillations
    #ifndef POT_CTRL
    thetaDes = (PI/2.2*sin(i));
    i += 0.0001; //this needs to decrease if the teensy 4.0 is used because of faster clock
    #endif

    //convert to radians
    theta = (((float)counts/INC_RES))*2*PI; //[rad]

    #ifdef POT_CTRL
    thetaDes = inputV * (PI/(3.3*2)) - .5; //[rad]
    #endif

    #ifdef TRIAL
    thetaDes  = constrain(thetaDes, -.5, 1.5);
    #endif

    #ifdef PLOTTING
    Serial.print(theta*.25);Serial.print("\t");Serial.println(thetaDes*.25);
    #endif

    //find err
    err = thetaDes - theta; //rad

    //calc correction
    thetaDotDes = P * err; //[rad/s]

    //command system
    MotorDrive(thetaDotDes);

    //feedback (not needed for P controller)
}