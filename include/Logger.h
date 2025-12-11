#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    DEBUG
};

// Singleton Logger (LLR11)
// Single Responsibility: Logging operations
class Logger {
private:
    static Logger* instance;
    std::ofstream logFile;
    bool fileLogging;
    
    // Private constructor (Singleton pattern)
    Logger();
    
    // Delete copy constructor and assignment operator
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    std::string getCurrentTimestamp();
    std::string logLevelToString(LogLevel level);
    
public:
    static Logger* getInstance();
    
    void log(LogLevel level, const std::string& message);
    void enableFileLogging(const std::string& filename);
    void disableFileLogging();
    
    ~Logger();
};