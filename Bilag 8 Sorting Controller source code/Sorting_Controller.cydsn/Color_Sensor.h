// Parts of this design was inspired by a solution from diluc_3555836 
// Last visited 2020/12/02
// Original post: https://community.cypress.com/thread/43433?start=0

#include "project.h"
#include <stdio.h>

uint16 freq = 0;
uint8 freqReady = 0;
char buf[256];

struct ColorFreq{
    uint16 red;
    uint16 green;
    uint16 blue;
}sensorColor;

struct Color{
    uint8 red;
    uint8 green;
    uint8 blue;
};

typedef enum
{
    RED = 0b00,
    BLUE = 0b01,
    CLEAR = 0b10,
    GREEN = 0b11
} colorConst;

typedef enum
{
    POWER_OFF = 0b00,
    TWO = 0b01,
    TWENTY = 0b10,
    ONEHUNDRED = 0b11
} freqScale;

CY_ISR_PROTO(freq_INT);

CY_ISR(freq_INT)
{
    Color_Counter_Stop();
    freq = Color_Counter_ReadCounter();
    isr_Color_ClearPending();
    Color_Reset_Write(1);
    freqReady = 1;
}

// ***************************
// * Initiat the ISR and set settings pins
//      of the color sensor
// ****************************
void Color_Sensor_Start()
{
    isr_Color_StartEx(freq_INT);
    Color_Pin_Freq_Select_Write(TWENTY);
}

// **********************
// * Returns the current freq of
//      the chosen color sensor
// **********************
uint16 Color_Sensor_Read_Freq()
{
    // Reset sensor
    Color_Reset_Write(1);
    CyDelay(1);
    Color_Reset_Write(0);
    
    Color_Pin_LED_Write(1);
    Color_Counter_Start();
    Color_PWM_Start();
    
    while(freqReady != 1){}
    Color_Pin_LED_Write(0);
    freqReady = 0;
    return(freq);
}

// *****************************
// * Makes cf into the current color frequency
//      of diodes
// *******************************
void Color_Sensor_Read_All_Freq(struct ColorFreq* cf)
{
    Color_Pin_Color_Select_Write(RED);
    cf->red = Color_Sensor_Read_Freq();
    
    Color_Pin_Color_Select_Write(GREEN);
    cf->green = Color_Sensor_Read_Freq();
    
    Color_Pin_Color_Select_Write(BLUE);
    cf->blue = Color_Sensor_Read_Freq();
}

// *************************
// * Makes c into the primary color 
//      from the box
// TODO: Be able to recognize more colors
// *************************
void Color_Sensor_Read_Color(struct Color* c)
{
    struct ColorFreq cf;
    
    Color_Sensor_Read_All_Freq(&cf);
    // Decide primary color
    if(cf.blue > cf.green && cf.blue > cf.red)
    {
        c->red = 0; 
        c->green = 0;
        c->blue = 255;
    }
    else if(cf.green> cf.blue && cf.green > cf.red)
    {
        c->red = 0; 
        c->green = 255;
        c->blue = 0;
    }
    else if(cf.red> cf.blue && cf.red > cf.green)
    {
        c->red = 255; 
        c->green = 0;
        c->blue = 0;
    }
}

// ***************
// DEBUG functions
// ***************
/*
void sendRedToConsol()
{
    Color_Pin_Color_Ctrl_Write(RED);
    sensorColor.red = getFreq();
    sprintf(buf,"Red frequency: %5d Hz",sensorColor.red);
    RPI_UART_PutString(buf);
     
    CyDelay(100);
}

void sendGreenToConsol()
{
    Color_Pin_Color_Ctrl_Write(GREEN);
    sensorColor.red = getFreq();
    sprintf(buf,"Green frequency: %5d Hz",sensorColor.red);
    RPI_UART_PutString(buf);
     
    CyDelay(100);  
}

void sendBlueToConsol()
{
    Color_Pin_Color_Ctrl_Write(BLUE);
    sensorColor.red = getFreq();
    sprintf(buf,"Blue frequency: %5d Hz",sensorColor.red);
    RPI_UART_PutString(buf);
     
    CyDelay(100);   
}
*/