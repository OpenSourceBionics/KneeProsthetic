/*
 * Auth: Justin Francis
 * Date: 11/25/19
 * Ver: 0.1
 * Sum: hopefully we're able to easily control the DAC over I2C, 
 *      written for teensy 4.0
 * 
 * Mod:
 *    
*/

#include <Wire.h>
// #include <bitset>

const int DAC_Write = 0x98;
const int DAC_Read = 0x99;

union {
  uint16_t number;
  unsigned char bytes[sizeof(uint16_t)];
} DAC_Cmd;

void setup()
{
    Serial.begin(115200);
    Wire.begin();   // Initialize comunication
    Wire.setClock(4e5); //fast mode      

    while(!Serial)
    {
      //wait
    }
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

    Serial.print("first byte: ");Serial.println(DAC_Write, BIN);
    Serial.print("second: ");Serial.println(0x10, BIN);
    Serial.print("third: ");Serial.println(0x40, BIN);
    Serial.print("fourth: ");Serial.println(0x00, BIN);
}

void loop() 
{
    // digitalWrite(13, HIGH);

    DAC_Cmd.number = 32768;

    Wire.beginTransmission(DAC_Write);       // Start communication with DAC  
    Wire.write(0x10); //ctrl byte that says store and output i2c data
    Wire.write(0x40); //ctrl byte that says store and output i2c data
    Wire.write(0x00); //ctrl byte that says store and output i2c data
    // Wire.write(DAC_Cmd.bytes[1]); //msb
    // Wire.write(DAC_Cmd.bytes[0]); //lsb
    Wire.endTransmission(true);  
    delay(10);


    // delay(10);
    // digitalWrite(13, LOW);
    // delay(10);


    // DAC_Cmd.number = 32768;

    // Serial.print("binary: ");Serial.println(32768, BIN);
    // Serial.print("number: ");Serial.println(c.number);
    // Serial.print("binary union: ");Serial.println((char)c.bytes[0], BIN);Serial.println((char)c.bytes[1], BIN);
    // Serial.println();
    // delay(2000);
}