#include "ui/Input.h"
#include <iostream>

static bool isSpace(char c) { return c == ' ' || c == '\t' || c == '\r' || c == '\n'; }
static bool isDigit(char c) { return c >= '0' && c <= '9'; }

bool Input::parseInt(const std::string& s, int& out) {
    int i = 0;
    while (i < (int)s.size() && isSpace(s[i])) i++;

    int sign = 1;
    if (i < (int)s.size() && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    if (i >= (int)s.size() || !isDigit(s[i])) return false;

    long val = 0;
    while (i < (int)s.size() && isDigit(s[i])) {
        val = val * 10 + (s[i] - '0');
        i++;
    }

    while (i < (int)s.size() && isSpace(s[i])) i++;
    if (i != (int)s.size()) return false; // trailing junk

    out = (int)(val * sign);
    return true;
}

int Input::readIntInRange(const char* prompt, int minVal, int maxVal) {
    std::string line;
    int v = 0;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        if (!parseInt(line, v)) {
            std::cout << "[HATA] Sayi gir.\n";
            continue;
        }
        if (v < minVal || v > maxVal) {
            std::cout << "[HATA] Aralik disi (" << minVal << "-" << maxVal << ").\n";
            continue;
        }
        return v;
    }
}

void Input::readLine(const char* prompt, std::string& out) {
    std::cout << prompt;
    std::getline(std::cin, out);
}
