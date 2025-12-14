#include "Detector.h" // Also serves as SmokeDetector.h

class SmokeDetector : public Detector {
private:
    float particleDensity; // Current reading (0-100)

protected:
    bool checkCondition() const override {
        return particleDensity > threshold;
    }

public:
    SmokeDetector(const std::string& name, float threshold, float range)
        : Detector(name, DeviceType::SMOKE_DETECTOR, threshold, range), particleDensity(0.0f) {}

    Device* clone() const override {
        return new SmokeDetector(name, threshold, detectionRange);
    }

    void setParticleDensity(float density) {
        particleDensity = density;
        logger->log(LogLevel::DEBUG, getName() + " density updated to " + std::to_string(density) + ".");
    }

    std::string getStatus() const override {
        return Device::getStatus() + " | Density: " + std::to_string(particleDensity) + 
               " | Threshold: " + std::to_string(threshold);
    }
};