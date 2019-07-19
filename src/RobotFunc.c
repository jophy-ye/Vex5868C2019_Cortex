#include "API.h"

#include "RobotFunc.h"
#include "typedefs.h"
#include "RobotFacilities.h"


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


int R_Encoder_Get(Encoder enc_input)
{
    return encoderGet(enc_input);

    // TODO: Add a algorithm to modify the value
    /**
     * if (enc_input == LeftEncoder)    // since the Encoder type is (void*), we can safely do the comparison
     *     XXX
     * else
     *     XXX
     */
}