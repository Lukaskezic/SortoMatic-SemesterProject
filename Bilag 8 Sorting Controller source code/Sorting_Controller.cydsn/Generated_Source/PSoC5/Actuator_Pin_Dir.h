/*******************************************************************************
* File Name: Actuator_Pin_Dir.h  
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

#if !defined(CY_PINS_Actuator_Pin_Dir_H) /* Pins Actuator_Pin_Dir_H */
#define CY_PINS_Actuator_Pin_Dir_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Actuator_Pin_Dir_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Actuator_Pin_Dir__PORT == 15 && ((Actuator_Pin_Dir__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Actuator_Pin_Dir_Write(uint8 value);
void    Actuator_Pin_Dir_SetDriveMode(uint8 mode);
uint8   Actuator_Pin_Dir_ReadDataReg(void);
uint8   Actuator_Pin_Dir_Read(void);
void    Actuator_Pin_Dir_SetInterruptMode(uint16 position, uint16 mode);
uint8   Actuator_Pin_Dir_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Actuator_Pin_Dir_SetDriveMode() function.
     *  @{
     */
        #define Actuator_Pin_Dir_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Actuator_Pin_Dir_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Actuator_Pin_Dir_DM_RES_UP          PIN_DM_RES_UP
        #define Actuator_Pin_Dir_DM_RES_DWN         PIN_DM_RES_DWN
        #define Actuator_Pin_Dir_DM_OD_LO           PIN_DM_OD_LO
        #define Actuator_Pin_Dir_DM_OD_HI           PIN_DM_OD_HI
        #define Actuator_Pin_Dir_DM_STRONG          PIN_DM_STRONG
        #define Actuator_Pin_Dir_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Actuator_Pin_Dir_MASK               Actuator_Pin_Dir__MASK
#define Actuator_Pin_Dir_SHIFT              Actuator_Pin_Dir__SHIFT
#define Actuator_Pin_Dir_WIDTH              1u

/* Interrupt constants */
#if defined(Actuator_Pin_Dir__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Actuator_Pin_Dir_SetInterruptMode() function.
     *  @{
     */
        #define Actuator_Pin_Dir_INTR_NONE      (uint16)(0x0000u)
        #define Actuator_Pin_Dir_INTR_RISING    (uint16)(0x0001u)
        #define Actuator_Pin_Dir_INTR_FALLING   (uint16)(0x0002u)
        #define Actuator_Pin_Dir_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Actuator_Pin_Dir_INTR_MASK      (0x01u) 
#endif /* (Actuator_Pin_Dir__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Actuator_Pin_Dir_PS                     (* (reg8 *) Actuator_Pin_Dir__PS)
/* Data Register */
#define Actuator_Pin_Dir_DR                     (* (reg8 *) Actuator_Pin_Dir__DR)
/* Port Number */
#define Actuator_Pin_Dir_PRT_NUM                (* (reg8 *) Actuator_Pin_Dir__PRT) 
/* Connect to Analog Globals */                                                  
#define Actuator_Pin_Dir_AG                     (* (reg8 *) Actuator_Pin_Dir__AG)                       
/* Analog MUX bux enable */
#define Actuator_Pin_Dir_AMUX                   (* (reg8 *) Actuator_Pin_Dir__AMUX) 
/* Bidirectional Enable */                                                        
#define Actuator_Pin_Dir_BIE                    (* (reg8 *) Actuator_Pin_Dir__BIE)
/* Bit-mask for Aliased Register Access */
#define Actuator_Pin_Dir_BIT_MASK               (* (reg8 *) Actuator_Pin_Dir__BIT_MASK)
/* Bypass Enable */
#define Actuator_Pin_Dir_BYP                    (* (reg8 *) Actuator_Pin_Dir__BYP)
/* Port wide control signals */                                                   
#define Actuator_Pin_Dir_CTL                    (* (reg8 *) Actuator_Pin_Dir__CTL)
/* Drive Modes */
#define Actuator_Pin_Dir_DM0                    (* (reg8 *) Actuator_Pin_Dir__DM0) 
#define Actuator_Pin_Dir_DM1                    (* (reg8 *) Actuator_Pin_Dir__DM1)
#define Actuator_Pin_Dir_DM2                    (* (reg8 *) Actuator_Pin_Dir__DM2) 
/* Input Buffer Disable Override */
#define Actuator_Pin_Dir_INP_DIS                (* (reg8 *) Actuator_Pin_Dir__INP_DIS)
/* LCD Common or Segment Drive */
#define Actuator_Pin_Dir_LCD_COM_SEG            (* (reg8 *) Actuator_Pin_Dir__LCD_COM_SEG)
/* Enable Segment LCD */
#define Actuator_Pin_Dir_LCD_EN                 (* (reg8 *) Actuator_Pin_Dir__LCD_EN)
/* Slew Rate Control */
#define Actuator_Pin_Dir_SLW                    (* (reg8 *) Actuator_Pin_Dir__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Actuator_Pin_Dir_PRTDSI__CAPS_SEL       (* (reg8 *) Actuator_Pin_Dir__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Actuator_Pin_Dir_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Actuator_Pin_Dir__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Actuator_Pin_Dir_PRTDSI__OE_SEL0        (* (reg8 *) Actuator_Pin_Dir__PRTDSI__OE_SEL0) 
#define Actuator_Pin_Dir_PRTDSI__OE_SEL1        (* (reg8 *) Actuator_Pin_Dir__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Actuator_Pin_Dir_PRTDSI__OUT_SEL0       (* (reg8 *) Actuator_Pin_Dir__PRTDSI__OUT_SEL0) 
#define Actuator_Pin_Dir_PRTDSI__OUT_SEL1       (* (reg8 *) Actuator_Pin_Dir__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Actuator_Pin_Dir_PRTDSI__SYNC_OUT       (* (reg8 *) Actuator_Pin_Dir__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Actuator_Pin_Dir__SIO_CFG)
    #define Actuator_Pin_Dir_SIO_HYST_EN        (* (reg8 *) Actuator_Pin_Dir__SIO_HYST_EN)
    #define Actuator_Pin_Dir_SIO_REG_HIFREQ     (* (reg8 *) Actuator_Pin_Dir__SIO_REG_HIFREQ)
    #define Actuator_Pin_Dir_SIO_CFG            (* (reg8 *) Actuator_Pin_Dir__SIO_CFG)
    #define Actuator_Pin_Dir_SIO_DIFF           (* (reg8 *) Actuator_Pin_Dir__SIO_DIFF)
#endif /* (Actuator_Pin_Dir__SIO_CFG) */

/* Interrupt Registers */
#if defined(Actuator_Pin_Dir__INTSTAT)
    #define Actuator_Pin_Dir_INTSTAT            (* (reg8 *) Actuator_Pin_Dir__INTSTAT)
    #define Actuator_Pin_Dir_SNAP               (* (reg8 *) Actuator_Pin_Dir__SNAP)
    
	#define Actuator_Pin_Dir_0_INTTYPE_REG 		(* (reg8 *) Actuator_Pin_Dir__0__INTTYPE)
#endif /* (Actuator_Pin_Dir__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Actuator_Pin_Dir_H */


/* [] END OF FILE */
