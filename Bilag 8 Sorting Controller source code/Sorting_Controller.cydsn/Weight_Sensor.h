/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"
#include <stdio.h>

const uint16 linearity; // TODO find linearity 
const float offset_err = 0;
const float gram_per_adc = 1;

// ********************
// * Initiates the ADC for the 
//      weight cell
// ********************
void Weight_Sensor_Start()
{
    Weight_ADC_Start();
    Weight_ADC_StartConvert();
}

// ******************
// * Utility function
// * Converts adc value to weight in grams
// ******************
float Weight_Sensor_ADC_To_Grams(uint16_t adc)
{
    //Remember this should be calibrated!!!!!!!
    float corrected_output = (adc - offset_err)/gram_per_adc;
    corrected_output = (corrected_output >= 0) ? corrected_output : 0;
    return (corrected_output) - 3;
}

// ******************
// * Returns the weight currently 
//      on the loadcell in grams
// ******************
uint16 Weight_Sensor_Read_Grams()
{
    uint16_t result = 0;
    
    while(!Weight_ADC_IsEndConversion(Weight_ADC_WAIT_FOR_RESULT)) {}
    
    result = Weight_ADC_GetResult16();
    
    return Weight_Sensor_ADC_To_Grams(result);
}

// ******************
// * Returns the final weight in grams
// * Takes the average of 10 readings from the scale
// ******************
uint16 Weight_Sensor_Read()
{
    float sum = 0;
    for(int i = 0; i < 10; i++)
        sum += Weight_Sensor_Read_Grams();
        
    uint16 result = sum/10;
        
    return result;
}