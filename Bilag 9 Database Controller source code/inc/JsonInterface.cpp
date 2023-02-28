#include "JsonInterface.hpp"
#include "ArduinoJson-v6.17.2.h"
#include <fstream>
#include <stdio.h>
#include <iostream>

JsonInterface::JsonInterface(){}

JsonInterface::~JsonInterface(){}

//Takes the name of a json file, and data in the form of a struct. Can only write struc of type Data, has to be modified if further data needs to be added
void JsonInterface::writer(std::string fileName, Box data)
{
    DynamicJsonDocument values(8000);

    std::fstream file_id;
    file_id.open(fileName, std::fstream::in| std::fstream::out /*| std::fstream::ate*/);

    if (!file_id.is_open())
        std::cout << "File not opened correctly" << std::endl;    
    
    std::cout << "JSON: writing to " << std::endl;
    
    deserializeJson(values, file_id);
//    std::cout << values << std::endl;


//    std::cout << values["data"].size() << std::endl;

    file_id.close();

    file_id.open(fileName, std::fstream::in| std::fstream::out | std::ofstream::trunc);

    data.id = values["data"].size() + 1;
    char buf[256];
    sprintf(buf, "box %i", data.id);

    values["data"][buf][0]["id"] = (data.id);
    values["data"][buf][0]["color"][0]["r"] = (data.color[0]);
    values["data"][buf][0]["color"][0]["g"] = (data.color[1]);
    values["data"][buf][0]["color"][0]["b"] = (data.color[2]);
    values["data"][buf][0]["weight"] = (data.weight);
    values["data"][buf][0]["sort"] = (data.sort);

    int err = serializeJsonPretty(values, file_id);
//    std::cout << values << std::endl;
    std::cout << "JSON: Lines written " << err << std::endl;
    file_id.close();
}


//Takes the name of a json file, and the name of the option variable it should return
int JsonInterface::reader(std::string fileName, std::string settingOption)
{
    std::fstream file_id;
    file_id.open(fileName);

    if (!file_id.is_open())
        std::cout << "File not opened correctly" << std::endl;    


    DynamicJsonDocument values(1024);
    deserializeJson(values, file_id);

    return values["settings"][0][settingOption].as<int>();
}