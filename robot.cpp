#include "robot.h"
#include "sensor.h"
#include "motor.h"
#include "exceptions.h"

int Robot::addSensor(Sensor *sensor) {
    int id = sensorID++;
    sensors.insert({id, shared_ptr<Sensor>(sensor)}); //in map einfügen
    return id;
}

Sensor *Robot::getSensor(int id) {
    //Gibt den Sensor mit der angegebenen ID zurück.
    if(sensors.find(id) != sensors.end()){
        return sensors[id].get();
    }else{
        //exception tbd
        return nullptr;
    }
}

void Robot::deleteSensor(int id) {
    if(sensors.find(id) != sensors.end()){
        sensors.erase(id);
    }else{
        //exception tbd
    }
}

void Robot::eventLoop(int iterations) {
    if(sosCount != 0){
        sosCount --;
        cout << "sosCount: " << sosCount << endl;
        return;
    }
    int count = 0;

    while(iterations >= 0){
        int maxDanger = 0;
        int newSpeed;
        if(driveOn){
            for (auto it = sensors.begin(); it != sensors.end(); it++){
                try {
                    int sensorDanger = it->second->checkSensor();
                    if (sensorDanger > maxDanger) {
                        maxDanger = sensorDanger;
                    }
                }
                catch(CriticalDangerException& e){
                    cout << e.what() << endl;
                    motor->emergencyBrake();
                    sosCount = 5;
                    driveOn = false;
                    //soll ein Notstopp derMotoren eingeleitet werden
                    break;
                }
                catch(InternalErrorException& e){
                    cout << e.what() << endl;
                    motor->setSpeed(1);
                    sosCount = 5;
                    cout << "Motor auf niedrigste Stufe gestellt!" << endl;
                    //dann soll ausSicherheitsgründen auf die niedrigste Geschwindigkeit geschalten werden
                }
            }
        }

        if(maxDanger == 0){
            newSpeed = 10;
        }else if(maxDanger < 5){
            newSpeed = 8;
        }else if(maxDanger < 9){
            newSpeed = 3;
        }else{
            newSpeed = 1;
        }
        motor->setSpeed(newSpeed);

        cout << "maxDanger beträgt: " << maxDanger << " newSpeed beträgt: " << newSpeed << endl;
        cout << "Neue Motorspeed beträgt: " << motor->getSpeed() << endl;

        cout << "----" << endl;







        if(iterations == 1){
            break;
        }else{
            iterations --;
        }
        //Sicherheitsabbruch while coding
        if(count >= 10){
            break;
        }
        count ++;
    }
}

