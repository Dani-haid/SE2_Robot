#ifndef INC_03_SE2_ROBOT_EXCEPTIONS_H
#define INC_03_SE2_ROBOT_EXCEPTIONS_H

#include <stdexcept>
using namespace std;

//Übergeordnete Exception Klasse um benutzerdefinierte Fehlermeldungen auszugeben
class RobotException: public runtime_error{
public:
    using runtime_error::runtime_error;
};

class CriticalDangerException:public RobotException{
public:
    CriticalDangerException(): RobotException("critical situation - robot is going to crash!"){};
};

class InternalErrorException:public RobotException{
public:
    InternalErrorException(): RobotException("Sensor Problem!"){};
};
#endif //INC_03_SE2_ROBOT_EXCEPTIONS_H
