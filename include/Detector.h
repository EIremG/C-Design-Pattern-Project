#pragma once
#include "Device.h" 

class Detector : public Device {
protected:
    float threshold;
    float detectionRange;

    // Template Method Primitive Operations
    virtual bool checkCondition() const = 0; // The specific check (smoke, gas, etc.)
    virtual void notify() const {
        logger->log(LogLevel::CRITICAL, "CRITICAL DETECTION: Threshold exceeded by " + getName() + "!");
    }

public:
    Detector(const std::string& name, DeviceType type, float threshold, float range)
        : Device(name, type), threshold(threshold), detectionRange(range) {
        // Dedektörler kritik olduğu için otomatik olarak açılır.
        powerOn(); 
    }

    // LLR12 - Template Method Pattern
    bool detect() {
        // DÜZELTME: isPoweredOn değişkenine doğrudan erişim yerine
        // Device sınıfındaki public isPoweredOn() metodu kullanılıyor.
        // Hata 22. satırda burada olmalıydı: if (!isPoweredOn)
        if (!isPoweredOn()) { // <-- Düzeltilmiş Satır
            logger->log(LogLevel::WARNING, getName() + " is off and cannot detect.");
            return false;
        }

        if (checkCondition()) {
            notify();
            return true;
        }
        logger->log(LogLevel::DEBUG, getName() + " checked, condition normal.");
        return false;
    }

    // Critical devices cannot be powered off (LLR17)
    bool powerOff() override {
        logger->log(LogLevel::CRITICAL, "SECURITY ALERT: Attempt to power off the Detector (" + getName() + ") was blocked.");
        return false;
    }

    // Detectors are always critical (LLR17)
    bool isCritical() const override { return true; }
    
    // ... (Diğer metotlar ve kurucu)
};