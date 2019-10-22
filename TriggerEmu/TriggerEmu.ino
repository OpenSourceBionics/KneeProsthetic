/*
 * Auth: Justin Francis
 * Date: 10/17/19
 * Ver: 0.1
 * Sum: Attempt at emulating trigger assembly
 * Mod:
*/

//*************************PREPROCESSOR***********************
#include <Motor.h>


//*************************GLOBALS***********************
Motor motor;

//*************************SETUP***********************
void setup()
{
    //empty
}

//*************************LOOP***********************
void loop()
{
    motor.Drive(.1);
    delay(500);
    motor.Drive(0);
    delay(500);
    motor.Drive(-.1);
    delay(500);
}