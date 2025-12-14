#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include "Event.h"
#include <queue>

// Forward declaration
class EventObjectPool;

// Singleton Pattern - LLR29: Event kuyrugu
class EventQueue {
private:
    static EventQueue* instance;

    std::queue<Event*> queue;
    bool isRunning;
    EventObjectPool* eventPool;

    EventQueue();
    EventQueue(const EventQueue&);
    EventQueue& operator=(const EventQueue&);

public:
    ~EventQueue();

    // Singleton Pattern
    static EventQueue& getInstance();

    void enqueueEvent(Event* event);
    Event* dequeue();
    void processNext();
    bool isEmpty() const;
    void start();
    void stop();
    void clear();
};

#endif
