#ifndef INC_03_SE2_ROBOT_CAMERASENSOR_H
#define INC_03_SE2_ROBOT_CAMERASENSOR_H


#include "sensor.h"
#include <iostream>

using namespace std;

class CameraSensor: public Sensor{
public:
    //default constructor

    //destructor:
    virtual ~CameraSensor(){
        cout << "destructor Camera Sensor" << endl;
    };

    //funktionen:
    virtual int checkSensor() override;
};


#endif //INC_03_SE2_ROBOT_CAMERASENSOR_H
