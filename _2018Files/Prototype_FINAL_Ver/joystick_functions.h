#include <Arduino.h>
#include <MapFloat.h>

#define VRX_PIN A3
#define VRY_PIN A4
#define JOYSTICK_BUTTON_PIN 18

void joystick_init();
void calibrate_joystick();
void measure_joystick(int values[3]);
