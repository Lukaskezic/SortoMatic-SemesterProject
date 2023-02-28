/*******************************************************************************
* File Name: IR_Actuator.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_IR_Actuator_H) /* Pins IR_Actuator_H */
#define CY_PINS_IR_Actuator_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IR_Actuator_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IR_Actuator__PORT == 15 && ((IR_Actuator__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IR_Actuator_Write(uint8 value);
void    IR_Actuator_SetDriveMode(uint8 mode);
uint8   IR_Actuator_ReadDataReg(void);
uint8   IR_Actuator_Read(void);
void    IR_Actuator_SetInterruptMode(uint16 position, uint16 mode);
uint8   IR_Actuator_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IR_Actuator_SetDriveMode() function.
     *  @{
     */
        #define IR_Actuator_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IR_Actuator_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IR_Actuator_DM_RES_UP          PIN_DM_RES_UP
        #define IR_Actuator_DM_RES_DWN         PIN_DM_RES_DWN
        #define IR_Actuator_DM_OD_LO           PIN_DM_OD_LO
        #define IR_Actuator_DM_OD_HI           PIN_DM_OD_HI
        #define IR_Actuator_DM_STRONG          PIN_DM_STRONG
        #define IR_Actuator_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IR_Actuator_MASK               IR_Actuator__MASK
#define IR_Actuator_SHIFT              IR_Actuator__SHIFT
#define IR_Actuator_WIDTH              1u

/* Interrupt constants */
#if defined(IR_Actuator__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IR_Actuator_SetInterruptMode() function.
     *  @{
     */
        #define IR_Actuator_INTR_NONE      (uint16)(0x0000u)
        #define IR_Actuator_INTR_RISING    (uint16)(0x0001u)
        #define IR_Actuator_INTR_FALLING   (uint16)(0x0002u)
        #define IR_Actuator_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IR_Actuator_INTR_MASK      (0x01u) 
#endif /* (IR_Actuator__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IR_Actuator_PS                     (* (reg8 *) IR_Actuator__PS)
/* Data Register */
#define IR_Actuator_DR                     (* (reg8 *) IR_Actuator__DR)
/* Port Number */
#define IR_Actuator_PRT_NUM                (* (reg8 *) IR_Actuator__PRT) 
/* Connect to Analog Globals */                                                  
#define IR_Actuator_AG                     (* (reg8 *) IR_Actuator__AG)                       
/* Analog MUX bux enable */
#define IR_Actuator_AMUX                   (* (reg8 *) IR_Actuator__AMUX) 
/* Bidirectional Enable */                                                        
#define IR_Actuator_BIE                    (* (reg8 *) IR_Actuator__BIE)
/* Bit-mask for Aliased Register Access */
#define IR_Actuator_BIT_MASK               (* (reg8 *) IR_Actuator__BIT_MASK)
/* Bypass Enable */
#define IR_Actuator_BYP                    (* (reg8 *) IR_Actuator__BYP)
/* Port wide control signals */                                                   
#define IR_Actuator_CTL                    (* (reg8 *) IR_Actuator__CTL)
/* Drive Modes */
#define IR_Actuator_DM0                    (* (reg8 *) IR_Actuator__DM0) 
#define IR_Actuator_DM1                    (* (reg8 *) IR_Actuator__DM1)
#define IR_Actuator_DM2                    (* (reg8 *) IR_Actuator__DM2) 
/* Input Buffer Disable Override */
#define IR_Actuator_INP_DIS                (* (reg8 *) IR_Actuator__INP_DIS)
/* LCD Common or Segment Drive */
#define IR_Actuator_LCD_COM_SEG            (* (reg8 *) IR_Actuator__LCD_COM_SEG)
/* Enable Segment LCD */
#define IR_Actuator_LCD_EN                 (* (reg8 *) IR_Actuator__LCD_EN)
/* Slew Rate Control */
#define IR_Actuator_SLW                    (* (reg8 *) IR_Actuator__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IR_Actuator_PRTDSI__CAPS_SEL       (* (reg8 *) IR_Actuator__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IR_Actuator_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IR_Actuator__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IR_Actuator_PRTDSI__OE_SEL0        (* (reg8 *) IR_Actuator__PRTDSI__OE_SEL0) 
#define IR_Actuator_PRTDSI__OE_SEL1        (* (reg8 *) IR_Actuator__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IR_Actuator_PRTDSI__OUT_SEL0       (* (reg8 *) IR_Actuator__PRTDSI__OUT_SEL0) 
#define IR_Actuator_PRTDSI__OUT_SEL1       (* (reg8 *) IR_Actuator__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IR_Actuator_PRTDSI__SYNC_OUT       (* (reg8 *) IR_Actuator__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IR_Actuator__SIO_CFG)
    #define IR_Actuator_SIO_HYST_EN        (* (reg8 *) IR_Actuator__SIO_HYST_EN)
    #define IR_Actuator_SIO_REG_HIFREQ     (* (reg8 *) IR_Actuator__SIO_REG_HIFREQ)
    #define IR_Actuator_SIO_CFG            (* (reg8 *) IR_Actuator__SIO_CFG)
    #define IR_Actuator_SIO_DIFF           (* (reg8 *) IR_Actuator__SIO_DIFF)
#endif /* (IR_Actuator__SIO_CFG) */

/* Interrupt Registers */
#if defined(IR_Actuator__INTSTAT)
    #define IR_Actuator_INTSTAT            (* (reg8 *) IR_Actuator__INTSTAT)
    #define IR_Actuator_SNAP               (* (reg8 *) IR_Actuator__SNAP)
    
	#define IR_Actuator_0_INTTYPE_REG 		(* (reg8 *) IR_Actuator__0__INTTYPE)
#endif /* (IR_Actuator__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IR_Actuator_H */


/* [] END OF FILE */
