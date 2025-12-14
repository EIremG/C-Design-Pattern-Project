#include <iostream>
#include "core/DeviceManager.h"
#include "ui/Menu.h"

int main() {
    DeviceManager dm;
    Menu::run(dm);
    return 0;
}
