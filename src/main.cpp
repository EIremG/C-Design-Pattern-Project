#include "core/Console.h"
#include "ui/HelpPages.h"
#include "ui/DeviceUI.h"
#include <iostream>

int main() {
    Console::clear();

    HelpPages::showAbout();
    std::cout << "\n";
    HelpPages::showManual();

    Console::pause();
    Console::clear();

    // Add flow test
    DeviceAddRequest req = DeviceUI::promptAddRequest();

    std::cout << "\n[DEVH TEST] Add request captured:\n";
    std::cout << "Type: " << (int)req.type << "\n";
    std::cout << "Name: " << req.name << "\n";
    std::cout << "Clone: " << (req.cloneFromExisting ? "yes" : "no") << "\n";
    if (req.cloneFromExisting) std::cout << "Clone source id: " << req.cloneSourceId << "\n";

    if (req.type == UI_LIGHT) {
        std::cout << "Light color: " << req.lightColor << "\n";
        std::cout << "Light illum: " << req.lightIllumination << "\n";
    }
    if (req.type == UI_TV) {
        std::cout << "TV model: " << req.tvModel << "\n";
    }

    Console::pause();
    Console::clear();

    // Remove flow test
    int id = DeviceUI::promptRemoveId();
    std::cout << "\n[DEVH TEST] Remove id captured: " << id << "\n";

    Console::pause();
    return 0;
}
