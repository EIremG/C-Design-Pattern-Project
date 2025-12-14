#include "Alarm.h"

Alarm* Alarm::instance = nullptr;

Alarm::Alarm() : active(false), acknowledged(false), fireDeptCalled(false) {}

Alarm* Alarm::getInstance() {
    if (instance == nullptr) {
        instance = new Alarm();
    }
    return instance;
}

void Alarm::trigger(const std::string& source) {
    if (!active) {
        active = true;
        acknowledged = false;
        fireDeptCalled = false;
        startTime = std::chrono::steady_clock::now();
        std::cout << "[ALARM] TEHLIKE! Kaynak: " << source << " - Alarm Tetiklendi!" << std::endl;
        std::cout << "[INFO] Kullanici onayi bekleniyor (10 saniye)..." << std::endl;
    }
}

void Alarm::acknowledge() {
    if (active) {
        acknowledged = true;
        active = false;
        std::cout << "[USER] Alarm kullanıcı tarafından onaylandı ve susturuldu." << std::endl;
    }
}

void Alarm::reset() {
    active = false;
    acknowledged = false;
    fireDeptCalled = false;
    std::cout << "[INFO] Alarm sistemi resetlendi." << std::endl;
}

void Alarm::update() {
    if (!active || acknowledged) return;

    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();

    // 10 saniye onay gelmezse ışıklar yanıp söner (Blink Simulation)
    if (elapsed > 10) {
        if (elapsed % 2 == 0) {
            std::cout << "[LIGHT] ON (Blinking...)" << std::endl;
        } else {
            std::cout << "[LIGHT] OFF (Blinking...)" << std::endl;
        }
    }

    // 20 saniye onay gelmezse İtfaiye aranır
    if (elapsed > 20 && !fireDeptCalled) {
        std::cout << "[EMERGENCY] KULLANICI YANIT VERMEDI! ITFAIYE ARANIYOR..." << std::endl;
        fireDeptCalled = true;
    }
}