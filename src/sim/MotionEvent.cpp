#include "sim/MotionEvent.h"
#include <iostream>

// LLR29: MotionEvent implementasyonu
MotionEvent::MotionEvent() : Event(MOTION_DETECTED), cameraId(0), motionIntensity(0.0f) {
}

MotionEvent::MotionEvent(int camId) : Event(MOTION_DETECTED), cameraId(camId), motionIntensity(1.0f) {
}

MotionEvent::~MotionEvent() {
}

void MotionEvent::process() {
    std::cout << "[MotionEvent] Processing motion from camera " << cameraId << std::endl;
}

int MotionEvent::getCameraId() const {
    return cameraId;
}

void MotionEvent::reset() {
    Event::reset();
    cameraId = 0;
    motionIntensity = 0.0f;
}
