#ifndef INC_03_SE2_ROBOT_MOTOR_H
#define INC_03_SE2_ROBOT_MOTOR_H

#include <iostream>
using namespace std;

class Motor{
private:
    int speed;

public:
    //constructor
    Motor(int speed) : speed(speed){};

    //destructor
    ~Motor(){
        cout << "destructor Motor" << endl;
    }

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int speed) {
        if(speed > 0 && speed <= 10){
            this->speed = speed;
        }else{
            this->speed = 0;
        }
    }

    void emergencyBrake(){
        cout << "Notstop durchgeführt!" << endl;
        this->speed = 0;
    };
};

#endif //INC_03_SE2_ROBOT_MOTOR_H
