/*
 * Auth: Justin Francis
 * Date: 10/17/19
 * Ver: 0.1
 * Sum: Attempt at emulating trigger assembly
 * Mod:
*/

//*************************PREPROCESSOR***********************
// #include <Motor.h>


//*************************GLOBALS***********************
// Motor motor;

//*************************SETUP***********************
// void setup()
// {
//     //empty
// }

const int DIR_PIN = 2;

void setup()
{   
    Serial.begin(115200);
    pinMode(A14, OUTPUT);
}

//*************************LOOP***********************
// void loop()
// {
//     motor.Drive(.1);
//     delay(500);
//     motor.Drive(0);
//     delay(500);
//     motor.Drive(-.1);
//     delay(500);
// }

int i = 0;
void loop()
{
    pinMode(2, OUTPUT);
    analogWrite(A14, 4096*(2.5/3.3)*sin(i));
    delay(1);
    Serial.println(4096*(2.5/3.3)*sin(i));
}