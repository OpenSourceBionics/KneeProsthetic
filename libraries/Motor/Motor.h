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

public:
  Motor();
  Motor(int dacPin, int dirPin, int enPin);
  void Drive(float effort);
  void Stop(void);
  void FreeSpin(void);

};
#endif
