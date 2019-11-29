#include "joystick_functions.h"

static int x_offset = 0;
static int y_offset = 0;

/*
   Sets each of the required pins up for input reading and calibrates
   the sticks such that the resting state in either direction is 0
*/
void joystick_init() {
  pinMode(VRX_PIN, INPUT);
  pinMode(VRY_PIN, INPUT);
  pinMode(JOYSTICK_BUTTON_PIN, INPUT_PULLUP);
  calibrate_joystick();
}

/*
   Collects 500 samples from the x and y sensors for 1 second
   and sets the offsets equal to the average measurements.
*/
void calibrate_joystick() {
  x_offset = 0; y_offset = 0;
  int n = 500;
  long long x_sum = 0, y_sum = 0;
  int measurements[3] = {0};

  for (int i = 0; i < n; i++) {
    measure_joystick(measurements);
    x_sum += measurements[0];
    y_sum += measurements[1];
  }
  x_offset = x_sum / (n+1);
  y_offset = y_sum / (n+1);
  Serial.println(x_offset);
}

/*
   Gets the x, y, and button states and stores them in the input array.
   args:
   @values - [x, y, btn]
   *NOTE* when button is pressed, btn reads as 0 and vice versa
*/
void measure_joystick(int values[3]) {
  int x = analogRead(VRX_PIN) - x_offset;
  int y = analogRead(VRY_PIN) - y_offset;
  int btn = digitalRead(JOYSTICK_BUTTON_PIN);
//  int x = analogRead(VRX_PIN);
//  int y = analogRead(VRY_PIN) - y_offset;
//  int btn = digitalRead(JOYSTICK_BUTTON_PIN);
  values[0] = x;
  values[1] = y;
  values[2] = btn;
}
