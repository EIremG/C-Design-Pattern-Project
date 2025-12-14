#include "SecuritySystem.h"
#include "MotionEvent.h"
#include <iostream>

// Observer Pattern - LLR25
SecuritySystem::SecuritySystem() {
    alarm = new Alarm();
    lightManager = new LightManager();
}

SecuritySystem::~SecuritySystem() {
    delete alarm;
    delete lightManager;
}

// Observer Pattern: Event geldiginde cagrilir
void SecuritySystem::onEvent(Event* event) {
    if (event == NULL) {
        return;
    }

    std::cout << "\n[SecuritySystem] Event received: Type " << event->getType() << std::endl;

    // LLR25: Motion detection event'ini isle
    if (event->getType() == MOTION_DETECTED) {
        MotionEvent* motionEvent = dynamic_cast<MotionEvent*>(event);
        if (motionEvent != NULL) {
            std::cout << "[SecuritySystem] Motion detected from camera "
                      << motionEvent->getCameraId() << std::endl;

            // LLR25: Alarm -> Lights -> Police sequence
            triggerAlarm();
            turnOnLights();
            callPolice();
        }
    }
}

std::string SecuritySystem::getObserverType() const {
    return "SecuritySystem";
}

// LLR25: Alarm'i tetikle
void SecuritySystem::triggerAlarm() {
    std::cout << "[SecuritySystem] Step 1: Triggering alarm..." << std::endl;
    alarm->trigger();
}

void SecuritySystem::turnOnLights() {
    std::cout << "[SecuritySystem] Step 2: Turning on lights..." << std::endl;
    lightManager->turnOnAll();
}

void SecuritySystem::callPolice() {
    std::cout << "[SecuritySystem] Step 3: Calling police..." << std::endl;
    std::cout << "                 Calling 911 - Emergency!" << std::endl;
}
