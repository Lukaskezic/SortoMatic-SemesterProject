/*******************************************************************************
* File Name: Actuator_Pin.h  
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

#if !defined(CY_PINS_Actuator_Pin_ALIASES_H) /* Pins Actuator_Pin_ALIASES_H */
#define CY_PINS_Actuator_Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Actuator_Pin_0			(Actuator_Pin__0__PC)
#define Actuator_Pin_0_INTR	((uint16)((uint16)0x0001u << Actuator_Pin__0__SHIFT))

#define Actuator_Pin_1			(Actuator_Pin__1__PC)
#define Actuator_Pin_1_INTR	((uint16)((uint16)0x0001u << Actuator_Pin__1__SHIFT))

#define Actuator_Pin_2			(Actuator_Pin__2__PC)
#define Actuator_Pin_2_INTR	((uint16)((uint16)0x0001u << Actuator_Pin__2__SHIFT))

#define Actuator_Pin_3			(Actuator_Pin__3__PC)
#define Actuator_Pin_3_INTR	((uint16)((uint16)0x0001u << Actuator_Pin__3__SHIFT))

#define Actuator_Pin_INTR_ALL	 ((uint16)(Actuator_Pin_0_INTR| Actuator_Pin_1_INTR| Actuator_Pin_2_INTR| Actuator_Pin_3_INTR))
#define Actuator_Pin_Interrupt			(Actuator_Pin__Interrupt__PC)
#define Actuator_Pin_Interrupt_INTR	((uint16)((uint16)0x0001u << Actuator_Pin__0__SHIFT))

#define Actuator_Pin_Enable			(Actuator_Pin__Enable__PC)
#define Actuator_Pin_Enable_INTR	((uint16)((uint16)0x0001u << Actuator_Pin__1__SHIFT))

#define Actuator_Pin_IN1			(Actuator_Pin__IN1__PC)
#define Actuator_Pin_IN1_INTR	((uint16)((uint16)0x0001u << Actuator_Pin__2__SHIFT))

#define Actuator_Pin_IN2			(Actuator_Pin__IN2__PC)
#define Actuator_Pin_IN2_INTR	((uint16)((uint16)0x0001u << Actuator_Pin__3__SHIFT))

#endif /* End Pins Actuator_Pin_ALIASES_H */


/* [] END OF FILE */
