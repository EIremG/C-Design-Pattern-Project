#ifndef DEVICEFAILUREEVENT_H
#define DEVICEFAILUREEVENT_H

#include "Event.h"
#include <string>

// LLR29: DeviceFailureEvent sinifi
class DeviceFailureEvent : public Event {
private:
    int deviceId;
    std::string failureReason;

public:
    DeviceFailureEvent();
    DeviceFailureEvent(int devId, const std::string& reason);
    virtual ~DeviceFailureEvent();

    void process();
    int getDeviceId() const;
    void reset();
};

#endif
