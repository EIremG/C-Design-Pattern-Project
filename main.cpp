#include "Alarm.h"
#include <thread>
#include <chrono>

int main() {
    std::cout << "--- Sencer (Developer E) Alarm Modulu Testi ---" << std::endl;
    Alarm* alarmSystem = Alarm::getInstance();

    // Senaryo: Duman dedektörü alarmı tetikliyor
    alarmSystem->trigger("Smoke Detector 1");

    // 25 saniye boyunca sistemi izliyoruz
    for (int i = 0; i < 25; ++i) {
        std::cout << "Time: " << i << "s" << std::endl;
        alarmSystem->update();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}