// ================================
// Sorting_Controller.c
// * Implemented on PSoC LP5, to control all hardware pressent 
//      on the SortoMatic belt. Responsible for sorting packages
//      and notifying the Database
// Created by: GustavNK, rasmoller & Christian-Bach-johansen
// GitHub: https://github.com/rasmoller/PRJ3-Group-13/tree/master/Code/PRJ3-FULLv0.3
// ================================
// Revisions log:
// 20201009: Created and initial setup of TopDesign
// 20201120: Started implementation og color sensor
// 20201204: Redesign to better match PSoC C code
// 20201220: Added Queue funktions
// === TODO =======================
// * Interrupts may disrput the flow
// * 
// ================================

#include "project.h"
#include "Color_Sensor.h"
#include "Weight_Sensor.h"
#include "Actuator.h"
#include "Box.h"
#include "Database_Interface.h"
#include "Belt_Motor.h"
#include "Queue.h"
#include <stdlib.h>

const int MY_DEBUG = 0;

unsigned long msgCount = 0;

struct Queue* msgQueue;
struct Box box;

enum id
{
    MEASURE,
    ACTUATOR,
    RECEIVED_SETTINGS,
};

void handleMsg(unsigned long id);

CY_ISR_PROTO(isr_Measure_handler);
CY_ISR_PROTO(isr_Actuator_handler);
CY_ISR_PROTO(isr_rx_handler);

CY_ISR(isr_Measure_handler)
{
    msgCount++;
    enqueue(msgQueue, MEASURE);
}

CY_ISR(isr_Actuator_handler)
{
    msgCount++;
    enqueue(msgQueue, ACTUATOR);
}

CY_ISR(isr_rx_handler)
{
    msgCount++;
    enqueue(msgQueue, RECEIVED_SETTINGS);
}

void debug(char * buf){if(MY_DEBUG) RPI_UART_PutString(buf);}

int main(void)
{
    // Setup interrupts
    CyGlobalIntEnable;
    isr_Actuator_StartEx(isr_Actuator_handler);
    isr_Measure_StartEx(isr_Measure_handler);
    isr_rx_StartEx(isr_rx_handler);
    
    // Create C Queue
    msgQueue = createQueue(10);
    
    // Initiate internal hardware
    Color_Sensor_Start();
    Weight_Sensor_Start();
    Database_Interface_Start();
    
    for(;;)
    {        
        if(msgCount)    
        {
            msgCount--;
            int id = dequeue(msgQueue);
            handleMsg(id);
            debug("Interrupt handled");
        }
    }
}

// *********************
// * Takes an id and decides an action,
//      based on the received id
// *********************
void handleMsg(unsigned long id)
{
    switch(id)
    {
    // Get info on box and send to UART
    case MEASURE : 
    {
        struct Color c;
        Color_Sensor_Read_Color(&c); // This only returns the freq. But we need an RGB value
        int weight = Weight_Sensor_Read();
        int sort = 1; //decide to sort
        
        // Put color, weight & sort into Data struct 
        box.color[0] = c.red;
        box.color[1] = c.green;
        box.color[2] = c.blue;
        box.weight = weight;
        box.sort = sort;
        
        // DEBUG
        char buf[100];
        sprintf(buf, "Red %i, Green %i, Blue %i, weight %i\n", box.color[0], box.color[1], box.color[2], weight);
        debug(buf);
        
        Database_Interface_Send(&box);
        break;
    }
    case ACTUATOR : // Decides wether to sort
        if(box.sort)
        {
            // TODO Base extension on actuation length, not time
            Actuator_Extend();
            CyDelay(2000); 
            Actuator_Retract();
            CyDelay(2000);
        }
        break;
    case RECEIVED_SETTINGS : // Receive and set new settings from Data Server
    {
        // TODO: Setup new settings
        // * Receive Setings for Database_Interface
        // * Set new settings
        break;   
    }
    default : break;
    }
}
