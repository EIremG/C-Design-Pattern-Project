#pragma once

#include <iostream>
#include <string>
#include "Logger.h" 

enum class DeviceType {
    LIGHT = 0,
    CAMERA = 1,
    TV = 2,
    MUSIC_SYSTEM = 3,
    SMOKE_DETECTOR = 4,
    GAS_DETECTOR = 5,
    ALARM = 6
};

class Device {
private:
    static int nextID;
    int id;
    // Düzeltme 1: isPoweredOn, sadece Device metotları tarafından değiştirilmelidir.
    bool isPoweredOn; 
    DeviceType type;

protected: 
    // Düzeltme 2: name değişkeni protected olmalıdır (Türetilmiş sınıfların kurucusu erişebilir).
    std::string name; 
    Logger* logger;

    // Kurucu protected olmalı
    Device(const std::string& name, DeviceType type) 
        : id(nextID++), name(name), isPoweredOn(false), type(type) {
        logger = Logger::getInstance();
        logger->log(LogLevel::INFO, "Device created: " + getName() + " (ID: " + std::to_string(id) + ")");
    }

public:
    virtual ~Device() {
        logger->log(LogLevel::INFO, "Device destroyed: " + getName());
    }

    static int getNextID() { return nextID; }

    // LLR11 - Base Operations
    virtual bool powerOn() {
        if (!isPoweredOn) {
            isPoweredOn = true;
            logger->log(LogLevel::INFO, getName() + " powered ON.");
            return true;
        }
        return false;
    }

    virtual bool powerOff() {
        if (isPoweredOn) {
            isPoweredOn = false;
            logger->log(LogLevel::INFO, getName() + " powered OFF.");
            return true;
        }
        return false;
    }
    
    // Düzeltme 3: isPoweredOn durumunu dışarıya açan public metot
    bool isPoweredOn() const { return isPoweredOn; }

    // LLR15 - Prototype Pattern
    virtual Device* clone() const = 0;

    // LLR17 - Criticality check
    virtual bool isCritical() const = 0; 

    // LLR11, LLR32 - Status reporting
    virtual std::string getStatus() const {
        return "ID: " + std::to_string(id) + " | Type: " + typeToString() + " | Name: " + name + 
               " | Status: " + (isPoweredOn ? "ON" : "OFF");
    }

    // Helper methods
    int getID() const { return id; }
    std::string getName() const { return name; }
    DeviceType getType() const { return type; }

    std::string typeToString() const {
        switch (type) {
            case DeviceType::LIGHT: return "Light";
            case DeviceType::CAMERA: return "Camera";
            case DeviceType::TV: return "TV";
            case DeviceType::MUSIC_SYSTEM: return "MusicSystem";
            case DeviceType::SMOKE_DETECTOR: return "SmokeDetector";
            case DeviceType::GAS_DETECTOR: return "GasDetector";
            case DeviceType::ALARM: return "Alarm";
        }
        return "UNKNOWN";
    }
};

int Device::nextID = 1000;