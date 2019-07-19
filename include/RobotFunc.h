#ifndef _ROBOT_H_
#define _ROBOT_H_


#include "typedefs.h"
#include "API.h"

/**
 * -------------------------------------------------------------------
 *
 * Containing some function implemented by ourselves, on top of PROS API.
 * 
 * -------------------------------------------------------------------
 */


/**
 * A few functions to implement the type we created, R_Motor_t
 */
int R_Motor_Get(R_Motor_t Motor);
void R_Motor_Set(R_Motor_t Motor, int speed_input);
void R_Motor_Stop(R_Motor_t Motor);


/**
 * Get the Encoder value from PROS API, then calibrate it for better accurancy
 */
int R_Encoder_Get(Encoder enc_input);

#endif
