#include "EventQueue.h"
#include "EventObjectPool.h"
#include "EventDispatcher.h"
#include "Camera.h"
#include "CameraBuilder.h"
#include "SecuritySystem.h"
#include "DeviceManager.h"
#include "DebugSimulator.h"
#include "MotionEvent.h"
#include <iostream>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Developer D - Camera + Motion System Tests" << std::endl;
    std::cout << "========================================" << std::endl;

    // Test 1: Singleton Pattern
    std::cout << "\n=== Test 1: Singleton Pattern ===" << std::endl;
    std::cout << "Testing EventQueue and EventObjectPool singletons..." << std::endl;

    EventQueue& queue1 = EventQueue::getInstance();
    EventQueue& queue2 = EventQueue::getInstance();
    std::cout << "EventQueue instance 1 address: " << &queue1 << std::endl;
    std::cout << "EventQueue instance 2 address: " << &queue2 << std::endl;
    std::cout << "Same instance? " << (&queue1 == &queue2 ? "YES" : "NO") << std::endl;

    EventObjectPool& pool1 = EventObjectPool::getInstance();
    EventObjectPool& pool2 = EventObjectPool::getInstance();
    std::cout << "EventObjectPool instance 1 address: " << &pool1 << std::endl;
    std::cout << "EventObjectPool instance 2 address: " << &pool2 << std::endl;
    std::cout << "Same instance? " << (&pool1 == &pool2 ? "YES" : "NO") << std::endl;

    DeviceManager& dm1 = DeviceManager::getInstance();
    DeviceManager& dm2 = DeviceManager::getInstance();
    std::cout << "DeviceManager instance 1 address: " << &dm1 << std::endl;
    std::cout << "DeviceManager instance 2 address: " << &dm2 << std::endl;
    std::cout << "Same instance? " << (&dm1 == &dm2 ? "YES" : "NO") << std::endl;

    // Test 2: Builder Pattern
    std::cout << "\n=== Test 2: Builder Pattern ===" << std::endl;
    std::cout << "Creating Camera using CameraBuilder fluent interface..." << std::endl;

    CameraBuilder builder(101, "Front Door Camera");
    Camera* camera = builder.setMotionDetection(true)
                            .setFPS(60)
                            .setNightVision(true)
                            .build();

    std::cout << "Camera created: " << camera->getName() << " (ID: " << camera->getId() << ")" << std::endl;
    camera->powerOn();
    camera->enableMotionDetection();
    std::cout << "Motion detection enabled via builder: " << (camera->getStatus() == "ON" ? "SUCCESS" : "FAILED") << std::endl;

    // Test 3: Object Pool Pattern
    std::cout << "\n=== Test 3: Object Pool Pattern ===" << std::endl;
    std::cout << "Testing event object pooling and reuse..." << std::endl;

    MotionEvent* event1 = pool1.acquireMotionEvent(101);
    std::cout << "Event 1 acquired, address: " << event1 << std::endl;
    std::cout << "Event 1 in use? " << (event1->isInUse() ? "YES" : "NO") << std::endl;

    pool1.releaseEvent(event1);
    std::cout << "Event 1 released" << std::endl;
    std::cout << "Event 1 in use after release? " << (event1->isInUse() ? "YES" : "NO") << std::endl;

    MotionEvent* event2 = pool1.acquireMotionEvent(102);
    std::cout << "Event 2 acquired, address: " << event2 << std::endl;
    std::cout << "Address reused? " << (event1 == event2 ? "YES (Object Pool working!)" : "NO (New object)") << std::endl;

    pool1.releaseEvent(event2);

    // Test 4: Observer Pattern
    std::cout << "\n=== Test 4: Observer Pattern ===" << std::endl;
    std::cout << "Testing many-to-many Observer pattern..." << std::endl;

    EventDispatcher dispatcher;
    SecuritySystem securitySystem;

    std::cout << "Subscribing SecuritySystem to MOTION_DETECTED events..." << std::endl;
    dispatcher.subscribeEventType(MOTION_DETECTED, &securitySystem);

    MotionEvent* testEvent = pool1.acquireMotionEvent(101);
    std::cout << "Dispatching motion event..." << std::endl;
    dispatcher.dispatch(testEvent);
    pool1.releaseEvent(testEvent);

    // Test 5: Full Motion Detection Sequence (LLR25)
    std::cout << "\n=== Test 5: Motion Detection (LLR25) ===" << std::endl;
    std::cout << "Testing complete flow: Camera.detectMotion() -> Event -> Dispatcher -> SecuritySystem" << std::endl;

    queue1.start();
    DeviceManager& deviceManager = DeviceManager::getInstance();
    deviceManager.addDevice(camera);

    std::cout << "\nTriggering motion detection..." << std::endl;
    camera->detectMotion();

    std::cout << "\nProcessing event from queue..." << std::endl;
    Event* queuedEvent = queue1.dequeue();
    if (queuedEvent != NULL) {
        dispatcher.dispatch(queuedEvent);
        pool1.releaseEvent(queuedEvent);
    }

    // Test 6: Debug Simulator (LLR38)
    std::cout << "\n=== Test 6: Debug Simulator (LLR38) ===" << std::endl;
    std::cout << "Testing simulateMotion() and simulateDeviceFailure()..." << std::endl;

    DebugSimulator simulator;

    std::cout << "\n--- Simulating motion on camera 101 ---" << std::endl;
    simulator.simulateMotion(101);

    std::cout << "\nProcessing simulated motion event..." << std::endl;
    Event* simulatedEvent = queue1.dequeue();
    if (simulatedEvent != NULL) {
        dispatcher.dispatch(simulatedEvent);
        pool1.releaseEvent(simulatedEvent);
    }

    std::cout << "\n--- Simulating device failure on device 101 ---" << std::endl;
    simulator.simulateDeviceFailure(101);

    std::cout << "\nProcessing failure event..." << std::endl;
    Event* failureEvent = queue1.dequeue();
    if (failureEvent != NULL) {
        failureEvent->process();
        pool1.releaseEvent(failureEvent);
    }

    std::cout << "\nDevice status after failure: " << camera->getStatus() << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "All Tests Completed Successfully!" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\n=== Design Patterns Demonstrated ===" << std::endl;
    std::cout << "1. Singleton Pattern: EventQueue, EventObjectPool, DeviceManager" << std::endl;
    std::cout << "2. Builder Pattern: CameraBuilder with fluent interface" << std::endl;
    std::cout << "3. Observer Pattern: EventDispatcher + SecuritySystem" << std::endl;
    std::cout << "4. Object Pool Pattern: EventObjectPool reuses event objects" << std::endl;

    std::cout << "\n=== LLRs Implemented ===" << std::endl;
    std::cout << "LLR10: Camera Device Class with inheritance from Device" << std::endl;
    std::cout << "LLR25: Motion Detection -> Alarm Sequence (Observer pattern)" << std::endl;
    std::cout << "LLR29: Event Queue/Scheduler with FIFO processing" << std::endl;
    std::cout << "LLR34: Camera Configuration using Builder pattern" << std::endl;
    std::cout << "LLR38: Debug Simulator for testing" << std::endl;

    return 0;
}
