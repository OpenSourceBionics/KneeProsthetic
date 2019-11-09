/*
 * Auth: Justin Francis
 * Date: 11/8/19
 * Ver: 0.1
 * Sum: Used for writing sensor libs. Attempt at reading all sensors 
 * on 2khz loop, written for teensy 4.0
 * Mod:
 *    
*/

#include <GRF.h>

GRF grf;
float* hallReadings;

void setup()
{
    Serial.begin(115200);
    delay(50);
    Serial.println("begin testing...");
}

void loop()
{
    hallReadings = grf.read();
    Serial.println(hallReadings[0]);
    Serial.println(hallReadings[1]);
    Serial.println(hallReadings[2]);
    

}