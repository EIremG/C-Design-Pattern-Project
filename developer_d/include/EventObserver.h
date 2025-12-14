#ifndef EVENTOBSERVER_H
#define EVENTOBSERVER_H

#include "Event.h"
#include <string>

// LLR29: Observer Pattern - EventObserver interface
class EventObserver {
public:
    virtual ~EventObserver() {}

    // Saf sanal fonksiyonlar
    virtual void onEvent(Event* event) = 0;
    virtual std::string getObserverType() const = 0;
};

#endif
