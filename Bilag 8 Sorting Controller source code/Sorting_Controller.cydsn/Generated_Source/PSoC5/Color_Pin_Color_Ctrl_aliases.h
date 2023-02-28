/*******************************************************************************
* File Name: Color_Pin_Color_Ctrl.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Color_Pin_Color_Ctrl_ALIASES_H) /* Pins Color_Pin_Color_Ctrl_ALIASES_H */
#define CY_PINS_Color_Pin_Color_Ctrl_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Color_Pin_Color_Ctrl_0			(Color_Pin_Color_Ctrl__0__PC)
#define Color_Pin_Color_Ctrl_0_INTR	((uint16)((uint16)0x0001u << Color_Pin_Color_Ctrl__0__SHIFT))

#define Color_Pin_Color_Ctrl_1			(Color_Pin_Color_Ctrl__1__PC)
#define Color_Pin_Color_Ctrl_1_INTR	((uint16)((uint16)0x0001u << Color_Pin_Color_Ctrl__1__SHIFT))

#define Color_Pin_Color_Ctrl_INTR_ALL	 ((uint16)(Color_Pin_Color_Ctrl_0_INTR| Color_Pin_Color_Ctrl_1_INTR))

#endif /* End Pins Color_Pin_Color_Ctrl_ALIASES_H */


/* [] END OF FILE */
