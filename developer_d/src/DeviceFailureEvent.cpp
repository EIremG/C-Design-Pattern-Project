#include "DeviceFailureEvent.h"
#include <iostream>

// LLR29: DeviceFailureEvent implementasyonu
DeviceFailureEvent::DeviceFailureEvent() : Event(DEVICE_FAILED), deviceId(0), failureReason("") {
}

DeviceFailureEvent::DeviceFailureEvent(int devId, const std::string& reason)
    : Event(DEVICE_FAILED), deviceId(devId), failureReason(reason) {
}

DeviceFailureEvent::~DeviceFailureEvent() {
}

void DeviceFailureEvent::process() {
    std::cout << "[DeviceFailureEvent] Device " << deviceId
              << " failed - Reason: " << failureReason << std::endl;
}

int DeviceFailureEvent::getDeviceId() const {
    return deviceId;
}

void DeviceFailureEvent::reset() {
    Event::reset();
    deviceId = 0;
    failureReason = "";
}
