#include "encoder_functions.h"
#include "motor_functions.h"
#include "joystick_functions.h"
#include "pid_functions.h"

#define ANGLE_OFFSET 0
#define BTN_PIN 2
#define N 10 // Rolling average parameter (angle filtering)
#define ALPHA 0.25 // IIR_WA filter parameter


float angle_lim[2] = {90, 165};

// Control Flow function declarations
void sense();
void process();
void actuate();

// Filtering functions
float iir_filter(float actual, float last_est, float alpha);
float rolling_avg_filter(float actual, float *last_ests, int n);

// Reference and input variables
float setpoint = 0; //[deg] desired position
float input = 0;
bool done = false;

// Time variables
unsigned long long duration = 5000;
unsigned long long start_time = 0;
unsigned long long last_time = 0;
unsigned long long time = 0;
unsigned long long refresh_time = 0;
unsigned long long refresh_period = 4000;
float dt = 0;

// Encoder angle variables
float raw_angle = 0;
float last_angle = 0;
float angle = 0;

// Encoder angle-rate variables
float last_speeds[N] = {0};
float speed = 0;

// Joystick measurement variables
int joystick_x = 0;
int joystick_y = 0;
bool joystick_btn = 0;

// Button state
bool btn_pressed = false;

// Error variables (angle diff)
float err = 0;
float last_err = 0;
float err_dot = 0;

void setup() {
  Serial.begin(9600);
  // Init hardware
  motor_init();
  spi_init();
  joystick_init();

  // Init button and led
  pinMode(BTN_PIN, INPUT_PULLUP);


  // Quickly record and process position data to bring filter to equilibrium
  for (int i = 0; i < 20; i++) {
    sense();
    process();
    delay(30);
  }
  done = false;
  Serial.printf("Current angle: %f\n", angle);
  /*Serial.println("Enter angle for setpoint.");
  while (Serial.available() <= 0);
  setpoint = (float)Serial.parseInt();
  Serial.printf("Setpoint of %.1f deg chosen\n", setpoint);
  */
  Serial.println("Test Begin");
  for (int i = 0; i < 3; i++) {
    sense();
    process();
    delay(30);
  }
  done = false;

  ////   Give the motor power and start the clock
  enable();  
  start_time = millis();
  //  Serial.print("data = [");
}

void loop() {
  sense();
  process();
  actuate();
  Serial.print(joystick_x);
  Serial.print(' ');
  Serial.print(input);
  Serial.print(' ');
  Serial.println(get_angle());
  delay(20);
  ////  Serial.printf("%u,%f,%f,%f,%f;\n", time - start_time, setpoint, angle, err, input);
  //
  //  // Stop when process is finished
  //  // (done is defined as true in process() when finished)
  //  if (done) {
  //    disable(); // Disable motor, kill the power
  //    Serial.print(']');
  //    while (true);
  //  }
}

/*===================================================================*
   ---------------------- FUNCTION DEFINITIONS ----------------------
  ===================================================================*/

/*
   Measure encoder angle, button state, joystick state, and record time
*/
void sense() {
  // Get measurements from each instrument
  float measurement = get_angle();
  bool btn_read = digitalRead(BTN_PIN);
  int joystick_data[3] = {0};
  measure_joystick(joystick_data);

  // Check for validity of encoder data
  if (measurement)
    raw_angle = measurement;

  // Update button var
  btn_pressed = !btn_read; // Invert btn_read so 1 is pressed, 0 is unpressed

  // Unpack joystick data
  joystick_x = -joystick_data[0];
  joystick_y = joystick_data[1];
  joystick_btn = !joystick_data[2]; // Invert btn so 1 is pressed, 0 is unpressed

  // Update timestamps
  last_time = time;
  time = millis();
}

/*
    Post-process the current data
*/
void process() {
  // IIR filter the angle
  last_angle = angle;
  angle = iir_filter(raw_angle - ANGLE_OFFSET, last_angle, ALPHA);

  // Calculate angular rate from measurement
  long long DT = time - last_time;
  dt = (float)DT / 1000; // Convert to seconds
  float raw_speed = (angle - last_angle) / dt;

  // Update array of speed history
  for (int i = 0; i < N - 1; i++)
    last_speeds[i] = last_speeds[i + 1];
  last_speeds[N - 1] = speed;
  // Use speed history to filter speed reading
  speed = rolling_avg_filter(raw_speed, last_speeds, N);

  // PID controller
  //  // Calculate errors
  //  last_err = err;
  //  err = setpoint - raw_angle;
  //  err_dot = (err - last_err) / dt;
  //
  //  // Determine if program has run for full duration
  //  if ((millis() - start_time) >= duration)
  //    done = true;

  // Determine motor input from pd controller
  //  input = constrain(pd(dt, err_dot, err), -255, 255); //PD

  // Joystick Controller
  int max_input = 255;
  input = mapFloat(joystick_x, -515, 515, -max_input, max_input);
  input = constrain(input, -max_input, max_input);
  if (angle >= angle_lim[1] && input >= 0)
    input = 0;
  else if (angle <= angle_lim[0] && input <= 0)
    input = 0;
}

void actuate() {
  set_speed(input);
}
  //iir filter
float iir_filter(float actual, float last_est, float alpha) {
  return alpha * actual + (1 - alpha) * last_est;
}
  // rolling average filter
float rolling_avg_filter(float actual, float *last_ests, int n) {
  float est = actual;
  for (int i = 0; i < n; i++)
    est += last_ests[i];
  est /= n;
  return est;
}
