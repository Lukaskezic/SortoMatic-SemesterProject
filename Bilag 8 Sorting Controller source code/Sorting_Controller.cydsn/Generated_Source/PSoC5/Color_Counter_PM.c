/*******************************************************************************
* File Name: Color_Counter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Color_Counter.h"

static Color_Counter_backupStruct Color_Counter_backup;


/*******************************************************************************
* Function Name: Color_Counter_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Color_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Color_Counter_SaveConfig(void) 
{
    #if (!Color_Counter_UsingFixedFunction)

        Color_Counter_backup.CounterUdb = Color_Counter_ReadCounter();

        #if(!Color_Counter_ControlRegRemoved)
            Color_Counter_backup.CounterControlRegister = Color_Counter_ReadControlRegister();
        #endif /* (!Color_Counter_ControlRegRemoved) */

    #endif /* (!Color_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Color_Counter_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Color_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Color_Counter_RestoreConfig(void) 
{      
    #if (!Color_Counter_UsingFixedFunction)

       Color_Counter_WriteCounter(Color_Counter_backup.CounterUdb);

        #if(!Color_Counter_ControlRegRemoved)
            Color_Counter_WriteControlRegister(Color_Counter_backup.CounterControlRegister);
        #endif /* (!Color_Counter_ControlRegRemoved) */

    #endif /* (!Color_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Color_Counter_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Color_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Color_Counter_Sleep(void) 
{
    #if(!Color_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Color_Counter_CTRL_ENABLE == (Color_Counter_CONTROL & Color_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Color_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Color_Counter_backup.CounterEnableState = 0u;
        }
    #else
        Color_Counter_backup.CounterEnableState = 1u;
        if(Color_Counter_backup.CounterEnableState != 0u)
        {
            Color_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Color_Counter_ControlRegRemoved) */
    
    Color_Counter_Stop();
    Color_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Color_Counter_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Color_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Color_Counter_Wakeup(void) 
{
    Color_Counter_RestoreConfig();
    #if(!Color_Counter_ControlRegRemoved)
        if(Color_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Color_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Color_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
