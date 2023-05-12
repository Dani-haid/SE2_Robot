#ifndef INC_03_SE2_ROBOT_ROBOT_H
#define INC_03_SE2_ROBOT_ROBOT_H

#include <iostream>
#include <map>
#include <memory>
#include "sensor.h"

using namespace std;

//forward declaration
class Motor;

class Robot{
private:
    Motor* motor = nullptr;
    map<int, shared_ptr<Sensor>> sensors; //Sensorkonfiguration
    int sensorID = 0;

public:
    //constructor
    Robot(Motor* motor):motor(motor){};

    //destructor:
    ~Robot(){
        cout << "destructor Robot" << endl;
    };

    //funktionen:
    int addSensor(Sensor* sensor);
    Sensor* getSensor(int id);
    void deleteSensor(int id);
    void eventLoop(int iterations);
};

#endif //INC_03_SE2_ROBOT_ROBOT_H
