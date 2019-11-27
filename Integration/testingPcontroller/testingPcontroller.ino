   /*
 * Auth: Justin Francis
 * Date: 11/27/19
 * Ver: 0.1
 * Sum: experimenting with a proportional position controller (tryna see what's inside the makita motor controller), 
 *      written for teensy 3.2
 * 
 * Mod:
 *    
*/

// #include <Arduino.h>
#include <Encoder.h>

//empirically determined speed curve (x = thetaDotDes [rad/s], y = command voltage[rad/s])
#define MOT_CONTROL_CURVE (0.67 - 0.148*log(abs(thetaDotDes))) 
#define TRIAL

//control vars
float P = 30; //proportional gain K_u ~= 35
float k; //conversion factor for theta dot to voltage for the controller output
float motCmd;
float err;
float errOld;
float thetaDes = 0;
float theta, thetaDotDes, inputV;
const int POT_PIN = 14; //A0 to get thetaDes

//motor vars
const int DAC_Pin = A14;
const int directionPin = 5;
const int enablePin = 4;

//inc Encoder
Encoder inc(2,3);
int counts, countsOld = 0;
const float INC_RES = 4096.0; //cpr

void setup()
{
    Serial.begin(115200);
    pinMode(DAC_Pin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, LOW);
    delay(200);
    pinMode(POT_PIN, INPUT);
    Serial.println("theta thetaDes");

}

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
    motCmd = constrain(motCmd, 0.0, .75);
    // Serial.print("motcmd: "); Serial.println(motCmd);

    analogWrite(DAC_Pin, (int)(motCmd*1024/3.3));
}

float i = 0;
void loop()
{
    //read sensor
    counts = inc.read();
    inputV = analogRead(POT_PIN) * (3.3/1024); //V
    // thetaDes = (PI/2.2*sin(i));
    // i += 0.0001;

    //convert to theta
    theta = (((float)counts/INC_RES))*2*PI; //rad
    thetaDes = inputV * (PI/(3.3*2)) - .5; //rad

    #ifdef TRIAL
    thetaDes  = constrain(thetaDes, -.5, 1.5);
    #endif

    // Serial.print(theta*.25);Serial.print("\t");Serial.println(thetaDes*.25);
    Serial.print("theta: ");Serial.println(theta, 6);
    Serial.print("thetaDes: ");Serial.println(thetaDes, 6);

    //find err
    err = thetaDes - theta; //rad

    //calc correction
    thetaDotDes = P * err; //[rad/s]

    //command system
    MotorDrive(thetaDotDes);

    //feedback (not needed for P controller)
    Serial.println();
    // delay(1000);
}