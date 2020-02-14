/*
 * Auth: Justin Francis
 * Date: 10/17/19
 * Ver: 0.1
 * Mod:
*/

#ifndef MOTOR_H
#define MOTOR_H


class Motor
{
private:
  int DAC_Pin;
  int directionPin;
  int enablePin;
  float motCmd;

public:
  //defaults to teensy 3.2 pins
  Motor(int dacPin, int dirPin, int enPin);
  void MotorDrive(float effort = 0.0);
  void Stop(void);
  void FreeSpin(void);

};
#endif
