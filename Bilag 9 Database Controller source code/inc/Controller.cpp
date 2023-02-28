#include "Controller.hpp"
#include "Box.h"

Controller::Controller() : 
    run_(true)
{
std::cerr << "Controller class init\n";
}

Controller::~Controller()
{
}

// *****************
// * Initial program to run the uart and database
//*******************

void Controller::run()
{
    int count = 1;
    while(run_)
    {
        Box package;
std::cout << "Controller: Data obj made " << count++ << "\n";
        uart_.rx(package);
std::cout << "Controller: Pkg received from UART, content is: \n"
    << "Color: " << d.color[0] << ", " << d.color[1] << ", " << d.color[2] << std::endl
    << "Weight: " << d.weight << std::endl 
    << "Sorted: " << d.sort << std::endl;
        pacakge.id = count;
        json_.json_writer(dataFile_, package);
//td::cerr << "Controller: Written to JSON file" << std::endl;
    }
}