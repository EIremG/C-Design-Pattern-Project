#include "EventDispatcher.h"
#include "EventQueue.h"
#include <iostream>

// Observer Pattern - LLR29
EventDispatcher::EventDispatcher() {
    eventQueue = &EventQueue::getInstance();
}

EventDispatcher::~EventDispatcher() {
}

// Observer Pattern: Observer'i belirli bir event tipine kaydet
void EventDispatcher::subscribeEventType(EventType type, EventObserver* observer) {
    if (observer != NULL) {
        observers[type].push_back(observer);
        std::cout << "[EventDispatcher] Observer subscribed to event type " << type << std::endl;
    }
}

void EventDispatcher::unsubscribeEventType(EventType type, EventObserver* observer) {
    if (observer == NULL) {
        return;
    }

    std::map<EventType, std::vector<EventObserver*> >::iterator mapIt = observers.find(type);
    if (mapIt != observers.end()) {
        std::vector<EventObserver*>& observerList = mapIt->second;
        std::vector<EventObserver*>::iterator it;
        for (it = observerList.begin(); it != observerList.end(); ++it) {
            if (*it == observer) {
                observerList.erase(it);
                std::cout << "[EventDispatcher] Observer unsubscribed from event type " << type << std::endl;
                break;
            }
        }
    }
}

// LLR29: Event'i isle ve observer'lari bilgilendir
void EventDispatcher::dispatch(Event* event) {
    if (event != NULL) {
        std::cout << "[EventDispatcher] Dispatching event type " << event->getType() << std::endl;
        notifyObservers(event);
    }
}

// Observer Pattern: Tum observer'lari bilgilendir
void EventDispatcher::notifyObservers(Event* event) {
    if (event == NULL) {
        return;
    }

    EventType type = event->getType();
    std::map<EventType, std::vector<EventObserver*> >::iterator mapIt = observers.find(type);

    if (mapIt != observers.end()) {
        std::vector<EventObserver*>& observerList = mapIt->second;
        std::vector<EventObserver*>::iterator it;
        for (it = observerList.begin(); it != observerList.end(); ++it) {
            EventObserver* observer = *it;
            if (observer != NULL) {
                std::cout << "[EventDispatcher] Notifying observer: " << observer->getObserverType() << std::endl;
                observer->onEvent(event);
            }
        }
    }
}
