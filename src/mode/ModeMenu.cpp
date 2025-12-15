#include <iostream>
#include "core/Input.h"
#include "mode/ModeManager.h"
#include "mode/MockDeviceManager.h"
#include "mode/Mode.h"

// Bu fonksiyon menüden çağrılacak:
void runModeMenu(ModeManager& modeManager, MockDeviceManager& deviceManager)
{
    int choice = -1;
    while (choice != 0)
    {
        std::cout << "\n--- MODE MENU ---\n";
        std::cout << "1 - NORMAL\n";
        std::cout << "2 - EVENING\n";
        std::cout << "3 - PARTY\n";
        std::cout << "4 - CINEMA\n";
        std::cout << "5 - PREVIOUS\n";
        std::cout << "0 - EXIT\n";

        choice = Input::readIntInRange("Choice (0-5): ", 0, 5);

        switch (choice)
        {
        case 1: modeManager.setMode(MODE_NORMAL); break;
        case 2: modeManager.setMode(MODE_EVENING); break;
        case 3: modeManager.setMode(MODE_PARTY); break;
        case 4: modeManager.setMode(MODE_CINEMA); break;
        case 5:
            if (!modeManager.previousState())
                std::cout << "No previous state!\n";
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
        }

        deviceManager.printStatus();
    }
}
