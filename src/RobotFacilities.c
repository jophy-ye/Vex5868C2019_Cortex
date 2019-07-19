/**
 * -------------------------------------------------------------------
 *
 * This file contains all robot facilities, like joystick, sensors, motors, etc.
 * 
 * -------------------------------------------------------------------
 */

#include "API.h"

#include "typedefs.h"
#include "Config.h"

#include <stdbool.h>


const R_Motor_t LeftFrontMotor = {LEFT_FRONT_MOTOR_PIN, LEFT_FRONT_MOTOR_REVERSED};
const R_Motor_t RightFrontMotor = {RIGHT_FRONT_MOTOR_PIN, RIGHT_FRONT_MOTOR_REVERSED};
const R_Motor_t LeftBackMotor = {LEFT_BACK_MOTOR_PIN, LEFT_BACK_MOTOR_REVERSED};
const R_Motor_t RightBackMotor = {RIGHT_BACK_MOTOR_PIN, RIGHT_BACK_MOTOR_REVERSED};

Encoder LeftEncoder;
Encoder RightEncoder;

// containing the joystick slot for master
const unsigned char joystick = 1;

// sensors, other motors can folllow on like this...
// remember to add them in .h file ++++++++


void InitRobotFacilities()
{
    LeftEncoder = encoderInit(LEFT_ENCODER_TOP_PIN, LEFT_ENCODER_BOTTOM_PIN, LEFT_ENCODER_REVERSED);
    RightEncoder = encoderInit(RIGHT_ENCODER_TOP_PIN, RIGHT_ENCODER_BOTTOM_PIN, RIGHT_ENCODER_REVERSED);
}