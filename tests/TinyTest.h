#ifndef TINYTEST_H
#define TINYTEST_H

#include <iostream>
#include <fstream>
#include <string>

struct TinyTest {
    int passed, failed;
    std::ofstream log;

    TinyTest(const char* logFile) : passed(0), failed(0), log(logFile, std::ios::app) {}

    void expectTrue(bool cond, const std::string& name) {
        if (cond) {
            ++passed;
        }
        else {
            ++failed;
            std::cout << "[FAIL] " << name << "\n";
        }
    }

    int report() {
        std::cout << "[TEST] Passed: " << passed << " Failed: " << failed << "\n";

        // LLR39 "loglama" için basit dosya log’u (şimdilik)
        if (log.is_open()) {
            log << "Passed=" << passed << " Failed=" << failed << "\n";
        }
        return failed == 0 ? 0 : 1;
    }
};

#endif
