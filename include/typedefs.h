#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

/**
 * -------------------------------------------------------------------
 * 
 * This file contains all of the typedefs we need for the whole program.
 * 
 * -------------------------------------------------------------------
 */

#include <stdbool.h>


/**
 * include the "vector2d" struct
 */
#include "vector2d.h"


/**
 * The 393 Motor type. It is actually containing 
 * the port of that motor, and if it is reversed.
 */
typedef struct
{
    unsigned char port;
    bool reversed;
} R_Motor_t;


/**
 * The starting position of autonomous
 * 
 * skills is also here. When we do skills, chose skills so 
 * the robot will call the specific autonomous action for skills
 */
typedef enum
{
    RedFront, RedBack, BlueFront, BlueBack, Skills
} AutonPos_t;

#endif