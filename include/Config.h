#ifndef _CONFIG_H_
#define _CONFIG_H_

/**
 * -----------------------------------------------------------------
 * 
 * The Config file of this project. 
 * It contains user configuration, port_numbers, constants, etc.
 * 
 * -----------------------------------------------------------------
 */

#include "API.h"

#include <stdbool.h>


// all port numbers
// all not set +++++++++++++++++++++++++++++
#define LEFT_FRONT_MOTOR_PIN                0
#define RIGHT_FRONT_MOTOR_PIN               0
#define LEFT_BACK_MOTOR_PIN                 0
#define RIGHT_BACK_MOTOR_PIN                0

#define LEFT_ENCODER_TOP_PIN                0   // note: do not use 10!!!
#define LEFT_ENCODER_BOTTOM_PIN             0   // note: do not use 10!!!
#define RIGHT_ENCODER_TOP_PIN               0   // note: do not use 10!!!
#define RIGHT_ENCODER_BOTTOM_PIN            0   // note: do not use 10!!!

#define LCD_PIN                             uart1



// all dimensions of robot
// all not set +++++++++++++++++++++++++++++
#define WHEEL_DIAMETER                      0
/*
    The turning radius of the robot.
    TURN_RADIUS = sqrt(robot_width^2 + distance_between_wheel^2) / 2
*/
#define ROBOT_TURN_RADIUS                   0



// all values for PID control
// all not set +++++++++++++++++++++++
#define KP                                  3
/*
    if OptimizedStop is enabled,
    the robot will start to slow down 'OPTIMIZEDSTOP_PRESERVE_DIST' cm before the goal
*/
#define OPTIMIZEDSTOP_PRESERVE_DIST         5



// all info about basis motors and encoders(except ports)
// all not set +++++++++++++++++++++++
#define LEFT_FRONT_MOTOR_REVERSED           false
#define RIGHT_FRONT_MOTOR_REVERSED          false
#define LEFT_BACK_MOTOR_REVERSED            false
#define RIGHT_BACK_MOTOR_REVERSED           false
#define LEFT_ENCODER_REVERSED               false
#define RIGHT_ENCODER_REVERSED              false



// all info of joystick action
// all not set +++++++++++++++++++++
// an absolute value for horizontal sliding joystick thresold
#define JOY_HORIZONTAL_SLIDE_THRESOLD       0.4
// the motor value would be joystick_input * CONTROL_P_VAL
#define JOY_CONTROL_P_VAL                   0.95



// all math constants
#define PI                                  3.1415926536

#endif