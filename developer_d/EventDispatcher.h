#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include "EventObserver.h"
#include "EventType.h"
#include <map>
#include <vector>

// Forward declaration
class EventQueue;

// Observer Pattern - LLR29: Event dagitici
class EventDispatcher {
private:
    std::map<EventType, std::vector<EventObserver*> > observers;
    EventQueue* eventQueue;

public:
    EventDispatcher();
    ~EventDispatcher();

    void subscribeEventType(EventType type, EventObserver* observer);
    void unsubscribeEventType(EventType type, EventObserver* observer);
    void dispatch(Event* event);
    void notifyObservers(Event* event);
};

#endif
