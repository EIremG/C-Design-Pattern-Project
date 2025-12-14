#include "Configurator.h"
#include <iostream>

void Configurator::configureLight(Light* l) {
    std::string color;
    int illum;

    std::cout << "Color: ";
    std::cin >> color;
    std::cout << "Illumination (0-100): ";
    std::cin >> illum;

    l->setColor(color);
    l->setIllumination(illum);
}

void Configurator::configureTV(TV* t) {
    int c;
    std::cout << "Select model:\n1) Samsung\n2) LG\nChoice: ";
    std::cin >> c;

    if (c == 1) t->setModel("Samsung");
    else if (c == 2) t->setModel("LG");
    else t->setModel("Unknown");
}
