/*******************************************************************************
* File Name: RPI_UART_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "RPI_UART.h"


/***************************************
* Local data allocation
***************************************/

static RPI_UART_BACKUP_STRUCT  RPI_UART_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: RPI_UART_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component nonretention control register.
*  Does not save the FIFO which is a set of nonretention registers.
*  This function is called by the RPI_UART_Sleep() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  RPI_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RPI_UART_SaveConfig(void)
{
    #if(RPI_UART_CONTROL_REG_REMOVED == 0u)
        RPI_UART_backup.cr = RPI_UART_CONTROL_REG;
    #endif /* End RPI_UART_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: RPI_UART_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the nonretention control register except FIFO.
*  Does not restore the FIFO which is a set of nonretention registers.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  RPI_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
* Notes:
*  If this function is called without calling RPI_UART_SaveConfig() 
*  first, the data loaded may be incorrect.
*
*******************************************************************************/
void RPI_UART_RestoreConfig(void)
{
    #if(RPI_UART_CONTROL_REG_REMOVED == 0u)
        RPI_UART_CONTROL_REG = RPI_UART_backup.cr;
    #endif /* End RPI_UART_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: RPI_UART_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. 
*  The RPI_UART_Sleep() API saves the current component state. Then it
*  calls the RPI_UART_Stop() function and calls 
*  RPI_UART_SaveConfig() to save the hardware configuration.
*  Call the RPI_UART_Sleep() function before calling the CyPmSleep() 
*  or the CyPmHibernate() function. 
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  RPI_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RPI_UART_Sleep(void)
{
    #if(RPI_UART_RX_ENABLED || RPI_UART_HD_ENABLED)
        if((RPI_UART_RXSTATUS_ACTL_REG  & RPI_UART_INT_ENABLE) != 0u)
        {
            RPI_UART_backup.enableState = 1u;
        }
        else
        {
            RPI_UART_backup.enableState = 0u;
        }
    #else
        if((RPI_UART_TXSTATUS_ACTL_REG  & RPI_UART_INT_ENABLE) !=0u)
        {
            RPI_UART_backup.enableState = 1u;
        }
        else
        {
            RPI_UART_backup.enableState = 0u;
        }
    #endif /* End RPI_UART_RX_ENABLED || RPI_UART_HD_ENABLED*/

    RPI_UART_Stop();
    RPI_UART_SaveConfig();
}


/*******************************************************************************
* Function Name: RPI_UART_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when 
*  RPI_UART_Sleep() was called. The RPI_UART_Wakeup() function
*  calls the RPI_UART_RestoreConfig() function to restore the 
*  configuration. If the component was enabled before the 
*  RPI_UART_Sleep() function was called, the RPI_UART_Wakeup()
*  function will also re-enable the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  RPI_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RPI_UART_Wakeup(void)
{
    RPI_UART_RestoreConfig();
    #if( (RPI_UART_RX_ENABLED) || (RPI_UART_HD_ENABLED) )
        RPI_UART_ClearRxBuffer();
    #endif /* End (RPI_UART_RX_ENABLED) || (RPI_UART_HD_ENABLED) */
    #if(RPI_UART_TX_ENABLED || RPI_UART_HD_ENABLED)
        RPI_UART_ClearTxBuffer();
    #endif /* End RPI_UART_TX_ENABLED || RPI_UART_HD_ENABLED */

    if(RPI_UART_backup.enableState != 0u)
    {
        RPI_UART_Enable();
    }
}


/* [] END OF FILE */
