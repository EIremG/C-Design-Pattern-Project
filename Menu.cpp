#include "Menu.h"
#include "../devices/Light.h"
#include "../devices/TV.h"
#include "Configurator.h"
#include <iostream>

void Menu::run(DeviceManager& dm) {
    int choice = 0;

    while (true) {
        std::cout << "\n1) Add Light\n2) Add TV\n3) List Devices\n4) Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            Light* l = new Light(dm.list().size() + 1, "Light");
            Configurator::configureLight(l);
            dm.add(l);
        }
        else if (choice == 2) {
            TV* t = new TV(dm.list().size() + 1, "TV");
            Configurator::configureTV(t);
            dm.add(t);
        }
        else if (choice == 3) {
            dm.list();
        }
        else if (choice == 4) {
            break;
        }
    }
}
