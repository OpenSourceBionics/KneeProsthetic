/*
 * Auth: Justin Francis
 * Date: 11/8/19
 * Ver: 0.1
 * Sum: ibrary to control a custom GRF on Open Source Bionic Leg
 *      written for teensy 4.0
 * Mod:
 *    
*/

#include "GRF.h"

GRF::GRF()
{
    hallPinF = A1; //analog pin
    const int hallPinM = A2; //analog pin
    const int hallPinB = A3; //analog pin
    Serial.begin(115200);
    pinMode(hallPinF, INPUT);
    pinMode(hallPinM, INPUT);
    pinMode(hallPinB, INPUT);

    analogReadResolution(ANALOG_READ_BIT);
    
    delay(50);
    Serial.println("Front Middle Back");
}

void loop()
{
    delay(100);
    Serial.print((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinF)*MULTIPLIER, 6);Serial.print("\t");
    Serial.print((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinB)*MULTIPLIER, 6);Serial.print("\t");
    Serial.print((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinM)*MULTIPLIER, 6);Serial.println();
    
}