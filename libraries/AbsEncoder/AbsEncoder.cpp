   /*
 * Auth: Justin Francis
 * Date: 11/9/19
 * Ver: 1.0
 * Sum: creating and using abs enc, written for teensy 4.0
 * Mod:
 *    
*/
   
#include "AbsEncoder.h"

void AbsEncoder::AbsEncoder()
{
    SPI.begin(); //this inits all spi pins on teensy and pulls sck/mosi low and ss HIGH
    pinMode(ABSPIN, OUTPUT); //set CS pin
    digitalWrite(ABSPIN, HIGH); //deselect chip //does not seem to pull with SPI.begin()
}

void AbsEncoder::~AbsEncoder()
{
    //Unecessary
}

void AbsEncoder::getAngleDeg()
{
    SPI.beginTransaction(kneeSettings);
  
    digitalWrite(ABSPIN, LOW);
    rawData = SPI.transfer16(ANGLECOM);
    digitalWrite(ABSPIN,HIGH);

    rawData = (rawData & (0x3FFF)); //offset data to 14 bit
    angleDeg = ( (float) rawData)) * 360.0 / 16384.0; //convert to degrees
}