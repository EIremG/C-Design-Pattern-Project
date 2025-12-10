#include "DeviceIdGenerator.h"

DeviceIdGenerator* DeviceIdGenerator::instance = nullptr;

DeviceIdGenerator* DeviceIdGenerator::getInstance() {
    if (instance == nullptr) {
        instance = new DeviceIdGenerator();
    }
    return instance;
}

int DeviceIdGenerator::getNextId() {
    return ++currentId;
}

void DeviceIdGenerator::reset() {
    currentId = 0;
}