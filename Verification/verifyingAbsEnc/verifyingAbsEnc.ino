/*
 * Auth: Justin Francis
 * Date: 11/6/19
 * Ver: 0.1
 * Sum: Attempt at reading abs enc, written for teensy 4.0
 * Mod:
 *    
*/

#include <SPI.h>
#define DEBUG //debug statement
#define ABSPIN 9 //abs enc cs pin
#define ANGLECOM 0x3FFF //abs enc register that returns measured angle with dynmic angle err compensation

SPISettings kneeSettings(4e6, MSBFIRST, SPI_MODE1);

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
//      unsigned int angle;
//   SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  
//   //Send the Command Frame
//   digitalWrite(ABSPIN, LOW);
//   delayMicroseconds(1);
//   SPI.transfer16(0xFFFF);
//   digitalWrite(ABSPIN,HIGH);

//   //Read data frame
//   digitalWrite(ABSPIN, LOW);
//   delayMicroseconds(1);
//   angle = SPI.transfer16(0xC000);
//   digitalWrite(ABSPIN, HIGH);
//   SPI.endTransaction();
//     Serial.print("data: "); Serial.println(angle, HEX);
//   angle = (angle & (0x3FFF)); 
//   float pos = ( (float) angle) * 360.0 / 16384.0;
//   delay(1);
//   Serial.print("pos: "); Serial.println(pos);


    SPI.beginTransaction(kneeSettings);
    digitalWrite(ABSPIN, LOW);
    delayMicroseconds(1);
    int32_t dataIn = SPI.transfer16(0x3FFF);
    delayMicroseconds(10);
    digitalWrite(ABSPIN, HIGH);
    SPI.endTransaction();

delay(1);
    #ifdef DEBUG
    Serial.println(dataIn);
    #endif
}