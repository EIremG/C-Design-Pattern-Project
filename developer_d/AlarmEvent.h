#ifndef ALARMEVENT_H
#define ALARMEVENT_H

#include "Event.h"
#include <string>

// LLR29: AlarmEvent sinifi
class AlarmEvent : public Event {
private:
    int detectorId;
    std::string reason;

public:
    AlarmEvent();
    AlarmEvent(int detId, EventType eventType, const std::string& alarmReason);
    virtual ~AlarmEvent();

    void process();
    void reset();
};

#endif
