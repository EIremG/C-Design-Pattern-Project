#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <string>

class Input {
public:
    static bool parseInt(const std::string& s, int& out);
    static int  readIntInRange(const char* prompt, int minVal, int maxVal);
    static void readLine(const char* prompt, std::string& out);
};

#endif
