#ifndef EVENTOBJECTPOOL_H
#define EVENTOBJECTPOOL_H

#include "MotionEvent.h"
#include "AlarmEvent.h"
#include "DeviceFailureEvent.h"
#include <vector>

// Object Pool Pattern + Singleton Pattern
// LLR29: Event nesnelerini yeniden kullanmak icin pool
class EventObjectPool {
private:
    static EventObjectPool* instance;

    std::vector<MotionEvent*> motionEventPool;
    std::vector<AlarmEvent*> alarmEventPool;
    std::vector<DeviceFailureEvent*> failureEventPool;
    int maxPoolSize;

    EventObjectPool();
    EventObjectPool(const EventObjectPool&);
    EventObjectPool& operator=(const EventObjectPool&);

    MotionEvent* createMotionEvent();
    AlarmEvent* createAlarmEvent();
    DeviceFailureEvent* createFailureEvent();

public:
    ~EventObjectPool();

    // Singleton Pattern
    static EventObjectPool& getInstance();

    MotionEvent* acquireMotionEvent(int cameraId);
    AlarmEvent* acquireAlarmEvent(int detectorId, EventType type, const std::string& reason);
    DeviceFailureEvent* acquireFailureEvent(int deviceId, const std::string& reason);

    void releaseEvent(Event* event);
    void clear();
};

#endif
