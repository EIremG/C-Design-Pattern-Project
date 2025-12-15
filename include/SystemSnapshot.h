#ifndef SYSTEM_SNAPSHOT_H
#define SYSTEM_SNAPSHOT_H

#include <map>
#include "Mode.h"

struct SystemSnapshot
{
    SystemSnapshot() : mode(MODE_NORMAL) {}

    Mode mode;
    std::map<int, bool> devicePower; // deviceId -> on/off
};

#endif
