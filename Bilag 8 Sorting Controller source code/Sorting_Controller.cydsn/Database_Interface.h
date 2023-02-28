#include "Box.h"
#include "stdio.h"
#include "project.h"


void Database_Interface_Start()
{
    RPI_UART_Start();
}

void Database_Interface_Send(struct Box* d)
{
    char buf[100] = {'\0'};
    
    int len = sprintf(buf, "%i %i %i %i %i", d->color[0], d->color[1], d->color[2], d->weight, d->sort);
    buf[len] = '\n';
    
    RPI_UART_PutString(buf);
}