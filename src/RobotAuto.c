#include "RobotAuto.h"
#include "Config.h"

#include <math.h>
#include <stdbool.h>

/**
 * This file contains function for the user to let the robot
 * walk a certain distance, etc. Inplementing all functions
 * with the foundation of Robot.h
 */


// how many CM each motor has moved
double R_LeftMotorMovedCM, R_RightMotorMovedCM;

void R_Stop()
{
    R_Motor_Set(LeftFrontMotor, 0);
    R_Motor_Set(LeftBackMotor, 0);
    R_Motor_Set(RightFrontMotor, 0);
    R_Motor_Set(RightBackMotor, 0);

    R_EncoderResetAll();
}

void R_EncoderResetAll()
{
    encoderReset(LeftEncoder);
    encoderReset(RightEncoder);

    R_LeftMotorMovedCM = R_RightMotorMovedCM = 0;
}

void R_Move(double power)
{
    double LeftPower, RightPower;

    // calculate the power for both sides with PID's P controlAUTO_MOVEMENT
    LeftPower = power - (R_LeftMotorMovedCM - R_RightMotorMovedCM) * KP;
    RightPower = power + (R_LeftMotorMovedCM - R_RightMotorMovedCM) * KP;

    // modify the power if it exceeded
    if (LeftPower > 127)    LeftPower = 127;
    if (LeftPower < -127)   LeftPower = -127;
    if (RightPower > 127)   RightPower = 127;
    if (RightPower < -127)  RightPower = -127;

    // apply the power to the motors
    R_Motor_Set(LeftFrontMotor, (int) LeftPower);
    R_Motor_Set(LeftBackMotor, (int) LeftPower);
    R_Motor_Set(RightFrontMotor, (int) RightPower);
    R_Motor_Set(RightBackMotor, (int) RightPower);

    // change the value of LeftMotorMovedCM and RightMotorMovedCM
    R_LeftMotorMovedCM = ((double)R_Encoder_Get(LeftEncoder)) / 360 * (WHEEL_DIAMETER * PI);
    R_RightMotorMovedCM = ((double)R_Encoder_Get(RightEncoder)) / 360 * (WHEEL_DIAMETER * PI);
}

void R_MoveDistance(double dist, double power, bool OptimizedStop)
{
    R_Stop();
    double LeftPower, RightPower;

    R_EncoderResetAll();


    while (fabs(R_LeftMotorMovedCM) < fabs(dist) || fabs(R_RightMotorMovedCM) < fabs(dist))
    {
        // calculate the power for both sides with PID's P controlAUTO_MOVEMENT
        LeftPower = power - (R_LeftMotorMovedCM - R_RightMotorMovedCM) * KP;
        RightPower = power + (R_LeftMotorMovedCM - R_RightMotorMovedCM) * KP;

        // configure the output power if OptimizedStop is enabled
        if (OptimizedStop)
        {
            if ((fabs(dist) - fabs(R_LeftMotorMovedCM)) <= OPTIMIZEDSTOP_PRESERVE_DIST
                || (fabs(dist) - fabs(R_RightMotorMovedCM)) <= OPTIMIZEDSTOP_PRESERVE_DIST)
            {
                // configure the power because the robot is near the end and OptimizedStop is enabled
                double ConfigureRate = ((double)(fabs(dist) - fabs(R_LeftMotorMovedCM))) / OPTIMIZEDSTOP_PRESERVE_DIST;

                LeftPower *= ConfigureRate;
                RightPower *= ConfigureRate;
            }
        }

        // modify the power if it exceeded
        if (LeftPower > 127)    LeftPower = 127;
        if (LeftPower < -127)   LeftPower = -127;
        if (RightPower > 127)   RightPower = 127;
        if (RightPower < -127)  RightPower = -127;

        // apply the power to the motors
        R_Motor_Set(LeftFrontMotor, (int) LeftPower);
        R_Motor_Set(LeftBackMotor, (int) LeftPower);
        R_Motor_Set(RightFrontMotor, (int) RightPower);
        R_Motor_Set(RightBackMotor, (int) RightPower);

        // change the value of LeftMotorMovedCM and RightMotorMovedCM
        R_LeftMotorMovedCM = ((double)R_Encoder_Get(LeftEncoder)) / 360 * (WHEEL_DIAMETER * PI);
        R_RightMotorMovedCM = ((double)R_Encoder_Get(RightEncoder)) / 360 * (WHEEL_DIAMETER * PI);
    }

    // let the whole robot stop after finishing the move
    R_Stop();
}

void R_Slide(double power)
{
    // Not Implemented!!!
    // TODO: implement this!!!
}

void R_SlideDistance(double dist, double power, bool OptimizedStop)
{
    // Not Implemented!!!
    // TODO: implement this!!!
}

void R_Turn(double power)
{
    double LeftPower, RightPower;

    // calculate the power for both sides with PID's P controlAUTO_MOVEMENT
    LeftPower = power - (R_LeftMotorMovedCM + R_RightMotorMovedCM) * KP;
    RightPower = - power - (R_LeftMotorMovedCM + R_RightMotorMovedCM) * KP;

    // modify the power if it exceeded
    if (LeftPower > 127)    LeftPower = 127;
    if (LeftPower < -127)   LeftPower = -127;
    if (RightPower > 127)   RightPower = 127;
    if (RightPower < -127)  RightPower = -127;

    // apply the power to the motors
    R_Motor_Set(LeftFrontMotor, (int) LeftPower);
    R_Motor_Set(LeftBackMotor, (int) LeftPower);
    R_Motor_Set(RightFrontMotor, (int) RightPower);
    R_Motor_Set(RightBackMotor, (int) RightPower);

    // change the value of LeftMotorMovedCM and RightMotorMovedCM
    R_LeftMotorMovedCM = ((double)R_Encoder_Get(LeftEncoder)) / 360 * (WHEEL_DIAMETER * PI);
    R_RightMotorMovedCM = ((double)R_Encoder_Get(RightEncoder)) / 360 * (WHEEL_DIAMETER * PI);   
}

void R_TurnDegree(double degree, double power, bool OptimizedStop)
{
    R_Stop();
    double LeftPower, RightPower;
    double turn_dist = ROBOT_TURN_RADIUS * PI * degree / 180;  // the distance each wheel is supposed to move

    R_EncoderResetAll();


    while (fabs(R_LeftMotorMovedCM) < fabs(turn_dist) || fabs(R_RightMotorMovedCM) < fabs(turn_dist))
    {
        // calculate the power for both sides with PID's P controlAUTO_MOVEMENT
        LeftPower = power - (R_LeftMotorMovedCM + R_RightMotorMovedCM) * KP;
        RightPower = - power - (R_LeftMotorMovedCM + R_RightMotorMovedCM) * KP;

        // configure the output power if OptimizedStop is enabled
        if (OptimizedStop)
        {
            if ((fabs(turn_dist) - fabs(R_LeftMotorMovedCM)) <= OPTIMIZEDSTOP_PRESERVE_DIST
                || (fabs(turn_dist) - fabs(R_RightMotorMovedCM)) <= OPTIMIZEDSTOP_PRESERVE_DIST)
            {
                // configure the power because the robot is near the end and OptimizedStop is enabled
                double ConfigureRate = ((double)(fabs(turn_dist) - fabs(R_LeftMotorMovedCM))) / OPTIMIZEDSTOP_PRESERVE_DIST;

                LeftPower *= ConfigureRate;
                RightPower *= ConfigureRate;
            }
        }

        // modify the power if it exceeded
        if (LeftPower > 127)    LeftPower = 127;
        if (LeftPower < -127)   LeftPower = -127;
        if (RightPower > 127)   RightPower = 127;
        if (RightPower < -127)  RightPower = -127;

        // apply the power to the motors
        R_Motor_Set(LeftFrontMotor, (int) LeftPower);
        R_Motor_Set(LeftBackMotor, (int) LeftPower);
        R_Motor_Set(RightFrontMotor, (int) RightPower);
        R_Motor_Set(RightBackMotor, (int) RightPower);

        // change the value of LeftMotorMovedCM and RightMotorMovedCM
        R_LeftMotorMovedCM = ((double)R_Encoder_Get(LeftEncoder)) / 360 * (WHEEL_DIAMETER * PI);
        R_RightMotorMovedCM = ((double)R_Encoder_Get(RightEncoder)) / 360 * (WHEEL_DIAMETER * PI);
    }

    // let the whole robot stop after finishing the move
    R_Stop();
}