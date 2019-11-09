/*
 * Auth: Justin Francis
 * Date: 11/9/19
 * Ver: 0.1
 * Sum: Creation and control of inc encoder from teensy 4.0
 * Mod:
 *    
 *
*/

#include "IncEncoder.h"

void IncEncoder::IncEncoder()
{
    encReadingOld = 0;
}

//not necesary with this lib Encoder.h from pjrc
// void IncEncoder::~IncEncoder()
// {
//     delete encReadings;
// }

int* IncEncoder::read()
{
    encReadingNew = incEnc.read();

    //TODO: return velocity or position, or whatever we want really
}