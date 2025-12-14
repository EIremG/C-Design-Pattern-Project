#include "TV.h"
#include <iostream>

TV::TV(int id, const std::string& name)
    : Device(id, name, "TV"), model("Unknown") {}

void TV::setModel(const std::string& m) { model = m; }

void TV::powerOn() { powerState = true; }
void TV::powerOff() { powerState = false; }

void TV::printDetails() const {
    std::cout << "   Model: " << model << "\n";
}
