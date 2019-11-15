   /*
 * Auth: Justin Francis
 * Date: 11/12/19
 * Ver: 0.1
 * Sum: experimenting with a proportional velocity controller (tryna see what's inside the makita motor controller), 
 *      written for teensy 3.6
 * 
 * Mod:
 *    
*/

#include <Arduino.h>
#include <Encoder.h>

#define _DAC_PIN A14 //built in DAC pin A14
#define _DIRECTION_PIN 3 // digital open-drain (TX)
#define _ENABLE_PIN 14 //A0
#define _DAC_RESOLUTION 4096 //12 bit
#define _ALLOWED_VOLTAGE_MAX 2.5 //V
#define _TEENSY_VOLTAGE_MAX 3.3 //V
#define _REVERSE HIGH //TODO: determine which directions these truly are
#define _FORWARD LOW

//control vars
float P = 10; //proportional gain
float k; //conversion factor for theta dot to voltage for the controller output
float err;
float errOld;
float theta, thetaDot;

//motor vars
int DAC_Pin = A14;
int directionPin = 3;
int enablePin = 14;

//inc Encoder
Encoder inc(2,3);
int counts, countsOld = 0;
const int INC_RES = 4096; //cpr

void setup()
{
    Serial.begin(115200);
    pinMode(DAC_Pin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    pinMode(enablePin, OUTPUT);

}


void MotorRev(int effort)
{
    digitalWrite(directionPin, _REVERSE);
    analogWrite(DAC_Pin, ((1 - std::abs(effort)) * _DAC_RESOLUTION) * (_ALLOWED_VOLTAGE_MAX / _TEENSY_VOLTAGE_MAX));
}

void MotorFor(int effort)
{
    digitalWrite(directionPin, _FORWARD);
    analogWrite(DAC_Pin, ((1 - std::abs(effort)) * _DAC_RESOLUTION) * (_ALLOWED_VOLTAGE_MAX / _TEENSY_VOLTAGE_MAX));
}


void loop()
{
    //read sensor
    counts = inc.read();

    //convert to theta
    theta = (counts/INC_RES)*2*PI;

    //find err

    //calc correction

    //convert to voltage
    

    //feedback



}