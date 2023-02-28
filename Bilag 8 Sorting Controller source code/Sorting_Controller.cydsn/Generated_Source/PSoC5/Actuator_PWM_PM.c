/*******************************************************************************
* File Name: Actuator_PWM_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Actuator_PWM.h"

static Actuator_PWM_backupStruct Actuator_PWM_backup;


/*******************************************************************************
* Function Name: Actuator_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Actuator_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Actuator_PWM_SaveConfig(void) 
{

    #if(!Actuator_PWM_UsingFixedFunction)
        #if(!Actuator_PWM_PWMModeIsCenterAligned)
            Actuator_PWM_backup.PWMPeriod = Actuator_PWM_ReadPeriod();
        #endif /* (!Actuator_PWM_PWMModeIsCenterAligned) */
        Actuator_PWM_backup.PWMUdb = Actuator_PWM_ReadCounter();
        #if (Actuator_PWM_UseStatus)
            Actuator_PWM_backup.InterruptMaskValue = Actuator_PWM_STATUS_MASK;
        #endif /* (Actuator_PWM_UseStatus) */

        #if(Actuator_PWM_DeadBandMode == Actuator_PWM__B_PWM__DBM_256_CLOCKS || \
            Actuator_PWM_DeadBandMode == Actuator_PWM__B_PWM__DBM_2_4_CLOCKS)
            Actuator_PWM_backup.PWMdeadBandValue = Actuator_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Actuator_PWM_KillModeMinTime)
             Actuator_PWM_backup.PWMKillCounterPeriod = Actuator_PWM_ReadKillTime();
        #endif /* (Actuator_PWM_KillModeMinTime) */

        #if(Actuator_PWM_UseControl)
            Actuator_PWM_backup.PWMControlRegister = Actuator_PWM_ReadControlRegister();
        #endif /* (Actuator_PWM_UseControl) */
    #endif  /* (!Actuator_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Actuator_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Actuator_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Actuator_PWM_RestoreConfig(void) 
{
        #if(!Actuator_PWM_UsingFixedFunction)
            #if(!Actuator_PWM_PWMModeIsCenterAligned)
                Actuator_PWM_WritePeriod(Actuator_PWM_backup.PWMPeriod);
            #endif /* (!Actuator_PWM_PWMModeIsCenterAligned) */

            Actuator_PWM_WriteCounter(Actuator_PWM_backup.PWMUdb);

            #if (Actuator_PWM_UseStatus)
                Actuator_PWM_STATUS_MASK = Actuator_PWM_backup.InterruptMaskValue;
            #endif /* (Actuator_PWM_UseStatus) */

            #if(Actuator_PWM_DeadBandMode == Actuator_PWM__B_PWM__DBM_256_CLOCKS || \
                Actuator_PWM_DeadBandMode == Actuator_PWM__B_PWM__DBM_2_4_CLOCKS)
                Actuator_PWM_WriteDeadTime(Actuator_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Actuator_PWM_KillModeMinTime)
                Actuator_PWM_WriteKillTime(Actuator_PWM_backup.PWMKillCounterPeriod);
            #endif /* (Actuator_PWM_KillModeMinTime) */

            #if(Actuator_PWM_UseControl)
                Actuator_PWM_WriteControlRegister(Actuator_PWM_backup.PWMControlRegister);
            #endif /* (Actuator_PWM_UseControl) */
        #endif  /* (!Actuator_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Actuator_PWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Actuator_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Actuator_PWM_Sleep(void) 
{
    #if(Actuator_PWM_UseControl)
        if(Actuator_PWM_CTRL_ENABLE == (Actuator_PWM_CONTROL & Actuator_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            Actuator_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Actuator_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (Actuator_PWM_UseControl) */

    /* Stop component */
    Actuator_PWM_Stop();

    /* Save registers configuration */
    Actuator_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: Actuator_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Actuator_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Actuator_PWM_Wakeup(void) 
{
     /* Restore registers values */
    Actuator_PWM_RestoreConfig();

    if(Actuator_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Actuator_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
