#ifndef INPUT_H
#define INPUT_H

#include <string>

namespace Input {
    bool readLine(std::string& out);
    bool parseInt(const std::string& s, int& out);
    int  readIntInRange(const char* prompt, int minV, int maxV);
}

#endif
