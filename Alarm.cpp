#include "Alarm.h"

// Static değişkeni başlat
Alarm* Alarm::instance = nullptr;

Alarm* Alarm::getInstance() {
    if (instance == nullptr) {
        instance = new Alarm();
    }
    return instance;
}

void Alarm::trigger(const std::string& sourceDevice) {
    if (!active) {
        active = true;
        std::cout << "\n[ALARM] TEHLIKE! Kaynak: " << sourceDevice << " - Alarm Tetiklendi!" << std::endl;
    }
}

void Alarm::update() {
    if (active) {
        static int timer = 0;
        timer++;
        
        // 1. Aşama: Kullanıcı onayı bekle
        if (timer < 10) {
            std::cout << "[INFO] Kullanici onayi bekleniyor (" << timer << " saniye)..." << std::endl;
        }
        // 2. Aşama: Işıkları yakıp söndür (Blink) - LLR28
        else if (timer >= 10 && timer < 20) {
            if (timer % 2 == 0) std::cout << "[LIGHT] ON (Blinking...)" << std::endl;
            else std::cout << "[LIGHT] OFF (Blinking...)" << std::endl;
        }
        // 3. Aşama: İtfaiye/Acil Durum - LLR27
        else if (timer == 20) {
            std::cout << "[EMERGENCY] KULLANICI YANIT VERMEDI! ITFAIYE ARANIYOR..." << std::endl;
        }
    }
}

void Alarm::silence() {
    active = false;
    std::cout << "[ALARM] Alarm susturuldu. Sistem guvenli." << std::endl;
}