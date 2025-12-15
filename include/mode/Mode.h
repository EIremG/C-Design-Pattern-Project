#ifndef MODE_H
#define MODE_H

enum Mode
{
    MODE_NORMAL = 0,
    MODE_EVENING,
    MODE_PARTY,
    MODE_CINEMA
};

inline const char* modeToString(Mode m)
{
    switch (m)
    {
    case MODE_NORMAL:  return "NORMAL";
    case MODE_EVENING: return "EVENING";
    case MODE_PARTY:   return "PARTY";
    case MODE_CINEMA:  return "CINEMA";
    default:           return "UNKNOWN";
    }
}

#endif
#pragma once
