/*******************************************************************************
* File Name: Weight_ADC_theACLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Weight_ADC_theACLK_H)
#define CY_CLOCK_Weight_ADC_theACLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Weight_ADC_theACLK_Start(void) ;
void Weight_ADC_theACLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Weight_ADC_theACLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Weight_ADC_theACLK_StandbyPower(uint8 state) ;
void Weight_ADC_theACLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Weight_ADC_theACLK_GetDividerRegister(void) ;
void Weight_ADC_theACLK_SetModeRegister(uint8 modeBitMask) ;
void Weight_ADC_theACLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 Weight_ADC_theACLK_GetModeRegister(void) ;
void Weight_ADC_theACLK_SetSourceRegister(uint8 clkSource) ;
uint8 Weight_ADC_theACLK_GetSourceRegister(void) ;
#if defined(Weight_ADC_theACLK__CFG3)
void Weight_ADC_theACLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 Weight_ADC_theACLK_GetPhaseRegister(void) ;
#endif /* defined(Weight_ADC_theACLK__CFG3) */

#define Weight_ADC_theACLK_Enable()                       Weight_ADC_theACLK_Start()
#define Weight_ADC_theACLK_Disable()                      Weight_ADC_theACLK_Stop()
#define Weight_ADC_theACLK_SetDivider(clkDivider)         Weight_ADC_theACLK_SetDividerRegister(clkDivider, 1u)
#define Weight_ADC_theACLK_SetDividerValue(clkDivider)    Weight_ADC_theACLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define Weight_ADC_theACLK_SetMode(clkMode)               Weight_ADC_theACLK_SetModeRegister(clkMode)
#define Weight_ADC_theACLK_SetSource(clkSource)           Weight_ADC_theACLK_SetSourceRegister(clkSource)
#if defined(Weight_ADC_theACLK__CFG3)
#define Weight_ADC_theACLK_SetPhase(clkPhase)             Weight_ADC_theACLK_SetPhaseRegister(clkPhase)
#define Weight_ADC_theACLK_SetPhaseValue(clkPhase)        Weight_ADC_theACLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Weight_ADC_theACLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Weight_ADC_theACLK_CLKEN              (* (reg8 *) Weight_ADC_theACLK__PM_ACT_CFG)
#define Weight_ADC_theACLK_CLKEN_PTR          ((reg8 *) Weight_ADC_theACLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Weight_ADC_theACLK_CLKSTBY            (* (reg8 *) Weight_ADC_theACLK__PM_STBY_CFG)
#define Weight_ADC_theACLK_CLKSTBY_PTR        ((reg8 *) Weight_ADC_theACLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Weight_ADC_theACLK_DIV_LSB            (* (reg8 *) Weight_ADC_theACLK__CFG0)
#define Weight_ADC_theACLK_DIV_LSB_PTR        ((reg8 *) Weight_ADC_theACLK__CFG0)
#define Weight_ADC_theACLK_DIV_PTR            ((reg16 *) Weight_ADC_theACLK__CFG0)

/* Clock MSB divider configuration register. */
#define Weight_ADC_theACLK_DIV_MSB            (* (reg8 *) Weight_ADC_theACLK__CFG1)
#define Weight_ADC_theACLK_DIV_MSB_PTR        ((reg8 *) Weight_ADC_theACLK__CFG1)

/* Mode and source configuration register */
#define Weight_ADC_theACLK_MOD_SRC            (* (reg8 *) Weight_ADC_theACLK__CFG2)
#define Weight_ADC_theACLK_MOD_SRC_PTR        ((reg8 *) Weight_ADC_theACLK__CFG2)

#if defined(Weight_ADC_theACLK__CFG3)
/* Analog clock phase configuration register */
#define Weight_ADC_theACLK_PHASE              (* (reg8 *) Weight_ADC_theACLK__CFG3)
#define Weight_ADC_theACLK_PHASE_PTR          ((reg8 *) Weight_ADC_theACLK__CFG3)
#endif /* defined(Weight_ADC_theACLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Weight_ADC_theACLK_CLKEN_MASK         Weight_ADC_theACLK__PM_ACT_MSK
#define Weight_ADC_theACLK_CLKSTBY_MASK       Weight_ADC_theACLK__PM_STBY_MSK

/* CFG2 field masks */
#define Weight_ADC_theACLK_SRC_SEL_MSK        Weight_ADC_theACLK__CFG2_SRC_SEL_MASK
#define Weight_ADC_theACLK_MODE_MASK          (~(Weight_ADC_theACLK_SRC_SEL_MSK))

#if defined(Weight_ADC_theACLK__CFG3)
/* CFG3 phase mask */
#define Weight_ADC_theACLK_PHASE_MASK         Weight_ADC_theACLK__CFG3_PHASE_DLY_MASK
#endif /* defined(Weight_ADC_theACLK__CFG3) */

#endif /* CY_CLOCK_Weight_ADC_theACLK_H */


/* [] END OF FILE */
