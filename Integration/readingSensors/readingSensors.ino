/*
 * Auth: Justin Francis
 * Date: 11/8/19
 * Ver: 0.1
 * Sum: Used for writing sensor libs. Attempt at reading all sensors 
 * on 2khz loop, written for teensy 4.0
 * Mod:
 *    
*/

#include <Encoder.h>
//TODO: figure out why arduino can't see our custom libs in the libraries folder
#include "GRF.h"
#include "AbsEncoder.h"
// not using IncEncoder.h for now bc seems rather uneccesary
// #include "IncEncoder.h"

#define CONTROL_FREQ 2000 //Hz
const int ENC_PIN_A = 1; //TODO:
const int ENC_PIN_B = 2; //TODO:

//sensor objects
GRF grf;
Encoder incEnc(ENC_PIN_A, ENC_PIN_B);
// IncEncoder incEnc;
AbsEncoder absEnc;

//control objects
elapsedMicros elapsedTime; 

//control vars
float* hallVoltages;
int incCount;
float incJointVel;
float absJointPosDeg;
// float absJointVel;
float loopTime; 


void setup()
{
    Serial.begin(115200);

    loopTime = 1e6/CONTROL_FREQ; //uSec

    delay(50);
    Serial.println("begin integration");
}

void loop()
{
    if(elapsedTime >= loopTime)
    {
        readSensors();
    }
    
}

void readSensors()
{
    hallVoltages = grf.getVoltages();
    incCount = incEnc.read();
    // incJointVel = incEnc.vel();
    absJointPosDeg = absEnc.getAngleDeg();
    // absJointVel = absEnc.vel();
}