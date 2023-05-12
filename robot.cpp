#include "robot.h"
#include "sensor.h"

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
    int count = 0;
    while(iterations >= 0){

        for (auto it = sensors.begin(); it != sensors.end(); it++)
        {
            std::cout << it->first << " = " << it->second << "; " << endl;
            //sensors.checkSensor();
        }


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

