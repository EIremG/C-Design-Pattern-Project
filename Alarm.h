#ifndef ALARM_H
#define ALARM_H

#include <iostream>
#include <string>
#include <chrono>

enum DeviceStatus {
    ACTIVE,
    INACTIVE,
    FAILED
};

class Alarm {
private:
    static Alarm* instance;
    Alarm();

    bool active;
    bool acknowledged;
    std::chrono::steady_clock::time_point startTime;
    bool fireDeptCalled;

public:
    static Alarm* getInstance();
    void trigger(const std::string& source);
    void acknowledge();
    void reset();
    void update(); 
    bool isActive() const { return active; }
};

#endif