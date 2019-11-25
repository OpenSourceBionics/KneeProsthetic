   /*
 * Auth: Justin Francis
 * Date: 11/25/19
 * Ver: 0.1
 * Sum: see if we can quickly switch high voltage, written for teensy 4.0
 * Mod:
 *    
*/

const int motEnPin = 4;

void setup()
{
    Serial.begin(115200);
    pinMode(motEnPin, OUTPUT);
    delay(50);
}

void loop()
{
    Serial.println("voltage high");
    digitalWrite(motEnPin, HIGH);
    delay(5000);
    
    Serial.println("voltage low");
    digitalWrite(motEnPin, LOW);
    delay(5000);
}