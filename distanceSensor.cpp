#include "distanceSensor.h"
#include <cstdlib>
#include "exceptions.h"

int DistanceSensor::checkSensor() {
    int x = 0, y = 100;
    int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y

    if(rand_num < 5){
        throw InternalErrorException();
    }else if(rand_num < 15){
        throw CriticalDangerException();
    }else{
        int a = 0, b = 6;
        int danger = rand()%((b+1)-a) + a; //Zufallszahl zwischen a und b
        return danger;
    }
}

