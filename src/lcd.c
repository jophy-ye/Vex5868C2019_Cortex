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
#include "typedefs.h"

#include <stdbool.h>


bool LCD_LeftBtnStat, LCD_CenterBtnStat, LCD_RightBtnStat;
bool Screen_Changed;    // set to true if the screen has changed but not yet done anything for it
Page_Act_t Page_Act;    // the current active page

/** 
 * values can be: 0 ~ 4, each accordingly be:
 * RedFront, RedBack, BlueFront, BlueBack, Skills
 * */ 
short AutonPos_CurrentSelection;
const char* AutonPos_Text[] = 
    { "    RedFront    ", 
      "     RedBack    ", 
      "    BlueFront   ", 
      "    BlueBack    ", 
      "     Skills     " };


void getLCDBUttonPressed()
{
    unsigned int LCD_Btn_Stat = lcdReadButtons(LCD_PIN);
    LCD_LeftBtnStat = LCD_Btn_Stat >> 2;
    LCD_Btn_Stat -= (LCD_Btn_Stat >> 2) << 2;
    LCD_CenterBtnStat = LCD_Btn_Stat >> 1;
    LCD_Btn_Stat -= (LCD_Btn_Stat >> 1) << 1;
    LCD_CenterBtnStat = LCD_Btn_Stat >> 0;
}


void LCDTask_Handler()
{
    lcdInit(LCD_PIN);
    lcdClear(LCD_PIN);
    Page_Act = Initialize_Main;
    Screen_Changed = false;
    AutonPos_CurrentSelection = 0;

    while(true)
    {
        getLCDBUttonPressed();

        switch(Page_Act)
        {
            case Initialize_Main: Initialize_Main_Handler(); break;
            case AutonSelect: AutonSelect_Handler(); break;
            case AutonConfirm: AutonConfirm_Handler(); break;
            case RobotCheck: RobotCheck_Handler(); break;
        }

        delay(150);
    }
}



void Initialize_Main_Handler()
{
    /**
     * if the screen has changed, display the message
     * if not, just detect the buttons
     */
    if (Screen_Changed)
    {
        lcdSetText(LCD_PIN, 1, " Welcome, 5868C ");
        lcdSetText(LCD_PIN, 2, "Auton_S    Check");
        Screen_Changed = false;
    }

    if (LCD_LeftBtnStat)
    {
        // navigate to AutonSelect Page
        Page_Act = AutonSelect;
        Screen_Changed = true;
    }
    else if (LCD_RightBtnStat)
    {
        // navigate to RobotCheck Page
        Page_Act = RobotCheck;
        Screen_Changed = true;
    }
}

void AutonSelect_Handler()
{
    /**
     * if the screen has changed, display the message
     * if not, just detect the buttons
     */
    if (Screen_Changed)
    {
        lcdSetText(LCD_PIN, 2, " <   Confirm  > ");
        Screen_Changed = false;
    }

    if (LCD_CenterBtnStat)
    {
        Screen_Changed = true;
        Page_Act = AutonConfirm;
    }
    else if (LCD_LeftBtnStat)
    {
        AutonPos_CurrentSelection--;
        AutonPos_CurrentSelection = AutonPos_CurrentSelection % 5;
    }
    else if (LCD_RightBtnStat)
    {
        AutonPos_CurrentSelection++;
        AutonPos_CurrentSelection = AutonPos_CurrentSelection % 5;
    }

    // set the text for the current selection
    lcdSetText(LCD_PIN, 1, AutonPos_Text[AutonPos_CurrentSelection]);
}

void AutonConfirm_Handler()
{
    /**
     * if the screen has changed, display the message
     * if not, just detect the buttons
     */
    if (Screen_Changed)
    {
        lcdSetText(LCD_PIN, 1, AutonPos_Text[AutonPos_CurrentSelection]);
        lcdSetText(LCD_PIN, 2, "Sure?   No   Yes");
        Screen_Changed = false;
    }

    if (LCD_CenterBtnStat)
    {
        Screen_Changed = true;
        Page_Act = Initialize_Main;
    }
    else if (LCD_RightBtnStat)
    {
        Screen_Changed = true;
        Page_Act = Initialize_Main;

        extern AutonPos_t AutonPos;
        switch (AutonPos_CurrentSelection)
        {
            case 0: AutonPos = RedFront; break;
            case 1: AutonPos = RedBack; break;
            case 2: AutonPos = BlueFront; break;
            case 3: AutonPos = BlueBack; break;
            case 4: AutonPos = Skills; break;
        }
    }
}

void RobotCheck_Handler()
{

}