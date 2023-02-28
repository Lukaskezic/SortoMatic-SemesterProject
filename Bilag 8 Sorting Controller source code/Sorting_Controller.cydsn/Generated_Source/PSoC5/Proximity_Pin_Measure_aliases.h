/*******************************************************************************
* File Name: Proximity_Pin_Measure.h  
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

#if !defined(CY_PINS_Proximity_Pin_Measure_ALIASES_H) /* Pins Proximity_Pin_Measure_ALIASES_H */
#define CY_PINS_Proximity_Pin_Measure_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Proximity_Pin_Measure_0			(Proximity_Pin_Measure__0__PC)
#define Proximity_Pin_Measure_0_INTR	((uint16)((uint16)0x0001u << Proximity_Pin_Measure__0__SHIFT))

#define Proximity_Pin_Measure_INTR_ALL	 ((uint16)(Proximity_Pin_Measure_0_INTR))
#define Proximity_Pin_Measure_Interrupt			(Proximity_Pin_Measure__Interrupt__PC)
#define Proximity_Pin_Measure_Interrupt_INTR	((uint16)((uint16)0x0001u << Proximity_Pin_Measure__0__SHIFT))

#endif /* End Pins Proximity_Pin_Measure_ALIASES_H */


/* [] END OF FILE */
