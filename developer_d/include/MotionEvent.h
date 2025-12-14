#ifndef MOTIONEVENT_H
#define MOTIONEVENT_H

#include "Event.h"

// LLR29: MotionEvent sinifi
class MotionEvent : public Event {
private:
    int cameraId;
    float motionIntensity;

public:
    MotionEvent();
    MotionEvent(int camId);
    virtual ~MotionEvent();

    void process();
    int getCameraId() const;
    void reset();
};

#endif
