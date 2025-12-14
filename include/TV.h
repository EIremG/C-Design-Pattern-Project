#include "Device.h" // Also serves as TV.h

enum class TVBrand {
    SAMSUNG = 0,
    LG = 1,
    SONY = 2
};

class TV : public Device {
private:
    TVBrand brand;
    int volume; // 0-100
    int channel; // 1-99

public:
    TV(const std::string& name, TVBrand brand)
        : Device(name, DeviceType::TV), brand(brand), volume(50), channel(1) {}

    Device* clone() const override {
        return new TV(name, brand);
    }

    // LLR33 - Specific operations
    void setVolume(int vol) {
        if (vol >= 0 && vol <= 100) {
            volume = vol;
            logger->log(LogLevel::INFO, getName() + " volume set to " + std::to_string(volume) + ".");
        }
    }

    void changeChannel(int ch) {
        channel = ch;
        logger->log(LogLevel::INFO, getName() + " changed channel to " + std::to_string(channel) + ".");
    }

    std::string getStatus() const override {
        std::string brandName;
        switch (brand) {
            case TVBrand::SAMSUNG: brandName = "SAMSUNG"; break;
            case TVBrand::LG: brandName = "LG"; break;
            case TVBrand::SONY: brandName = "SONY"; break;
        }
        return Device::getStatus() + " | Brand: " + brandName + " | Volume: " + std::to_string(volume) + 
               " | Channel: " + std::to_string(channel);
    }

    bool isCritical() const override { return false; }
};