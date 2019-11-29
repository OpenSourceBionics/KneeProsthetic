/*
 * Auth: Justin Francis
 * Date: 10/25/19
 * Ver: 0.1
 * Sum: Attempt at validating hall grf
 * Mod:
 *    
*/

#define ANALOG_READ_RES 8192 //13 bit
#define ANALOG_READ_BIT 13 //13 bit
#define ANALOG_MAX_V 3.3 // max voltage readable by pin [V]
#define MULTIPLIER 100 //increase signal for plot
#define OFFSET 50 //plot signals in same region

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