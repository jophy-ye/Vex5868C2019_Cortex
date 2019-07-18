#include "API.h"

#include "RobotFunc.h"
#include "typedefs.h"



/**
 * -------------------------------------------------------------------
 *
 * Containing some function implemented by ourselves, on top of PROS API.
 * 
 * -------------------------------------------------------------------
 */


inline int R_Motor_Get(R_Motor_t* Motor)
{
    // check if the pointer is pointing to something
    if (Motor == NULL)
        return 0;

    return motorGet(Motor->port);
}

inline void R_Motor_Set(R_Motor_t* Motor, int speed_input)
{
    // check if the pointer is pointing to something
    if (Motor == NULL)
        return;

    if (Motor->reversed == true)
        motorSet(Motor->port, -speed_input);
    else
        motorSet(Motor->port, speed_input);
}

inline void R_Motor_Stop(R_Motor_t* Motor)
{
    // check if the pointer is pointing to something
    if (Motor == NULL)
        return;
    
    motorStop(Motor->port);
}