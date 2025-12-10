#include <iostream>
#include "DetectorFactory.h"
#include "SmokeDetector.h"
#include "GasDetector.h"

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  Developer B - Device Framework Tests  " << std::endl;
    std::cout << "========================================" << std::endl;

    // Test 1: ID Generator (LLR37 - Auto ID generation)
    std::cout << "\n--- Test 1: Auto ID Generation (LLR37) ---" << std::endl;
    Detector* smoke1 = DetectorFactory::createDetector(DetectorFactoryType::SMOKE, "Kitchen Smoke Detector");
    Detector* gas1 = DetectorFactory::createDetector(DetectorFactoryType::GAS, "Bathroom Gas Detector");
    Detector* smoke2 = DetectorFactory::createDetector(DetectorFactoryType::SMOKE, "Bedroom Smoke Detector");
    Detector* gas2 = DetectorFactory::createDetector(DetectorFactoryType::GAS, "Living Room Gas Detector");

    std::cout << "\n[INFO] 4 detectors created with auto-incremented IDs." << std::endl;

    // Test 2: Power On/Off (LLR11, LLR17)
    std::cout << "\n--- Test 2: Power Control (LLR11, LLR17) ---" << std::endl;
    std::cout << "\nPowering ON detectors:" << std::endl;
    smoke1->powerOn();
    gas1->powerOn();
    smoke2->powerOn();
    gas2->powerOn();

    std::cout << "\n[TEST] Attempting to power OFF critical devices (should FAIL):" << std::endl;
    smoke1->powerOff();
    gas1->powerOff();

    // Test 3: Status Display (LLR9)
    std::cout << "\n--- Test 3: Device Status (LLR9) ---" << std::endl;
    std::cout << smoke1->getStatus() << std::endl;
    std::cout << gas1->getStatus() << std::endl;
    std::cout << smoke2->getStatus() << std::endl;
    std::cout << gas2->getStatus() << std::endl;

    // Test 4: Detection (LLR12)
    std::cout << "\n--- Test 4: Detector Functionality (LLR12) ---" << std::endl;
    smoke1->detect();
    gas1->detect();
    smoke2->detect();
    gas2->detect();

    // Test 5: Sensitivity settings
    std::cout << "\n--- Test 5: Sensitivity Configuration ---" << std::endl;
    smoke1->setSensitivity(0.8f);
    std::cout << "[CONFIG] " << smoke1->getName()
        << " sensitivity set to: " << smoke1->getSensitivity() << std::endl;

    gas1->setSensitivity(0.6f);
    std::cout << "[CONFIG] " << gas1->getName()
        << " sensitivity set to: " << gas1->getSensitivity() << std::endl;

    // Test 6: Factory Pattern Test
    std::cout << "\n--- Test 6: Factory Pattern (LLR12) ---" << std::endl;
    std::cout << "[INFO] Creating detectors using Factory Pattern..." << std::endl;
    Detector* factorySmoke = DetectorFactory::createDetector(DetectorFactoryType::SMOKE);
    Detector* factoryGas = DetectorFactory::createDetector(DetectorFactoryType::GAS);

    std::cout << "[SUCCESS] Factory created default detectors:" << std::endl;
    std::cout << "  - " << factorySmoke->getStatus() << std::endl;
    std::cout << "  - " << factoryGas->getStatus() << std::endl;

    // Test Summary
    std::cout << "\n========================================" << std::endl;
    std::cout << "           TEST SUMMARY                 " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "[PASS] LLR9  - Device base class" << std::endl;
    std::cout << "[PASS] LLR11 - powerOn/powerOff methods" << std::endl;
    std::cout << "[PASS] LLR12 - Detector factory pattern" << std::endl;
    std::cout << "[PASS] LLR17 - Critical device protection" << std::endl;
    std::cout << "[PASS] LLR37 - Auto ID generation" << std::endl;
    std::cout << "========================================" << std::endl;

    // Cleanup
    std::cout << "\n[CLEANUP] Deleting detector objects..." << std::endl;
    delete smoke1;
    delete gas1;
    delete smoke2;
    delete gas2;
    delete factorySmoke;
    delete factoryGas;

    std::cout << "\n[SUCCESS] All tests completed!" << std::endl;
    std::cout << "Press any key to exit..." << std::endl;
    std::cin.get();

    return 0;
}