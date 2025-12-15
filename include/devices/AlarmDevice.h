#pragma once
#include "devices/HomeDevice.h"

class AlarmDevice : public HomeDevice {
private:
    static AlarmDevice* instance;
    bool isAlarming;
    std::string alarmReason;

    AlarmDevice();

public:
    AlarmDevice(const AlarmDevice&) = delete;
    void operator=(const AlarmDevice&) = delete;

    static AlarmDevice* getInstance();

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    HomeDevice* clone() const override;

    void trigger(const std::string& reason);
    void silence();
};