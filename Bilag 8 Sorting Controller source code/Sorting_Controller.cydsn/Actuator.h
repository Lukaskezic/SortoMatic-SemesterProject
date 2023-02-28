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

enum Actuator_dir{
    IN1 = 1,
    IN2 = 0,
};

const uint16 ACTUATOR_DELAY = 3000;  // ms delay

// ******************
// * Extends the actuator and turns it
//      off after a period
// ******************
void Actuator_Extend()
{
    // Set direction
    Actuator_Dir_Write(IN1);
    Actuator_PWM_Start();
    
    // Wait till extended
    // TODO bad implemenentation. Use pins on actuator
    CyDelay(ACTUATOR_DELAY);
    Actuator_PWM_Stop();
}

// ******************
// * Retracts the actuator and turns it
//      off after a period
// ******************
void Actuator_Retract()
{
    // Set direction
    Actuator_Dir_Write(IN2);
    Actuator_PWM_Start();
    
    // Wait till extended
    // TODO bad implemenentation. Use pins on actuator
    CyDelay(ACTUATOR_DELAY);
    Actuator_PWM_Stop();
}