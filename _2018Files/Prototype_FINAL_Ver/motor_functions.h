#define PINK_PIN  23
#define RED_PIN   19
#define BLUE_PIN  21
#define GREY_PIN  A14
#define ANALOG_RES 12

// Opperational parameters
#define DEAD_ZONE 1.5f
#define DEAD_TIME_MS 1

// Motor Functions
void init();
void set_voltage(float volt);
void set_direction(bool dir);
void set_speed(float speed);
float speed_to_voltage(float speed);
void enable();
void disable();
void enable_speed();
void disable_speed();

// Test Functions
void btn_wait();
