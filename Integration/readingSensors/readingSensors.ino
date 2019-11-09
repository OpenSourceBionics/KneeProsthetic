/*
 * Auth: Justin Francis
 * Date: 11/8/19
 * Ver: 0.1
 * Sum: Used for writing sensor libs. Attempt at reading all sensors 
 * on 2khz loop, written for teensy 4.0
 * Mod:
 *    
*/

#define DEBUG //statement
#define ANALOG_READ_RES 8192 //13 bit
#define ANALOG_READ_BIT 13 //13 bit
#define ANALOG_MAX_V 3.3 // max voltage readable by pin [V]
#ifdef DEBUG
#define MULTIPLIER 100 //increase signal for plot
#define OFFSET 50 //plot signals in same region
#endif

const int hallPinF = A1; //analog pin
const int hallPinM = A2; //analog pin
const int hallPinB = A3; //analog pin

void setup()
{
    Serial.begin(115200);
    pinMode(hallPinF, INPUT);
    pinMode(hallPinM, INPUT);
    pinMode(hallPinB, INPUT);

    analogReadResolution(ANALOG_READ_BIT);
    
    delay(50);
    Serial.println("Front Middle Back");
}

void loop()
{
    delay(100);
    Serial.print((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinF)*MULTIPLIER, 6);Serial.print("\t");
    Serial.print((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinB)*MULTIPLIER, 6);Serial.print("\t");
    Serial.print((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinM)*MULTIPLIER, 6);Serial.println();
    
}