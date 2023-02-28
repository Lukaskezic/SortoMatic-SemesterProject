/*******************************************************************************
* File Name: IR_Actuator.h  
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

#if !defined(CY_PINS_IR_Actuator_ALIASES_H) /* Pins IR_Actuator_ALIASES_H */
#define CY_PINS_IR_Actuator_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define IR_Actuator_0			(IR_Actuator__0__PC)
#define IR_Actuator_0_INTR	((uint16)((uint16)0x0001u << IR_Actuator__0__SHIFT))

#define IR_Actuator_INTR_ALL	 ((uint16)(IR_Actuator_0_INTR))
#define IR_Actuator_Interrupt			(IR_Actuator__Interrupt__PC)
#define IR_Actuator_Interrupt_INTR	((uint16)((uint16)0x0001u << IR_Actuator__0__SHIFT))

#endif /* End Pins IR_Actuator_ALIASES_H */


/* [] END OF FILE */
