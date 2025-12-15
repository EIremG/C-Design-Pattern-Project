#ifndef ALARM_H
#define ALARM_H

#include <iostream>
#include <string>

class Alarm {
private:
    static Alarm* instance;
    bool active;

    Alarm() : active(false) {}

public:
    static Alarm* getInstance();

    void trigger(const std::string& sourceDevice);
    void update();
    void silence();

    bool isActive() const { return active; }
};

#endif
