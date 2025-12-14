#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "EventObserver.h"
#include <iostream>

// Stub classes - will be provided by other developers
class Alarm {
public:
    void trigger() {
        std::cout << "[STUB - Alarm] ALARM TRIGGERED!" << std::endl;
    }
};

class LightManager {
public:
    void turnOnAll() {
        std::cout << "[STUB - LightManager] All lights turned ON" << std::endl;
    }
};

// Observer Pattern - LLR25: SecuritySystem
class SecuritySystem : public EventObserver {
private:
    Alarm* alarm;
    LightManager* lightManager;

public:
    SecuritySystem();
    virtual ~SecuritySystem();

    // EventObserver interface implementation
    void onEvent(Event* event);
    std::string getObserverType() const;

    // LLR25: Security actions
    void triggerAlarm();
    void turnOnLights();
    void callPolice();
};

#endif
