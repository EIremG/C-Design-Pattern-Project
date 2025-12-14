#pragma once
#include "Device.h"

class Alarm : public Device {
private:
    static Alarm* instance;
    bool isAlarming;
    std::string alarmReason;

    Alarm();

public:
    Alarm(const Alarm&) = delete;
    void operator=(const Alarm&) = delete;

    static Alarm* getInstance();

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override;

    void trigger(const std::string& reason);
    void silence();
};