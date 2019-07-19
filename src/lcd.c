/**
 * ------------------------------------------------------
 * 
 * This file contains code for the LCD management
 * 
 * ------------------------------------------------------
 */

#include "API.h"

#include "lcd.h"
#include "Config.h"


void LCDTask_Handler()
{
    lcdInit(LCD_PIN);
}