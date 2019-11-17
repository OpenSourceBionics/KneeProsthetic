  /*
 * Auth: Justin Francis
 * Date: 11/16/19
 * Ver: 0.1
 * Sum: Characterizing the makita motor and controller,
 *      or at least trying to, 
 *      written for teensy 3.6
 * 
 * Mod:
 *    
*/

#include <SD.h>
#include <SPI.h>
#include <Encoder.h>

#define _DAC_RESOLUTION 4096 //12 bit
#define _ALLOWED_VOLTAGE_MAX 2.5 //V
#define _TEENSY_VOLTAGE_MAX 3.3 //V

//inc Encoder
Encoder inc(2,3);
int counts, countsOld = 0;
const int INC_RES = 4096; //cpr

//motor vars
int DAC_Pin = A22;
int directionPin = 35;
int enablePin = 34;

elapsedMicros eTime;
int startTime;
const int chipSelect = BUILTIN_SDCARD;

void setup()
{
  
 // Open serial communications and wait for port to open:
  Serial.begin(115200);


  Serial.print("Initializing SD card...");
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

    delay(2000);
    pinMode(DAC_Pin, OUTPUT);
  eTime = 0;
  startTime = 0;
  
}


float voltageCmd = 1.0; //V

void loop()
{
    if((eTime - startTime) >= 50e3)
    {
        analogWrite(DAC_Pin, (voltageCmd*(1024/3.3)));
        voltageCmd -= .01;
        startTime = eTime;
    }


    // Serial.print(eTime);Serial.print(",");Serial.print(voltageCmd);Serial.print(",");Serial.println(inc.read());
  // make a string for assembling the data to log:
  String dataString = "";

  dataString += String(eTime); //time in uS
  dataString += String(","); 
  dataString += String(voltageCmd); //voltage command
  dataString += String(",");
  dataString += String(inc.read()); // counts


  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("DATALOG.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}








