#include <iostream>
#include <thread>
#include <chrono>

#include "alarm/AlarmDevice.h"
#include "alarm/DetectorFactory.h"

// Menü 6'dan çağıracağımız demo:
void runAlarmDemoScenario() {
    std::cout << "--- Sencer (Developer E) Demo Scenario ---" << std::endl;

    Detector* smokeDet = DetectorFactory::createDetector(SMOKE_DETECTOR, 101);
    Detector* gasDet = DetectorFactory::createDetector(GAS_DETECTOR, 102);

    smokeDet->powerOn();
    gasDet->powerOn();

    std::cout << "\n[TEST] Smoke detector danger simulation...\n";
    smokeDet->simulateDanger(10.0f);
    smokeDet->simulateDanger(85.5f);

    Alarm* alarmSystem = Alarm::getInstance();

    // Çok uzun bekletmeyelim; hızlı demo:
    for (int i = 0; i < 10; i++) {
        alarmSystem->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    alarmSystem->silence();

    std::cout << "\n[TEST] Critical device powerOff attempt (LLR17) ...\n";
    gasDet->powerOff();

    std::cout << "\n--- Alarm Demo Finished ---" << std::endl;

    delete smokeDet;
    delete gasDet;
}
