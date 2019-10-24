/*
 * Auth: Justin Francis
 * Date: 10/17/19
 * Ver: 0.1
 * Sum: attaches pins and commands to a motor object, 
 *      defaults to pins used on Teensy 3.2
 * Mod:
*/
#include <Arduino.h>
#include <math.h>
#include "Motor.h"

//pins for teensy 3.2
#define _DAC_PIN A14
#define _DIRECTION_PIN 2
#define _ENABLE_PIN 14 //A0
#define _DAC_RESOLUTION 1024 //12 bit
#define _ALLOWED_VOLTAGE_MAX 2.5 //V
#define _TEENSY_VOLTAGE_MAX 3.3 //V
#define _REVERSE INPUT
#define _FORWARD OUTPUT

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
  if(effort == 0 || effort > 1.0 || effort < -1.0)
  {
    return;
  }
  else if(effort < 0)
  {
    pinMode(directionPin, _REVERSE);
    analogWrite(DAC_Pin, (effort*_DAC_RESOLUTION)*(_ALLOWED_VOLTAGE_MAX/_TEENSY_VOLTAGE_MAX));
  }
  else
  {
    pinMode(directionPin, _FORWARD);
    analogWrite(DAC_Pin, (effort*_DAC_RESOLUTION)*(_ALLOWED_VOLTAGE_MAX/_TEENSY_VOLTAGE_MAX));
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