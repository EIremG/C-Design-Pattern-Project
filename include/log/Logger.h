// Logger.h
// Developer G - Kübra Akpınar
// LLR6, LLR7, LLR30: Log dosyası yönetimi ve işlem loglama
// Pattern: Singleton

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class LogFormatter;

class Logger {
private:
    static Logger* instance;
    LogFormatter* formatter;
    std::ofstream logFile;
    std::string filename;
    bool isInitialized;

    Logger();
    Logger(const Logger&);
    Logger& operator=(const Logger&);

    std::string getCurrentTimestamp() const;

public:
    static Logger* getInstance();

    // C4458 fix: parametre adı filename değil -> logFilename
    bool initialize(const std::string& logFilename, LogFormatter* fmt);

    void log(const std::string& message);

    void logAction(const std::string& timestamp,
                   const std::string& action,
                   int deviceId);

    void close();
    bool isReady() const;

    ~Logger();
};

#endif


