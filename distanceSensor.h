#ifndef INC_03_SE2_ROBOT_DISTANCESENSOR_H
#define INC_03_SE2_ROBOT_DISTANCESENSOR_H

#include "sensor.h"
#include <iostream>

using namespace std;

class DistanceSensor: public Sensor{
public:
    //default constructor

    //destructor:
    virtual ~DistanceSensor(){
        cout << "destructor Distance Sensor" << endl;
    };

    //funktionen:
    virtual int checkSensor() override;
};

#endif //INC_03_SE2_ROBOT_DISTANCESENSOR_H
