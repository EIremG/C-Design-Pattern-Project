#include "DebugSimulator.h"
#include "DeviceManager.h"
#include "EventObjectPool.h"
#include "EventQueue.h"
#include "MotionEvent.h"
#include "AlarmEvent.h"
#include "DeviceFailureEvent.h"
#include <iostream>

// LLR38: Debug simulator implementasyonu
DebugSimulator::DebugSimulator() {
    deviceManager = &DeviceManager::getInstance();
    eventPool = &EventObjectPool::getInstance();
    eventQueue = &EventQueue::getInstance();
}

DebugSimulator::~DebugSimulator() {
}

// LLR38: Cihaz hatasini simule et
void DebugSimulator::simulateDeviceFailure(int deviceId) {
    std::cout << "\n[DebugSimulator] Simulating device failure for device " << deviceId << std::endl;

    // Cihazi FAILED durumuna getir
    Device* device = deviceManager->getDevice(deviceId);
    if (device != NULL) {
        device->setFailed();
        std::cout << "[DebugSimulator] Device " << deviceId << " set to FAILED" << std::endl;
    }

    // DeviceFailureEvent olustur ve kuyruğa ekle
    DeviceFailureEvent* event = eventPool->acquireFailureEvent(deviceId, "Simulated failure");
    eventQueue->enqueueEvent(event);
}

// LLR38: Motion event simule et
void DebugSimulator::simulateMotion(int cameraId) {
    std::cout << "\n[DebugSimulator] Simulating motion for camera " << cameraId << std::endl;

    // MotionEvent olustur ve kuyruğa ekle
    MotionEvent* event = eventPool->acquireMotionEvent(cameraId);
    eventQueue->enqueueEvent(event);
}

void DebugSimulator::simulateAlarm(int detectorId) {
    std::cout << "\n[DebugSimulator] Simulating alarm for detector " << detectorId << std::endl;

    // AlarmEvent olustur ve kuyruğa ekle
    AlarmEvent* event = eventPool->acquireAlarmEvent(detectorId, ALARM_TRIGGERED, "Simulated alarm");
    eventQueue->enqueueEvent(event);
}

// LLR38: Event'i doğrudan kuyruğa ekle
void DebugSimulator::injectEvent(Event* event) {
    if (event != NULL) {
        std::cout << "[DebugSimulator] Injecting event of type " << event->getType() << std::endl;
        eventQueue->enqueueEvent(event);
    }
}
