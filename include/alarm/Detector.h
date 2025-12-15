#ifndef DETECTOR_H
#define DETECTOR_H

#include "alarm/AlarmDevice.h"
#include "alarm/Alarm.h" 
#include <iostream>

// Soyut Detector Sınıfı
class Detector : public AlarmDevice {
protected:
    float sensitivity;
    float threshold;

public:
    // Dedektörler kritik cihazlardır (critical = true)
    Detector(int id, const std::string& name, DeviceType type, float thresh)
        : AlarmDevice(id, name, type, true), sensitivity(1.0f), threshold(thresh) {}

    void setSensitivity(float s) { sensitivity = s; }

    // UML gereği saf sanal fonksiyon
    virtual bool detect() = 0;

    // Test simülasyonu için yardımcı fonksiyon
    virtual void simulateDanger(float level) = 0;
};

// Duman Dedektörü
class SmokeDetector : public Detector {
private:
    float particleDensity; 

public:
    SmokeDetector(int id) 
        : Detector(id, "Smoke Detector", SMOKE_DETECTOR, 50.0f), particleDensity(0) {}

    // Duman değerini simüle et ve kontrol et
    void simulateDanger(float level) override {
        particleDensity = level;
        detect();
    }

    bool detect() override {
        if (status == FAILED) {
            std::cout << "[FAILURE] " << name << " is FAILED. No detection.\n";
            return false;
        }

        std::cout << "[SENSOR] " << name << " duman seviyesi: " << particleDensity << "\n";
        if (particleDensity > threshold) {
            Alarm::getInstance()->trigger(name); // Alarmı tetikle
            return true;
        }
        return false;
    }
};

// Gaz Dedektörü
class GasDetector : public Detector {
private:
    float gasConcentration;

public:
    GasDetector(int id) 
        : Detector(id, "Gas Detector", GAS_DETECTOR, 30.0f), gasConcentration(0) {}

    // Gaz değerini simüle et ve kontrol et
    void simulateDanger(float level) override {
        gasConcentration = level;
        detect();
    }

    bool detect() override {
        if (status == FAILED) {
             std::cout << "[FAILURE] " << name << " is FAILED. No detection.\n";
             return false;
        }

        std::cout << "[SENSOR] " << name << " gaz seviyesi: " << gasConcentration << "\n";
        if (gasConcentration > threshold) {
            Alarm::getInstance()->trigger(name);
            return true;
        }
        return false;
    }
};

#endif