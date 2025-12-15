#include "core/Input.h"
#include <iostream>
#include <sstream>

namespace Input {

    bool readLine(std::string& out) {
        out.clear();
        if (!std::getline(std::cin, out)) return false;
        return true;
    }

    bool parseInt(const std::string& s, int& out) {
        std::istringstream iss(s);
        iss >> out;
        if (!iss) return false;

        char c;
        if (iss >> c) return false; // "12abc" gibi trailing varsa reddet
        return true;
    }

    int readIntInRange(const char* prompt, int minV, int maxV) {
        while (true) {
            std::cout << prompt;

            std::string line;
            if (!readLine(line)) {
                std::cout << "\n[WARN] Input ended. Exiting...\n";
                return maxV; // Exit seçeneği
            }

            int v = 0;
            if (!parseInt(line, v)) {
                std::cout << "[ERROR] Invalid input. Please enter a number.\n";
                continue;
            }

            if (v < minV || v > maxV) {
                std::cout << "[ERROR] Out of range (" << minV << "-" << maxV << "). Try again.\n";
                continue;
            }

            return v;
        }
    }

} // namespace Input
