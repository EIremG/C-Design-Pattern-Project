#include <iostream>
#include <unistd.h> // sleep fonksiyonu için
#include "Alarm.h"
#include "DetectorFactory.h"

void testScenario() {
    std::cout << "--- Sencer (Developer E) UML Uyumlu Test ---" << std::endl;

    // 1. Factory ile Dedektörleri Oluştur (DeviceType Enum kullanarak)
    Detector* smokeDet = DetectorFactory::createDetector(SMOKE_DETECTOR, 101);
    Detector* gasDet = DetectorFactory::createDetector(GAS_DETECTOR, 102);

    // Cihazları Aç
    smokeDet->powerOn();
    gasDet->powerOn();

    // 2. Normal Alarm Testi (Duman)
    std::cout << "\n[TEST] Saglam Duman Dedektorune duman veriliyor (Beklenen: Alarm CALMALI)..." << std::endl;
    smokeDet->simulateDanger(10.0f); // Güvenli
    smokeDet->simulateDanger(85.5f); // TEHLİKELİ -> Alarm Çalmalı

    // Alarm sürecini izle (Update döngüsü)
    Alarm* alarmSystem = Alarm::getInstance();
    for (int i = 0; i < 22; i++) {
        alarmSystem->update();
        sleep(1); 
    }
    
    // Alarmı sustur
    alarmSystem->silence();

    // 3. Arıza (Failure) Testi - LLR18
    std::cout << "\n[TEST] Gaz Dedektoru arizalandiriliyor..." << std::endl;
    // Arıza durumunu simüle etmek için manuel olarak durumu değiştirelim
    // Not: Device sınıfında status protected olduğu için cast edip erişebiliriz 
    // veya basitçe yeni bir FAILED testi yapabiliriz.
    // Ancak Device.h'da public bir setStatus yoksa, onu simüle etmek için powerOff deneyelim.
    // Dedektörler "Critical" olduğu için kapanmayacaktır (LLR17 testi).
    
    std::cout << "[TEST] Kritik cihaz kapatilmaya calisiliyor (LLR17)..." << std::endl;
    gasDet->powerOff(); // Uyarı vermeli, kapanmamalı.

    std::cout << "\n--- Test Tamamlandi ---" << std::endl;

    delete smokeDet;
    delete gasDet;
}

int main() {
    testScenario();
    return 0;
}