   /*
 * Auth: Justin Francis
 * Date: 11/12/19
 * Ver: 0.1
 * Sum: creating and using abs enc, written for teensy 4.0
 * Mod:
 *    
*/




//inc stuff
#include <Encoder.h>
Encoder incEnc(2,3);


//polling stuff
elapsedMicros elapsedTime;
// unsigned int loopTime; //uSec
unsigned int loopTime = (int)5e5; //uSec
const unsigned int loopFreq = 2; //Hz

//IMU stuff
const int IMU = 0x68; //i2c addy
const int ACCEL_XOUT_H = 0x3B; //x accelerometer addy
const int ACCEL_RES = 16384.0; //14 bits
float AccX, AccY, AccZ;
#include <Wire.h>

//Abs stuff
#include <SPI.h>
#define DEBUG //debug statement
#define ABSPIN 10 //abs enc cs pin
#define ANGLECOM 0x3FFF //abs enc register that returns measured angle with dynmic angle err compensation
SPISettings kneeSettings(10e6, MSBFIRST, SPI_MODE1);

//grf stuff
#define ANALOG_READ_RES 8192 //13 bit
#define ANALOG_READ_BIT 13 //13 bit
#define ANALOG_MAX_V 3.3 // max voltage readable by pin [V]
#define MULTIPLIER 100 //increase signal for plot
#define OFFSET 50 //plot signals in same region

const int hallPinF = A1; //analog pin
const int hallPinM = A2; //analog pin
const int hallPinB = A3; //analog pin


void setup()
{
  //this code
  Serial.begin(115200);
  // loopTime = (int)((float)(1/loopFreq)*(int)1e6);
  delay(100);
  Serial.print("LoopTime [uS]: ");Serial.println(loopTime);
  delay(500);

  //imu code
  Wire.begin();   // Initialize comunication
  Wire.setClock(4e5); //fast mode

  //abs code
  SPI.begin(); //this inits all spi pins on teensy and pulls sck/mosi low and ss HIGH
  pinMode(ABSPIN, OUTPUT);
  digitalWrite(ABSPIN, HIGH);
  
  //grf code
  pinMode(hallPinF, INPUT);
  pinMode(hallPinM, INPUT);
  pinMode(hallPinB, INPUT);

  analogReadResolution(ANALOG_READ_BIT);

}

void loop()
{
  if(elapsedTime >= loopTime)
  {
    Serial.print("eTime: ");Serial.println(elapsedTime);

    //abs encunsigned 
    int angle;
    SPI.beginTransaction(kneeSettings);
  
    digitalWrite(ABSPIN, LOW);
    angle = SPI.transfer16(ANGLECOM);
    digitalWrite(ABSPIN,HIGH);

    angle = (angle & (0x3FFF)); 
    float pos = ( (float) angle) * 360.0 / 16384.0;
    Serial.print("absenc pos: ");Serial.println(pos);


    //inc stuff
    Serial.print("incenc counts: ");Serial.println(incEnc.read());

    //grf stuff
    Serial.print("hall 1: "); Serial.println((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinF));
    Serial.print("hall 2: "); Serial.println((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinM));
    Serial.print("hall 3: "); Serial.println((ANALOG_MAX_V/ANALOG_READ_RES)*analogRead(hallPinB));

    //imu stuff
    // === Read acceleromter data === //
  Wire.beginTransmission(IMU);
  Wire.write(ACCEL_XOUT_H); // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission();
  Wire.requestFrom(IMU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  //For a range of +-2g, we need to divide the raw values by 16384, according to the datasheet
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value

  Serial.print("AccX: ");Serial.println(AccX); 
  Serial.print("AccY: ");Serial.println(AccY); 
  Serial.print("AccZ: ");Serial.println(AccZ); 
    
    Serial.println();
    elapsedTime = 0;
  }


  }