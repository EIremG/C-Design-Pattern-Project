#include "ui/HelpPages.h"
#include <iostream>

void HelpPages::showAbout() {
    std::cout
        << "=== MY SWEET HOME (MSH) ===\n"
        << "Konsol tabanli akilli ev yonetim paneli.\n"
        << "C++98 + CMake + Design Patterns.\n"
        << "\nModuller:\n"
        << "1) Devices (Show)\n"
        << "2) Add Device\n"
        << "3) Remove Device\n"
        << "4) Change Mode\n"
        << "5) Previous State\n"
        << "6) Simulate Scenario\n"
        << "7) Exit\n";
}

void HelpPages::showManual() {
    std::cout
        << "=== MANUAL ===\n"
        << "- Menuden 1-7 arasinda secim yap.\n"
        << "- Add Device: cihaz tipini sec, gerekli config sorularini cevapla.\n"
        << "- Remove Device: silinecek cihaz ID gir.\n"
        << "- Change Mode: Normal/Evening/Party/Cinema.\n"
        << "- Previous State: bir onceki duruma doner.\n"
        << "- Simulate Scenario: motion/alarm/failure gibi eventleri demo eder.\n"
        << "\nNot: Gecersiz girislerde sistem tekrar sorar.\n";
}
