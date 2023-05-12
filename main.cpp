#include <iostream>
#include "motor.h"

int main() {
    Motor mymotor(4);
    cout << "Speed1 Motor: " << mymotor.getSpeed() << endl;
    mymotor.setSpeed(10);
    cout << "Speed2 Motor: " << mymotor.getSpeed() << endl;

    return 0;
}
