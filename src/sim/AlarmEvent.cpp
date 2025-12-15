#include "sim/AlarmEvent.h"
#include <iostream>

// LLR29: AlarmEvent implementasyonu
AlarmEvent::AlarmEvent() : Event(ALARM_TRIGGERED), detectorId(0), reason("") {
}

AlarmEvent::AlarmEvent(int detId, EventType eventType, const std::string& alarmReason)
    : Event(eventType), detectorId(detId), reason(alarmReason) {
}

AlarmEvent::~AlarmEvent() {
}

void AlarmEvent::process() {
    std::cout << "[AlarmEvent] Processing alarm from detector " << detectorId
              << " - Reason: " << reason << std::endl;
}

void AlarmEvent::reset() {
    Event::reset();
    detectorId = 0;
    reason = "";
}
