   /*
 * Auth: Justin Francis
 * Date: 11/12/19
 * Ver: 1.0
 * Sum: experimenting with a proportional velocity controller (tryna see what's inside the makita motor controller), 
 *      written for teensy 3.6
 * 
 * Mod:
 *    
*/

// #include <Arduino.h>
#include <Encoder.h>
#include <SD.h>
#include <SPI.h>

//empirically determined speed curve (x = thetaDotDes [rad/s], y = command voltage[rad/s])
#define MOT_CONTROL_CURVE (0.67 - 0.148*log(abs(thetaDotDes))) 

const int chipSelect = BUILTIN_SDCARD;

//control vars
float P = 10; //proportional gain
float k; //conversion factor for theta dot to voltage for the controller output
float motCmd;
float err;
float errOld;
float thetaDes = 0.0f;
float theta, thetaDotDes, inputV;
const int POT_PIN = 33; //A14 to get thetaDes
elapsedMicros eTime;

//motor vars
int DAC_Pin = A22;
int directionPin = 35;
int enablePin = 14;

//inc Encoder
Encoder inc(2,3);
int counts, countsOld = 0;
const float INC_RES = 4096.0; //cpr

void setup()
{
    Serial.begin(115200);
    pinMode(DAC_Pin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    pinMode(enablePin, OUTPUT);

    // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

  eTime = 0;
}

void MotorDrive(float thetaDotDes)
{
    if(thetaDotDes >= 0.0)
    {
        digitalWrite(directionPin, HIGH);
    }
    else
    {
        digitalWrite(directionPin, LOW);
    }

    motCmd = MOT_CONTROL_CURVE; //[V]
    motCmd = constrain(motCmd, 0.0, .75);

    analogWrite(DAC_Pin, (int)(motCmd*1024/3.3));
}

void loop()
{
    //step input of 1 radian
    if(eTime >= 1e6)
    {
        thetaDes = 3.0f;
    }

    //read sensor
    counts = inc.read();

    //convert to theta
    theta = (((float)counts/INC_RES))*2*PI; //rad

    //find err
    err = thetaDes - theta; //rad

    //calc correction
    thetaDotDes = P * err; //[rad/s]

    //command system
    MotorDrive(thetaDotDes);

     // make a string for assembling the data to log:
  String dataString = "";

  dataString += String(eTime); //time in uS
  dataString += String(","); 
  dataString += String(thetaDes); //desired position
  dataString += String(","); 
  dataString += String(theta); //position


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
  else {
    Serial.println("error opening datalog.txt");
  } 

    //feedback (not needed for P controller)
}