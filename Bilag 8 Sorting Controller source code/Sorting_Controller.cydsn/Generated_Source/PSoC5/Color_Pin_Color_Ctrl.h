/*******************************************************************************
* File Name: Color_Pin_Color_Ctrl.h  
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

#if !defined(CY_PINS_Color_Pin_Color_Ctrl_H) /* Pins Color_Pin_Color_Ctrl_H */
#define CY_PINS_Color_Pin_Color_Ctrl_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Color_Pin_Color_Ctrl_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Color_Pin_Color_Ctrl__PORT == 15 && ((Color_Pin_Color_Ctrl__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Color_Pin_Color_Ctrl_Write(uint8 value);
void    Color_Pin_Color_Ctrl_SetDriveMode(uint8 mode);
uint8   Color_Pin_Color_Ctrl_ReadDataReg(void);
uint8   Color_Pin_Color_Ctrl_Read(void);
void    Color_Pin_Color_Ctrl_SetInterruptMode(uint16 position, uint16 mode);
uint8   Color_Pin_Color_Ctrl_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Color_Pin_Color_Ctrl_SetDriveMode() function.
     *  @{
     */
        #define Color_Pin_Color_Ctrl_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Color_Pin_Color_Ctrl_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Color_Pin_Color_Ctrl_DM_RES_UP          PIN_DM_RES_UP
        #define Color_Pin_Color_Ctrl_DM_RES_DWN         PIN_DM_RES_DWN
        #define Color_Pin_Color_Ctrl_DM_OD_LO           PIN_DM_OD_LO
        #define Color_Pin_Color_Ctrl_DM_OD_HI           PIN_DM_OD_HI
        #define Color_Pin_Color_Ctrl_DM_STRONG          PIN_DM_STRONG
        #define Color_Pin_Color_Ctrl_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Color_Pin_Color_Ctrl_MASK               Color_Pin_Color_Ctrl__MASK
#define Color_Pin_Color_Ctrl_SHIFT              Color_Pin_Color_Ctrl__SHIFT
#define Color_Pin_Color_Ctrl_WIDTH              2u

/* Interrupt constants */
#if defined(Color_Pin_Color_Ctrl__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Color_Pin_Color_Ctrl_SetInterruptMode() function.
     *  @{
     */
        #define Color_Pin_Color_Ctrl_INTR_NONE      (uint16)(0x0000u)
        #define Color_Pin_Color_Ctrl_INTR_RISING    (uint16)(0x0001u)
        #define Color_Pin_Color_Ctrl_INTR_FALLING   (uint16)(0x0002u)
        #define Color_Pin_Color_Ctrl_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Color_Pin_Color_Ctrl_INTR_MASK      (0x01u) 
#endif /* (Color_Pin_Color_Ctrl__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Color_Pin_Color_Ctrl_PS                     (* (reg8 *) Color_Pin_Color_Ctrl__PS)
/* Data Register */
#define Color_Pin_Color_Ctrl_DR                     (* (reg8 *) Color_Pin_Color_Ctrl__DR)
/* Port Number */
#define Color_Pin_Color_Ctrl_PRT_NUM                (* (reg8 *) Color_Pin_Color_Ctrl__PRT) 
/* Connect to Analog Globals */                                                  
#define Color_Pin_Color_Ctrl_AG                     (* (reg8 *) Color_Pin_Color_Ctrl__AG)                       
/* Analog MUX bux enable */
#define Color_Pin_Color_Ctrl_AMUX                   (* (reg8 *) Color_Pin_Color_Ctrl__AMUX) 
/* Bidirectional Enable */                                                        
#define Color_Pin_Color_Ctrl_BIE                    (* (reg8 *) Color_Pin_Color_Ctrl__BIE)
/* Bit-mask for Aliased Register Access */
#define Color_Pin_Color_Ctrl_BIT_MASK               (* (reg8 *) Color_Pin_Color_Ctrl__BIT_MASK)
/* Bypass Enable */
#define Color_Pin_Color_Ctrl_BYP                    (* (reg8 *) Color_Pin_Color_Ctrl__BYP)
/* Port wide control signals */                                                   
#define Color_Pin_Color_Ctrl_CTL                    (* (reg8 *) Color_Pin_Color_Ctrl__CTL)
/* Drive Modes */
#define Color_Pin_Color_Ctrl_DM0                    (* (reg8 *) Color_Pin_Color_Ctrl__DM0) 
#define Color_Pin_Color_Ctrl_DM1                    (* (reg8 *) Color_Pin_Color_Ctrl__DM1)
#define Color_Pin_Color_Ctrl_DM2                    (* (reg8 *) Color_Pin_Color_Ctrl__DM2) 
/* Input Buffer Disable Override */
#define Color_Pin_Color_Ctrl_INP_DIS                (* (reg8 *) Color_Pin_Color_Ctrl__INP_DIS)
/* LCD Common or Segment Drive */
#define Color_Pin_Color_Ctrl_LCD_COM_SEG            (* (reg8 *) Color_Pin_Color_Ctrl__LCD_COM_SEG)
/* Enable Segment LCD */
#define Color_Pin_Color_Ctrl_LCD_EN                 (* (reg8 *) Color_Pin_Color_Ctrl__LCD_EN)
/* Slew Rate Control */
#define Color_Pin_Color_Ctrl_SLW                    (* (reg8 *) Color_Pin_Color_Ctrl__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Color_Pin_Color_Ctrl_PRTDSI__CAPS_SEL       (* (reg8 *) Color_Pin_Color_Ctrl__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Color_Pin_Color_Ctrl_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Color_Pin_Color_Ctrl__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Color_Pin_Color_Ctrl_PRTDSI__OE_SEL0        (* (reg8 *) Color_Pin_Color_Ctrl__PRTDSI__OE_SEL0) 
#define Color_Pin_Color_Ctrl_PRTDSI__OE_SEL1        (* (reg8 *) Color_Pin_Color_Ctrl__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Color_Pin_Color_Ctrl_PRTDSI__OUT_SEL0       (* (reg8 *) Color_Pin_Color_Ctrl__PRTDSI__OUT_SEL0) 
#define Color_Pin_Color_Ctrl_PRTDSI__OUT_SEL1       (* (reg8 *) Color_Pin_Color_Ctrl__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Color_Pin_Color_Ctrl_PRTDSI__SYNC_OUT       (* (reg8 *) Color_Pin_Color_Ctrl__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Color_Pin_Color_Ctrl__SIO_CFG)
    #define Color_Pin_Color_Ctrl_SIO_HYST_EN        (* (reg8 *) Color_Pin_Color_Ctrl__SIO_HYST_EN)
    #define Color_Pin_Color_Ctrl_SIO_REG_HIFREQ     (* (reg8 *) Color_Pin_Color_Ctrl__SIO_REG_HIFREQ)
    #define Color_Pin_Color_Ctrl_SIO_CFG            (* (reg8 *) Color_Pin_Color_Ctrl__SIO_CFG)
    #define Color_Pin_Color_Ctrl_SIO_DIFF           (* (reg8 *) Color_Pin_Color_Ctrl__SIO_DIFF)
#endif /* (Color_Pin_Color_Ctrl__SIO_CFG) */

/* Interrupt Registers */
#if defined(Color_Pin_Color_Ctrl__INTSTAT)
    #define Color_Pin_Color_Ctrl_INTSTAT            (* (reg8 *) Color_Pin_Color_Ctrl__INTSTAT)
    #define Color_Pin_Color_Ctrl_SNAP               (* (reg8 *) Color_Pin_Color_Ctrl__SNAP)
    
	#define Color_Pin_Color_Ctrl_0_INTTYPE_REG 		(* (reg8 *) Color_Pin_Color_Ctrl__0__INTTYPE)
	#define Color_Pin_Color_Ctrl_1_INTTYPE_REG 		(* (reg8 *) Color_Pin_Color_Ctrl__1__INTTYPE)
#endif /* (Color_Pin_Color_Ctrl__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Color_Pin_Color_Ctrl_H */


/* [] END OF FILE */
