#include "cameraSensor.h"
#include <cstdlib>
#include "exceptions.h"

int CameraSensor::checkSensor() {
    int x = 0, y = 100;
    int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y

    if(rand_num < 15){
        throw InternalErrorException();
    }else if(rand_num < 20){
        throw CriticalDangerException();
    }else{
        int a = 0, b = 4;
        int danger = rand()%((b+1)-a) + a; //Zufallszahl zwischen a und b
        cout << "Gefahrenlevel im Camerasensor: " << danger << endl;
        return danger;
    }
}


