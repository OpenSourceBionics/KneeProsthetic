/*
 * Auth: Justin Francis
 * Date: 11/6/19
 * Ver: 1.0
 * Sum: Attempt at reading abs enc, written for teensy 4.0
 * Mod:
 *    
*/

#include <SPI.h>
#define DEBUG //debug statement
#define ABSPIN 10 //abs enc cs pin
#define ANGLECOM 0x3FFF //abs enc register that returns measured angle with dynmic angle err compensation

SPISettings kneeSettings(10e6, MSBFIRST, SPI_MODE1);

void setup()
{
    #ifdef DEBUG
    Serial.begin(115200);
    #endif

    SPI.begin(); //this inits all spi pins on teensy and pulls sck/mosi low and ss HIGH
    pinMode(ABSPIN, OUTPUT);
    digitalWrite(ABSPIN, HIGH);

}

void loop()
{
    unsigned int angle;
    SPI.beginTransaction(kneeSettings);
  
    digitalWrite(ABSPIN, LOW);
    angle = SPI.transfer16(ANGLECOM);
    digitalWrite(ABSPIN,HIGH);

    angle = (angle & (0x3FFF)); 
    float pos = ( (float) angle) * 360.0 / 16384.0;
    Serial.println(pos);
}