/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"

uint16 BELT_SPEED_MAX;
const uint16 BELT_SPEED_OFF = 0;
int BELT_SPEED_NORMAL;

void Belt_Motor_Start()
{
    Motor_PWM_Start();
    BELT_SPEED_MAX = Motor_PWM_ReadPeriod();
}

void Belt_Motor_Set_Speed(uint8 speed)
{
    if (speed < BELT_SPEED_MAX && speed > BELT_SPEED_OFF) 
    {
        Motor_PWM_WriteCompare(speed);
    }
}