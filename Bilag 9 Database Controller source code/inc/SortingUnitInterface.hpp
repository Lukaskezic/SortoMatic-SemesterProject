#pragma once
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string>

// ref0 Setup for Serial0 / ttyS0: https://redmine.ase.au.dk/devs/projects/raspberry-zero/wiki/TtyS0
// ref1 Info on serial writing: https://www.cmrr.umn.edu/~strupp/serial.html

//======TODO=======
//
//=================

struct Box;

class UartInterface {
public:
    UartInterface(int setup = O_RDWR | O_NOCTTY | O_NDELAY);
    ~UartInterface();
    int tx(char setting);
    int rx(Box& package);
private:
    const char* port_ = "/dev/serial0";
    int fd_;
    int setupFlags_;

    void stringToPackage(Box& pkg, char* tranlste);
};