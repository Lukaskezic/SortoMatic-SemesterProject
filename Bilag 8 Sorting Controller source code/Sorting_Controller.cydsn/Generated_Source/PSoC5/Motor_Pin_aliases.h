/*******************************************************************************
* File Name: Motor_Pin.h  
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

#if !defined(CY_PINS_Motor_Pin_ALIASES_H) /* Pins Motor_Pin_ALIASES_H */
#define CY_PINS_Motor_Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Motor_Pin_0			(Motor_Pin__0__PC)
#define Motor_Pin_0_INTR	((uint16)((uint16)0x0001u << Motor_Pin__0__SHIFT))

#define Motor_Pin_1			(Motor_Pin__1__PC)
#define Motor_Pin_1_INTR	((uint16)((uint16)0x0001u << Motor_Pin__1__SHIFT))

#define Motor_Pin_INTR_ALL	 ((uint16)(Motor_Pin_0_INTR| Motor_Pin_1_INTR))
#define Motor_Pin_IN1			(Motor_Pin__IN1__PC)
#define Motor_Pin_IN1_INTR	((uint16)((uint16)0x0001u << Motor_Pin__0__SHIFT))

#define Motor_Pin_IN2			(Motor_Pin__IN2__PC)
#define Motor_Pin_IN2_INTR	((uint16)((uint16)0x0001u << Motor_Pin__1__SHIFT))

#endif /* End Pins Motor_Pin_ALIASES_H */


/* [] END OF FILE */
