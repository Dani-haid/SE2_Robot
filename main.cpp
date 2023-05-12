#include <iostream>
#include "motor.h"
#include "distanceSensor.h"
#include "sensor.h"
#include <ctime>
#include "exceptions.h"
#include "robot.h"
#include "cameraSensor.h"

int main() {
    srand(time(nullptr));//Damit random Number immer unterschiedlich ist --> in main (braucht <ctime>)

    Robot myrobot(new Motor(4));

    myrobot.addSensor(new DistanceSensor);
    myrobot.addSensor(new CameraSensor);

    myrobot.eventLoop(3);


    /*
    try {
        DistanceSensor distance;
        int danger = distance.checkSensor();
        cout << "Danger Distance: " << danger << endl;

        DistanceSensor camera;
        int danger2 = camera.checkSensor();
        cout << "Danger Camera: " << danger2 << endl;

        DistanceSensor cliff;
        int danger3 = cliff.checkSensor();
        cout << "Danger Cliff: " << danger3 << endl;
    }
    catch (InternalErrorException& e){
        cout << e.what() << endl;
    }
    catch(CriticalDangerException& e){
        cout << e.what() << endl;
    }*/


    return 0;
}
