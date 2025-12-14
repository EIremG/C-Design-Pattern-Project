#include "Event.h"
#include <ctime>

// LLR29: Event sinifi implementasyonu
Event::Event() : type(STATE_CHANGED), inUse(false) {
    timestamp = time(NULL);
}

Event::Event(EventType eventType) : type(eventType), inUse(false) {
    timestamp = time(NULL);
}

Event::~Event() {
}

EventType Event::getType() const {
    return type;
}

time_t Event::getTimestamp() const {
    return timestamp;
}

void Event::reset() {
    timestamp = time(NULL);
    inUse = false;
}

void Event::setInUse(bool use) {
    inUse = use;
}

bool Event::isInUse() const {
    return inUse;
}
