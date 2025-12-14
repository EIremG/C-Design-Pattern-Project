#ifndef EVENT_H
#define EVENT_H

#include "EventType.h"
#include <ctime>

// LLR29: Abstract Event sinifi
class Event {
protected:
    EventType type;
    time_t timestamp;
    bool inUse;

public:
    Event();
    Event(EventType eventType);
    virtual ~Event();

    EventType getType() const;
    time_t getTimestamp() const;

    // Saf sanal fonksiyon
    virtual void process() = 0;

    virtual void reset();
    void setInUse(bool use);
    bool isInUse() const;
};

#endif
