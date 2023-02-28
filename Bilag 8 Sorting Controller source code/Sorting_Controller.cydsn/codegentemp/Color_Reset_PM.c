/*******************************************************************************
* File Name: Color_Reset_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Color_Reset.h"

/* Check for removal by optimization */
#if !defined(Color_Reset_Sync_ctrl_reg__REMOVED)

static Color_Reset_BACKUP_STRUCT  Color_Reset_backup = {0u};

    
/*******************************************************************************
* Function Name: Color_Reset_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Color_Reset_SaveConfig(void) 
{
    Color_Reset_backup.controlState = Color_Reset_Control;
}


/*******************************************************************************
* Function Name: Color_Reset_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Color_Reset_RestoreConfig(void) 
{
     Color_Reset_Control = Color_Reset_backup.controlState;
}


/*******************************************************************************
* Function Name: Color_Reset_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Color_Reset_Sleep(void) 
{
    Color_Reset_SaveConfig();
}


/*******************************************************************************
* Function Name: Color_Reset_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Color_Reset_Wakeup(void)  
{
    Color_Reset_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
