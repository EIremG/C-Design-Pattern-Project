#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

enum class LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    CRITICAL = 3,
    ERROR = 3
};

class Logger {
private:
    static Logger* instance;
    std::ofstream logFile;
    bool fileLogging;

    Logger();

    std::string getCurrentTimestamp();
    std::string logLevelToString(LogLevel level);

public:
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

    static Logger* getInstance();

    void log(LogLevel level, const std::string& message);
    void enableFileLogging(const std::string& filename);
    void disableFileLogging();

    ~Logger();
};