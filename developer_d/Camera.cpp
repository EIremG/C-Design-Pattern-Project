#include "Camera.h"
#include "EventObjectPool.h"
#include "EventQueue.h"
#include "MotionEvent.h"
#include <iostream>

// LLR10: Camera implementasyonu
Camera::Camera(int id, const std::string& name)
    : Device(id, name), motionDetection(false), fps(30), nightVision(false) {
}

Camera::~Camera() {
}

void Camera::powerOn() {
    status = "ON";
    std::cout << "[Camera " << deviceId << "] Powered ON" << std::endl;
}

void Camera::powerOff() {
    status = "OFF";
    std::cout << "[Camera " << deviceId << "] Powered OFF" << std::endl;
}

void Camera::enableMotionDetection() {
    motionDetection = true;
    std::cout << "[Camera " << deviceId << "] Motion detection ENABLED" << std::endl;
}

void Camera::disableMotionDetection() {
    motionDetection = false;
    std::cout << "[Camera " << deviceId << "] Motion detection DISABLED" << std::endl;
}

void Camera::setFPS(int f) {
    fps = f;
    std::cout << "[Camera " << deviceId << "] FPS set to " << fps << std::endl;
}

void Camera::setNightVision(bool enabled) {
    nightVision = enabled;
    std::cout << "[Camera " << deviceId << "] Night vision "
              << (enabled ? "ENABLED" : "DISABLED") << std::endl;
}

// LLR25: Motion algılandığında event oluştur
void Camera::detectMotion() {
    if (!motionDetection) {
        std::cout << "[Camera " << deviceId << "] Motion detection is disabled" << std::endl;
        return;
    }

    std::cout << "[Camera " << deviceId << "] MOTION DETECTED!" << std::endl;

    // Object Pool'dan MotionEvent al
    MotionEvent* event = EventObjectPool::getInstance().acquireMotionEvent(deviceId);

    // Event'i kuyruğa ekle
    EventQueue::getInstance().enqueueEvent(event);
}

void Camera::startRecording() {
    std::cout << "[Camera " << deviceId << "] Recording STARTED" << std::endl;
}

void Camera::stopRecording() {
    std::cout << "[Camera " << deviceId << "] Recording STOPPED" << std::endl;
}
