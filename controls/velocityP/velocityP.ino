   /*
 * Auth: Justin Francis
 * Date: 11/12/19
 * Ver: 1.0
 * Sum: experimenting with a proportional position controller (tryna see what's inside the makita motor controller), 
 *      written for teensy 3.6
 * 
 * Mod:
 *    
*/

// #include <Arduino.h>
#include <Encoder.h>

//empirically determined speed curve (x = thetaDotDes [rad/s], y = command voltage[rad/s])
#define MOT_CONTROL_CURVE (0.67 - 0.148*log(abs(thetaDotDes))) 

//control vars
float P = 5; //proportional gain Ku ~= 35
float k; //conversion factor for theta dot to voltage for the controller output
float motCmd;
float err;
float errOld;
float thetaDes = 0;
float theta, thetaDotDes, inputV;
const int POT_PIN = 33; //A14 to get thetaDes

//motor vars
int DAC_Pin = A22;
int directionPin = 35;
int enablePin = 14;

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

    motCmd = MOT_CONTROL_CURVE; //[V]
    motCmd = constrain(motCmd, 0.0, .75);

    analogWrite(DAC_Pin, (int)(motCmd*1024/3.3));
}

float i = 0;
void loop()
{
    //read sensor
    counts = inc.read();
    inputV = analogRead(POT_PIN) * (3.3/1024); //V
    // Serial.print("counts: ");Serial.println(counts);


    //convert to theta
    theta = (((float)counts/INC_RES))*2*PI; //rad
    // if(Serial.available() > 0)
    // {
    //     thetaDes = Serial.parseFloat();
    //     while(Serial.available() > 0)
    //         {
    //             Serial.read();
    //         }
    // }
    // thetaDes = inputV * (2*PI/3.3); //rad
    thetaDes = inputV * (2*PI/3.3) - PI; //rad
    // thetaDes = (PI*sin(i));
    // i += 0.0001;

    Serial.print(theta*.25);Serial.print("\t");Serial.println(thetaDes*.25);
    // Serial.print("theta: ");Serial.println(theta, 6);
    // Serial.print("thetaDes: ");Serial.println(thetaDes, 6);

    //find err
    err = thetaDes - theta; //rad

    // Serial.print("err: ");Serial.println(err, 6);

    //calc correction
    thetaDotDes = P * err; //[rad/s]

    // Serial.print("thetaDotDes: ");Serial.println(thetaDotDes, 6);

    //moved to MotorDrive();
    //convert to voltage
    // motCmd = MOT_CONTROL_CURVE; //[V]
    // motCmd = constrain(motCmd, 0.0, .75);

    // Serial.print("motCmd [v]: ");Serial.println(motCmd, 6);
    // Serial.print("motCmd [bits]: ");Serial.println((int)(motCmd*1024/3.3), 6);


    //moved to MotorDrive()
    //command system
    // digitalWrite(directionPin, HIGH);
    // analogWrite(DAC_Pin, (int)(motCmd*1024/3.3));
    MotorDrive(thetaDotDes);

    //feedback (not needed for P controller)
    Serial.println();
    // delay(1000);
}