#pragma once

class DeviceIdGenerator {
private:
    static DeviceIdGenerator* instance;
    int currentId;

    DeviceIdGenerator() : currentId(0) {}  // private constructor

public:
    static DeviceIdGenerator* getInstance();
    int getNextId();
    void reset();  // test için
};