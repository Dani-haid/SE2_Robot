#ifndef INC_03_SE2_ROBOT_SENSOR_H
#define INC_03_SE2_ROBOT_SENSOR_H

class Sensor{
public:
    //default constructor

    //destructor:
    virtual ~Sensor(){};

    //funktionen:
    virtual int checkSensor() = 0;
};

#endif //INC_03_SE2_ROBOT_SENSOR_H
