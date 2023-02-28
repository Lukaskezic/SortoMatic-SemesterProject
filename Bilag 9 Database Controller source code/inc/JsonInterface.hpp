#pragma once
#include <string>
#include "Box.h"

class JsonInterface
{
public:
    JsonInterface();
    ~JsonInterface();
    int reader(std::string fileName, std::string settingOption);
    void writer(std::string fileName, Box data);
};