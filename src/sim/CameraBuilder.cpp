#include "sim/CameraBuilder.h"

// Builder Pattern - LLR34
CameraBuilder::CameraBuilder(int id, const std::string& name) {
    camera = new Camera(id, name);
}

CameraBuilder::~CameraBuilder() {
}

// Builder Pattern: Fluent interface - method chaining
CameraBuilder& CameraBuilder::setMotionDetection(bool enabled) {
    camera->motionDetection = enabled;
    return *this;
}

CameraBuilder& CameraBuilder::setFPS(int f) {
    camera->fps = f;
    return *this;
}

CameraBuilder& CameraBuilder::setNightVision(bool enabled) {
    camera->nightVision = enabled;
    return *this;
}

Camera* CameraBuilder::build() {
    return camera;
}
