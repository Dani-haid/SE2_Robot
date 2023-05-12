#ifndef INC_03_SE2_ROBOT_CLIFFSENSOR_H
#define INC_03_SE2_ROBOT_CLIFFSENSOR_H

#include "sensor.h"
#include <iostream>

using namespace std;

class CliffSensor: public Sensor{
public:
    //default constructor

    //destructor:
    virtual ~CliffSensor(){
        cout << "destructor Cliff Sensor" << endl;
    };

    //funktionen:
    virtual int checkSensor() override;
};


#endif //INC_03_SE2_ROBOT_CLIFFSENSOR_H
