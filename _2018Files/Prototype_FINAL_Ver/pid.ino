#include "pid_functions.h"

float pid(float dt, float err_dot, float err, float err_int) {
  return KP * err + KI * err_int + KD * err_dot;
}

float pd(float dt, float err_dot, float err) {
  return KP * err + KD * err_dot;
}
