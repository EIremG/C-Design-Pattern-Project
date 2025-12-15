#ifndef ALARM_H
#define ALARM_H

#include <iostream>
#include <string>
#include <unistd.h> // sleep için

class Alarm {
private:
    static Alarm* instance;
    bool active;
    
    // Singleton: Constructor private
    Alarm() : active(false) {}

public:
    // Singleton erişim
    static Alarm* getInstance();

    // Alarmı tetikle (Hangi cihazın tetiklediğini parametre alır)
    void trigger(const std::string& sourceDevice);

    // Durumu kontrol et ve işle (Zamanlayıcı simülasyonu)
    void update();

    // Alarmı sustur (HATAYI ÇÖZEN KISIM BU)
    void silence();
    
    // Alarm durumu sorgula
    bool isActive() const { return active; }
};

#endif