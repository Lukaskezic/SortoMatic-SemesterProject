/*******************************************************************************
* File Name: Weight_Pin.h  
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

#if !defined(CY_PINS_Weight_Pin_ALIASES_H) /* Pins Weight_Pin_ALIASES_H */
#define CY_PINS_Weight_Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Weight_Pin_0			(Weight_Pin__0__PC)
#define Weight_Pin_0_INTR	((uint16)((uint16)0x0001u << Weight_Pin__0__SHIFT))

#define Weight_Pin_1			(Weight_Pin__1__PC)
#define Weight_Pin_1_INTR	((uint16)((uint16)0x0001u << Weight_Pin__1__SHIFT))

#define Weight_Pin_INTR_ALL	 ((uint16)(Weight_Pin_0_INTR| Weight_Pin_1_INTR))
#define Weight_Pin_Pos			(Weight_Pin__Pos__PC)
#define Weight_Pin_Pos_INTR	((uint16)((uint16)0x0001u << Weight_Pin__0__SHIFT))

#define Weight_Pin_Neg			(Weight_Pin__Neg__PC)
#define Weight_Pin_Neg_INTR	((uint16)((uint16)0x0001u << Weight_Pin__1__SHIFT))

#endif /* End Pins Weight_Pin_ALIASES_H */


/* [] END OF FILE */
