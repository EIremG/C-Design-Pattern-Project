#ifndef DEBUGSIMULATOR_H
#define DEBUGSIMULATOR_H

#include "Event.h"

// Forward declarations
class DeviceManager;
class EventObjectPool;
class EventQueue;

// LLR38: Debug ve test icin simulator
class DebugSimulator {
private:
    DeviceManager* deviceManager;
    EventObjectPool* eventPool;
    EventQueue* eventQueue;

public:
    DebugSimulator();
    ~DebugSimulator();

    // LLR38: Simulasyon fonksiyonlari
    void simulateDeviceFailure(int deviceId);
    void simulateMotion(int cameraId);
    void simulateAlarm(int detectorId);
    void injectEvent(Event* event);
};

#endif
