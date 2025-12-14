#include "EventQueue.h"
#include "EventObjectPool.h"
#include <iostream>

// Singleton Pattern - static instance
EventQueue* EventQueue::instance = NULL;

// Singleton Pattern - LLR29
EventQueue::EventQueue() : isRunning(false) {
    eventPool = &EventObjectPool::getInstance();
}

EventQueue::~EventQueue() {
    clear();
}

// Singleton Pattern
EventQueue& EventQueue::getInstance() {
    if (instance == NULL) {
        instance = new EventQueue();
    }
    return *instance;
}

// LLR29: Event'i kuyruğa ekle
void EventQueue::enqueueEvent(Event* event) {
    if (event != NULL) {
        queue.push(event);
        std::cout << "[EventQueue] Event enqueued. Queue size: " << queue.size() << std::endl;
    }
}

Event* EventQueue::dequeue() {
    if (queue.empty()) {
        return NULL;
    }

    Event* event = queue.front();
    queue.pop();
    return event;
}

// LLR29: Bir sonraki event'i isle
void EventQueue::processNext() {
    if (queue.empty()) {
        return;
    }

    Event* event = dequeue();
    if (event != NULL) {
        std::cout << "[EventQueue] Processing event..." << std::endl;
        event->process();

        // Event'i pool'a geri dondur
        eventPool->releaseEvent(event);
    }
}

bool EventQueue::isEmpty() const {
    return queue.empty();
}

void EventQueue::start() {
    isRunning = true;
    std::cout << "[EventQueue] Started" << std::endl;
}

void EventQueue::stop() {
    isRunning = false;
    std::cout << "[EventQueue] Stopped" << std::endl;
}

void EventQueue::clear() {
    while (!queue.empty()) {
        Event* event = queue.front();
        queue.pop();
        if (event != NULL) {
            eventPool->releaseEvent(event);
        }
    }
}
