/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

#include "RobotAuto.h"
extern AutonPos_t AutonPos;


void RedFront_Action()
{

}

void RedBack_Action()
{

}

void BlueFront_Action()
{

}

void BlueBack_Action()
{

}

void Skills_Action()
{

}


/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
void autonomous()
{
    R_Stop();

    switch(AutonPos)
    {
        case RedFront: RedFront_Action(); break;
        case RedBack: RedBack_Action(); break;
        case BlueFront: BlueFront_Action(); break;
        case BlueBack: BlueBack_Action(); break;
        case Skills: Skills_Action(); break;
    }
}
