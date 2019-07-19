#ifndef _LCD_H_
#define _LCD_H_

/**
 * ------------------------------------------------------
 * 
 * This file contains code for the LCD management
 * 
 * ------------------------------------------------------
 */

#include "API.h"

#include <stdbool.h>


// type for the current active screen we are on
typedef enum {
    Initialize_Main,    // the home page
    AutonSelect,        // the page for selecting autonomous
    AutonConfirm,       // the page for confirming the autonomous selection
    RobotCheck          // the page for robot check
} Page_Act_t;


/**
 * Get the 3 buttons status on the LCD
 * stored accordingly in LCD_LeftBtnStat, LCD_CenterBtnStat, and LCD_RightBtnStat
 */
void getLCDBUttonPressed();

/**
 * the task handler function for handling LCD
 */
void LCDTask_Handler();



/**
 * Here follows a few functions, 
 * each used to handle a different screen
 * 
 * They will be called by the main loop
 */
void Initialize_Main_Handler();

void AutonSelect_Handler();

void AutonConfirm_Handler();

void RobotCheck_Handler();


#endif