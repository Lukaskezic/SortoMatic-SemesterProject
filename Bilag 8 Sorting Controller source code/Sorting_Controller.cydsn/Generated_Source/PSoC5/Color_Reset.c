/*******************************************************************************
* File Name: Color_Reset.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Color_Reset.h"

/* Check for removal by optimization */
#if !defined(Color_Reset_Sync_ctrl_reg__REMOVED)

    
/*******************************************************************************
* Function Name: Color_Reset_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void Color_Reset_Write(uint8 control) 
{
    Color_Reset_Control = control;
}


/*******************************************************************************
* Function Name: Color_Reset_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 Color_Reset_Read(void) 
{
    return Color_Reset_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
