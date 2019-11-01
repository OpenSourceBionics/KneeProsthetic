/*
 * Auth: Justin Francis
 * Date: 10/25/19
 * Ver: 0.1
 * Sum: Attempt at validating hall grf
 * Mod:
 *    
*/

#define ANALOG_READ_RES 1024 //10 bit
#define ANALOG_MAX_V 3.3 // max voltage readable by pin [V]
#define MULTIPLIER 100 //increase signal for plot
const int hallPin = 15; //analog pin

void setup()
{
    Serial.begin(115200);
    pinMode(hallPin, INPUT);

    delay(50);
    Serial.println("Begin Read Hall...");
}

void loop()
{
    delay(100);
    // Serial.print("Hall V: ");
    Serial.print((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPin)*MULTIPLIER, 3);Serial.println();
    
}