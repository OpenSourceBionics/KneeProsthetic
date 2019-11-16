/*
 * Auth: Justin Francis
 * Date: 10/17/19
 * Ver: 0.1
 * Sum: attaches pins and commands to a motor object, 
 *      defaults to pins used on Teensy 3.2
 * Mod:
*/
#include <Arduino.h>
#include <cmath>
#include <algorithm>
#include "Motor.h"

//pins for teensy 3.2
#define _DAC_PIN A14 //built in DAC pin A14
#define _DIRECTION_PIN 3 // digital open-drain (TX)
#define _ENABLE_PIN 14 //A0
#define _DAC_RESOLUTION 4096 //12 bit
#define _ALLOWED_VOLTAGE_MAX 2.5 //V
#define _TEENSY_VOLTAGE_MAX 3.3 //V
#define _REVERSE HIGH //TODO: determine which directions these truly are
#define _FORWARD LOW

/*
Initializes motor control pins, defaults to teensy 3.2 setup
*/
Motor::Motor()
{
  Motor(_DAC_PIN, _DIRECTION_PIN, _ENABLE_PIN);
}

Motor::Motor(int dacPin = _DAC_PIN, int dirPin = _DIRECTION_PIN, int enPin = _ENABLE_PIN)
  : DAC_Pin(dacPin), directionPin(dirPin), enablePin(enPin)
{
  pinMode(DAC_Pin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
}

/*
Effort is [-1.000, 1.000] given as a fractional of the maximum
motor effort output
*/
void Motor::Drive(float effort)
{

  //NOTE: constrain() exists only in the arduino compiler
  //if using c++17, use std::clamp()
  effort = constrain(effort, -1.0, 1.0); 

  if(effort == 0)
  {
    return;
  }
  else if(effort < 0)
  {
    digitalWrite(directionPin, _REVERSE);
    analogWrite(DAC_Pin, ((1 - std::abs(effort)) * _DAC_RESOLUTION) * (_ALLOWED_VOLTAGE_MAX / _TEENSY_VOLTAGE_MAX));
  }
  else
  {
    digitalWrite(directionPin, _FORWARD);
    analogWrite(DAC_Pin, ((1 - std::abs(effort)) * _DAC_RESOLUTION) * (_ALLOWED_VOLTAGE_MAX / _TEENSY_VOLTAGE_MAX));
  }
}

/*
Immediately locks motor
*/
void Motor::Stop(void)
{
  //TODO:
}

/*
Puts motor into free spin (backdriveable)
*/
void Motor::FreeSpin(void)
{
  //TODO:
}