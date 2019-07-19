#ifndef _ROBOT_AUTO_H_
#define _ROBOT_AUTO_H_

#include "API.h"
#include "RobotFacilities.h"
#include "RobotFunc.h"

#include <math.h>
#include <stdbool.h>

/**
 * This file contains function for the user to let the robot
 * walk a certain distance, etc. Inplementing all functions
 * with the foundation of Robot.h
 */



// how many CM each motor has moved
extern double R_LeftMotorMovedCM, R_RightMotorMovedCM;


/*
* Function for the whole robot to stop

* Input: (none)
* Output: (none)
* */
void R_Stop();

/*
* Function to reset the encoder for both sides

* Input: (none)
* Output: (none)
* */
void R_EncoderResetAll();

/*
* Function for the whole robot to start moving

* Input:
*     power (double)      :  The power for the motor (-127 ~ 127)
* Output: (none)

* #Note: if you want to the robot to move with other condition other than distance,
*         apply this function regularly with that condition.
*     Ex:     R_Stop();
*             while ([CONDITION])
*             {R_Move(127);}
*             R_Stop();
* */
void R_Move(double power);

/*
* Function for the whole robot to move a certain distance

* Input:
*     dist (double)       :  The desire distance in centimeters(cm)
*     power (double)      :  The power for the motor (-127 ~ 127)
*     OptimizedStop (bool):  The stop of the movement will be more accurate if true
* Output: (none)

* #Note1: dist is supposed to be positive, please set the rotate direction through power
*     (negative dist will not affect the direction)
* */
void R_MoveDistance(double dist, double power, bool OptimizedStop);

/*
* Function for the whole robot to slide from left to right and vice versa

* Input:
*     power (double)      :  The power for the motor (-127 ~ 127)
* Output: (none)

* #Note: if you want to the robot to turn with other condition other than distance,
*         apply this function regularly with that condition.
*     Ex:     R_Stop();
*             while ([CONDITION])
*             {R_Slide(127);}
*             R_Stop();
* */
void R_Slide(double power);

/*
* Function for the whole robot to slide from left to right and vice versa

* Input:
*     dist (double)       :  The desire distance in centimeters(cm)
*     power (double)      :  The power for the motor (-127 ~ 127)
*     OptimizedStop (bool):  The stop of the movement will be more accurate if true
* Output: (none)

* #Note1: a minus degree will result in left slide, and vise versa.
* #Note2: dist is supposed to be positive, please set the rotate direction through power
*     (negative dist will not affect the direction)
* */
void R_SlideDistance(double dist, double power, bool OptimizedStop);

/*
* Function for the whole robot to swing turn

* Input:
*     power (double)      :  The power for the motor (-127 ~ 127)
* Output: (none)

* #Note: if you want to the robot to turn with other condition other than distance,
*         apply this function regularly with that condition.
*     Ex:     R_Stop();
*             while ([CONDITION])
*             {R_Turn(127);}
*             R_Stop();
* */
void R_Turn(double power);

/*
* Function for the whole robot to swing turn

* Input:
*     degree (double)     :  The desire degree
*     power (double)      :  The power for the motor (-127 ~ 127)
*     OptimizedStop (bool):  The stop of the movement will be more accurate if true
* Output: (none)

* #Note1: a minus degree will result in left swing turn, and vise versa.
* #Note2: degree is supposed to be positive, please set the rotate direction through power
*     (negative dist will not affect the direction)
* */
void R_TurnDegree(double degree, double power, bool OptimizedStop);

#endif
