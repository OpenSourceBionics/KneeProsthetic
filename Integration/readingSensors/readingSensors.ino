/*
 * Auth: Justin Francis
 * Date: 11/8/19
 * Ver: 0.1
 * Sum: Used for writing sensor libs. Attempt at reading all sensors 
 * on 2khz loop, written for teensy 4.0
 * Mod:
 *    
*/

//TODO: figure out why arduino can't see our custom libs in the libraries folder
#include "GRF.h"
#include "AbsEncoder.h"
#include "IncEncoder.h"

#define CONTROL_FREQ 2000 //Hz

//sensor objects
GRF grf;
IncEncoder incEnc;
AbsEncoder absEnc;

//control objects
elapsedMicros elapsedTime; 

//control vars
float* hallVoltages;
int incCounts;
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
    incCount = incEnc.getCount();
    // incJointVel = incEnc.vel();
    absJointPosDeg = absEnc.getAngleDeg();
    // absJointVel = absEnc.vel();
}