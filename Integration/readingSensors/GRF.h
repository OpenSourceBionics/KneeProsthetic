/*
 * Auth: Justin Francis
 * Date: 11/8/19
 * Ver: 0.1
 * Sum: library to control a custom GRF on Open Source Bionic Leg
 *      written for teensy 4.0
 * Mod:
 *    
*/

#ifndef GRF_H
#define GRF_H

#define DEBUG //statement
#define ANALOG_READ_RES 8192 //13 bit
#define ANALOG_READ_BIT 13 //13 bit
#define ANALOG_MAX_V 3.3 // max voltage readable by pin [V]

#ifdef DEBUG
#define MULTIPLIER 100 //increase signal for plot
#define OFFSET 50 //plot signals in same region
#endif


class GRF
{
private: 
    //all pins must be analog read capable
    const int anteriorHall = A1; //anterior hall analog pin
    const int deadCenterHall = A2; //dead center hall analog pin
    const int posteriorHall = A3; //posterior analog pin
    float* hallReadings; // array to return

public:
    GRF(); //constructor
    ~GRF(); //destructor
    //No need for copy
    float* getVoltages(); //reads all pins, returns vals
};

#endif
