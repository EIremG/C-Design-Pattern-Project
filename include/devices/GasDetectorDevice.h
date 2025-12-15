#pragma once

#include "devices/DetectorDevice.h"   // <-- base class burada!
#include <string>

class GasDetectorDevice : public DetectorDevice {
private:
    float gasConcentration;

public:
    GasDetectorDevice(const std::string& name,
        float sensitivity = 0.7f,
        float threshold = 100.0f);

    // override kullanma: imza uyuşmazsa hata veriyor
    virtual bool powerOn();
    virtual std::string getStatus() const;
    virtual HomeDevice* clone() const;

    // DetectorDevice içinde virtual olmalı
    virtual bool detect();

    void setGasConcentration(float concentration) { gasConcentration = concentration; }
    float getGasConcentration() const { return gasConcentration; }
};
