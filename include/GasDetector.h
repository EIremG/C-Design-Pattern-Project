#pragma once
#include "Detector.h" // Detector.h de Device.h'ı içerir

class GasDetector : public Detector {
private:
    float gasConcentration; // Current reading (0-100)

protected:
    bool checkCondition() const override {
        return gasConcentration > threshold;
    }

public:
    // 17. Satır: Burada temel sınıf kurucusunu çağırıyor.
    GasDetector(const std::string& name, float threshold, float range)
        // Device kurucusuna name'i iletiyor. name artık protected.
        : Detector(name, DeviceType::GAS_DETECTOR, threshold, range), gasConcentration(0.0f) {}

    Device* clone() const override {
        // name değişkenine erişim burada da protected olduğu için sorunsuz
        return new GasDetector(name, threshold, detectionRange);
    }

    void setGasConcentration(float concentration) {
        gasConcentration = concentration;
        logger->log(LogLevel::DEBUG, getName() + " concentration updated to " + std::to_string(concentration) + ".");
    }

    std::string getStatus() const override {
        return Device::getStatus() + " | Concentration: " + std::to_string(gasConcentration) + 
               " | Threshold: " + std::to_string(threshold);
    }
    
    // isCritical() Detector.h'de tanımlandığı için burada tekrar tanımlamaya gerek yok
};