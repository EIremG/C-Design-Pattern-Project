// main.cpp
// Developer G - Kübra Akpınar
// MSH Logging & Notification Module - Test Program

#include <iostream>
#include <string>
#include "Logger.h"
#include "LogFormatter.h"
#include "LogFormatterFactory.h"
#include "NotificationManager.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "  MSH Logging & Notification Test" << endl;
    cout << "  Developer G - Kubra Akpinar" << endl;
    cout << "========================================\n" << endl;
    
    // STEP 1: Logger baslatma (LLR6, LLR8)
    cout << "[STEP 1] Initializing Logger with JSON format..." << endl;
    LogFormatter* format = LogFormatterFactory::createFormatter("json");
    Logger::getInstance()->initialize("msh_log.txt", format);
    
    // STEP 2: Notification Manager kurulum (LLR36)
    cout << "[STEP 2] Setting up Notification Manager..." << endl;
    NotificationManager notifManager;
    notifManager.setNotificationMethod("console");
    
    // STEP 3: Basarili islem loglari (LLR30)
    cout << "[STEP 3] Logging successful operations..." << endl;
    Logger::getInstance()->logAction("2025-12-12 14:00:00", "TurnOnLight", 101);
    Logger::getInstance()->logAction("2025-12-12 14:01:00", "OpenDoor", 202);
    
    // STEP 4: Basarisiz islem ornegi (LLR30)
    cout << "[STEP 4] Logging error example..." << endl;
    Logger::getInstance()->logAction("2025-12-12 14:02:00", "StartHeater_FAILED", 303);
    
    // STEP 5: Cihaz arizasi bildirimi (LLR19)
    cout << "[STEP 5] Sending device failure notification..." << endl;
    notifManager.notify("Device 303 overheating detected");
    
    // STEP 6: Log dosyasini kapat (LLR7)
    cout << "[STEP 6] Closing log file..." << endl;
    Logger::getInstance()->close();
    
    cout << "\n========================================" << endl;
    cout << "  Program completed successfully!" << endl;
    cout << "  Check 'msh_log.txt' for logs." << endl;
    cout << "========================================" << endl;
    
    return 0;
}   