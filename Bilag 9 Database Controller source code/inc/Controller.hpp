#pragma once
#include <string>
#include <iostream>
#include "JsonCom.hpp"
#include "SortinUnitInterface.hpp"

class Controller
{
public:
    Controller();
    ~Controller();
    void run();
private:
    JsonCom json_;
    SortinUnitInterface uart_;
    bool run_;
    std::string dataFile_ = "/www/pages/database.json";
};

