#include "cliffSensor.h"
#include <cstdlib>
#include "exceptions.h"

int CliffSensor::checkSensor() {
    int x = 0, y = 100;
    int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y

    if(rand_num < 5){
        throw InternalErrorException();
    }else if(rand_num < 10){
        throw CriticalDangerException();
    }else{
        int a = 0, b = 9;
        int danger = rand()%((b+1)-a) + a; //Zufallszahl zwischen a und b
        cout << "Gefahrenlevel im Cliffsensor: " << danger << endl;
        return danger;
    }
}



