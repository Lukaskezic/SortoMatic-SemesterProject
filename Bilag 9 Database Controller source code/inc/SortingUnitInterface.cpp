#include "SortingUnitInterface.hpp"
#include <iostream>
#include <sstream>
#include "Box.h"

UartInterface::UartInterface(int setupFlags) 
    : setupFlags_(setupFlags)
    {
    fd_ = open(port_, setupFlags_);
    if (fd_ == -1)
    {
        perror("UARTDriver init: Unable to open serial connection on /dev/ttyf1");
    }
    else
    {
        fcntl(fd_, F_SETFL, 0);
    }
}

UartInterface::~UartInterface()
{
    close(fd_);
}

//****************************
// Use a char to set bits from enum settings 
// Send the char and a \0
//********************************
int UARTDriver::tx(char setting)
{
    char msgBuf[2];
    msgBuf[0] = setting;
    msgBuf[1] = '\0';

    int len = 2;
    int err = write(fd_, msgBuf, len);
    if(err < 0)
        std::cout << "UARTDriver::tx: unable to send" << std::endl;

    return 0;
}

//****************************
// First create Package obj to store received info
// Receives the expected Package and af \0
//*****************************
int UartInterface::rx(Box &package)
{
    // For non-blocking behavior. See ref1
    // fcntl(fd, F_SETFL, FNDELAY);

    // Get msg from UART
    const int len = 100;
    char msgBuffer[len];
    
    int len = read(fd_, msgBuffer, len);

    if( len <= 0) // Unable to read
    {
        std::cout << ("UARTDriver.rx: unable to read") << std::endl;
        return -1;
    }  

    // Send to user
    stringToPackage(package, msgBuffer);
    
    return len;
}

//***********************
// Converts received msg to a struct Package
//*************************
void UartInterface::stringToPackage(Box& package, char* translate)
{
    std::stringstream ss(translate);
    ss >> pkg.color[0] >> pkg.color[1] >> pkg.color[2] >> pkg.weight >> pkg.sort;
}