#include <iostream>
#include "motor.h"
#include "distanceSensor.h"
#include <ctime>

int main() {
    srand(time(nullptr));//Damit random Number immer unterschiedlich ist --> in main (braucht <ctime>)


    Motor mymotor(4);
    cout << "Speed1 Motor: " << mymotor.getSpeed() << endl;
    mymotor.setSpeed(10);
    cout << "Speed2 Motor: " << mymotor.getSpeed() << endl;

    DistanceSensor distance;
    int danger = distance.checkSensor();
    cout << "Danger Distance: " << danger << endl;

    DistanceSensor camera;
    int danger2 = camera.checkSensor();
    cout << "Danger Camera: " << danger2 << endl;

    DistanceSensor cliff;
    int danger3 = cliff.checkSensor();
    cout << "Danger Cliff: " << danger3 << endl;


    return 0;
}
