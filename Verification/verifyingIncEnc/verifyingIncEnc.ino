   /*
 * Auth: Justin Francis
 * Date: 11/12/19
 * Ver: 0.1
 * Sum: creating and using abs enc, written for teensy 4.0
 * Mod:
 *    
*/

#include <Encoder.h>

Encoder incEnc(2,3);

void setup()
{
    Serial.begin(115200);
    delay(100);
}

void loop()
{
    Serial.print("counts: ");Serial.println(incEnc.read());
    delay(500);
}