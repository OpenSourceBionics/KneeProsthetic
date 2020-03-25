/*
 * Auth: Justin Francis
 * Date: 3/7/20
 * Ver: 0.1
 * Sum: Finite state machine: Stance (binary), Swing (PID). 
 * Mod:
 *    
*/

#define thighAngleThres 0.174533 //[rad] (appros 10 [deg])

//desc: function takes sensor readings and returns state
//input: thigh angle [rad] and ground contact boolean  
//return: the state (0 == stance, 1 == swing)
uint8_t finiteStateMachine(float thighAngle, uint8_t groundContact)
{
    if(thighAngle >= thighAngleThres && groundContact)
    {
        return 1;
    }
    
    return 0;
}


//**************************************************************************
/*
 * Auth: Justin Francis
 * Date: 3/24/20
 * Ver: 0.1
 * Sum: Sensor gathering code 
 * Mod:
 *    
*/

