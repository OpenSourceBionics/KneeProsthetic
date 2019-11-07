#define KP 10.4//6.8//last ku = 8.5
#define KD 0.4528//0.0881//0.3046//0.6-->-.15
#define KI 0.0

float pid(float vel, float last_vel, float pos, float last_pos, float integral);
float pd(float dt, float err_dot, float err);
