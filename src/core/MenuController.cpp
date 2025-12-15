#include "core/MenuController.h"
#include <iostream>

void MenuController::showMainMenu() const {
    std::cout << "\n===== MY SWEET HOME (MSH) =====\n";
    std::cout << "1) Show devices\n";
    std::cout << "2) Add device\n";
    std::cout << "3) Remove device\n";
    std::cout << "4) Change mode (Normal/Evening/Party/Cinema)\n";
    std::cout << "5) Previous state\n";
    std::cout << "6) Simulate scenario\n";
    std::cout << "7) Exit\n";
    std::cout << "==============================\n";
}

void MenuController::showAfterActionPause() const {
    std::cout << "\nPress ENTER to continue...";
}
