#include "EventObjectPool.h"
#include <iostream>

// Singleton Pattern - static instance
EventObjectPool* EventObjectPool::instance = NULL;

// Object Pool Pattern + Singleton Pattern
EventObjectPool::EventObjectPool() : maxPoolSize(10) {
}

EventObjectPool::~EventObjectPool() {
    clear();
}

// Singleton Pattern
EventObjectPool& EventObjectPool::getInstance() {
    if (instance == NULL) {
        instance = new EventObjectPool();
    }
    return *instance;
}

MotionEvent* EventObjectPool::createMotionEvent() {
    return new MotionEvent();
}

AlarmEvent* EventObjectPool::createAlarmEvent() {
    return new AlarmEvent();
}

DeviceFailureEvent* EventObjectPool::createFailureEvent() {
    return new DeviceFailureEvent();
}

// Object Pool Pattern: Event nesnesini pool'dan al veya yeni olustur
MotionEvent* EventObjectPool::acquireMotionEvent(int cameraId) {
    MotionEvent* event = NULL;

    // Pool'dan kullanilabilir event bul
    std::vector<MotionEvent*>::iterator it;
    for (it = motionEventPool.begin(); it != motionEventPool.end(); ++it) {
        if (!(*it)->isInUse()) {
            event = *it;
            break;
        }
    }

    // Bulunamadiysa yeni olustur
    if (event == NULL) {
        event = new MotionEvent(cameraId);
        if (motionEventPool.size() < (size_t)maxPoolSize) {
            motionEventPool.push_back(event);
        }
    } else {
        // Mevcut event'i reset et ve yeniden kullan
        event->reset();
        event = new (event) MotionEvent(cameraId);
    }

    event->setInUse(true);
    return event;
}

AlarmEvent* EventObjectPool::acquireAlarmEvent(int detectorId, EventType type, const std::string& reason) {
    AlarmEvent* event = NULL;

    std::vector<AlarmEvent*>::iterator it;
    for (it = alarmEventPool.begin(); it != alarmEventPool.end(); ++it) {
        if (!(*it)->isInUse()) {
            event = *it;
            break;
        }
    }

    if (event == NULL) {
        event = new AlarmEvent(detectorId, type, reason);
        if (alarmEventPool.size() < (size_t)maxPoolSize) {
            alarmEventPool.push_back(event);
        }
    } else {
        event->reset();
        event = new (event) AlarmEvent(detectorId, type, reason);
    }

    event->setInUse(true);
    return event;
}

DeviceFailureEvent* EventObjectPool::acquireFailureEvent(int deviceId, const std::string& reason) {
    DeviceFailureEvent* event = NULL;

    std::vector<DeviceFailureEvent*>::iterator it;
    for (it = failureEventPool.begin(); it != failureEventPool.end(); ++it) {
        if (!(*it)->isInUse()) {
            event = *it;
            break;
        }
    }

    if (event == NULL) {
        event = new DeviceFailureEvent(deviceId, reason);
        if (failureEventPool.size() < (size_t)maxPoolSize) {
            failureEventPool.push_back(event);
        }
    } else {
        event->reset();
        event = new (event) DeviceFailureEvent(deviceId, reason);
    }

    event->setInUse(true);
    return event;
}

// Event'i pool'a geri dondur
void EventObjectPool::releaseEvent(Event* event) {
    if (event != NULL) {
        event->reset();
        event->setInUse(false);
    }
}

void EventObjectPool::clear() {
    std::vector<MotionEvent*>::iterator motionIt;
    for (motionIt = motionEventPool.begin(); motionIt != motionEventPool.end(); ++motionIt) {
        delete *motionIt;
    }
    motionEventPool.clear();

    std::vector<AlarmEvent*>::iterator alarmIt;
    for (alarmIt = alarmEventPool.begin(); alarmIt != alarmEventPool.end(); ++alarmIt) {
        delete *alarmIt;
    }
    alarmEventPool.clear();

    std::vector<DeviceFailureEvent*>::iterator failureIt;
    for (failureIt = failureEventPool.begin(); failureIt != failureEventPool.end(); ++failureIt) {
        delete *failureIt;
    }
    failureEventPool.clear();
}
