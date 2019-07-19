#ifndef _ROBOT_FACILITIES_H_
#define _ROBOT_FACILITIES_H_

/**
 * -----------------------------------------------------------------------------
 *
 * This file contains all robot facilities, like joystick, sensors, motors, etc.
 * 
 * -----------------------------------------------------------------------------
 */

#include "typedefs.h"
#include "API.h"


extern const R_Motor_t LeftFrontMotor;
extern const R_Motor_t RightFrontMotor;
extern const R_Motor_t LeftBackMotor;
extern const R_Motor_t RightBackMotor;

extern Encoder LeftEncoder;
extern Encoder RightEncoder; 

// containing the joystick slot for master
extern const unsigned char joystick;

// sensors, other motors can folllow on like this...
// remember to add them in .c file ++++++++


void InitRobotFacilities();

#endif