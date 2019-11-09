/*
 * Auth: Justin Francis
 * Date: 11/8/19
 * Ver: 0.1
 * Sum: ibrary to control a custom GRF on Open Source Bionic Leg
 *      written for teensy 4.0
 * Mod:
 *    
*/

#include <Arduino.h>
#include "GRF.h"

GRF::GRF()
{
    //setup aRead
    pinMode(anteriorHall, INPUT);
    pinMode(deadCenterHall, INPUT);
    pinMode(posteriorHall, INPUT);
    analogReadResolution(ANALOG_READ_BIT);

    //setup members
    hallReadings = new float[3];
}

GRF::~GRF()
{
    delete hallReadings;
}

/*
returns voltage of anterior, dead center, and posterior hall sensor
respectively in a float arrry
*/
float* GRF::getVoltages()
{

    hallReadings[0] = (ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(anteriorHall);
    hallReadings[1] = (ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(deadCenterHall);
    hallReadings[2] = (ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(posteriorHall);
    
    return hallReadings;
}

