// main.cpp
// Developer G - Kübra Akpınar
// MSH Logging & Notification Module
// LLR6, LLR7, LLR8, LLR19, LLR30, LLR36
// Design Patterns: Singleton + Factory Method + Strategy Pattern

#include <iostream>
#include <string>
#include "Logger.h"
#include "LogFormatter.h"
#include "LogFormatterFactory.h"
#include "NotificationManager.h"

using namespace std;

void testBasicScenario() {
    cout << "\n========================================" << endl;
    cout << "   BASIC SCENARIO TEST" << endl;
    cout << "========================================\n" << endl;

    /* ================================
       LLR8: Log format seçimi
       ================================ */
    cout << "[STEP 1] Select log format (json / xml / yaml): ";
    string logFormat;
    cin >> logFormat;

    LogFormatter* formatter = LogFormatterFactory::createFormatter(logFormat);
    if (formatter == NULL) {
        cout << "[WARN] Invalid format. Defaulting to JSON.\n";
        logFormat = "json";
        formatter = LogFormatterFactory::createFormatter("json");
    }

    Logger::getInstance()->initialize("msh_log.txt", formatter);

    /* ================================
       LLR36: Notification tercihi
       ================================ */
    cout << "\n[STEP 2] Select notification method (console / sms / email / alarm): ";
    string notifMethod;
    cin >> notifMethod;

    NotificationManager notifManager;
    notifManager.setNotificationMethod(notifMethod);

    if (notifMethod != "console" &&
        notifMethod != "sms" &&
        notifMethod != "email" &&
        notifMethod != "alarm") {
        cout << "[WARN] Invalid notification method. Defaulting to console.\n";
        notifManager.setNotificationMethod("console");
    }

    /* ================================
       LLR30: İşlem loglama
       ================================ */
    cout << "\n[STEP 3] Logging operations..." << endl;
    Logger::getInstance()->logAction("2025-12-12 14:00:00", "TurnOnLight", 101);
    Logger::getInstance()->logAction("2025-12-12 14:01:00", "OpenDoor", 202);
    Logger::getInstance()->logAction("2025-12-12 14:02:00", "StartHeater_FAILED", 303);

    /* ================================
       LLR19: Arıza bildirimi
       ================================ */
    cout << "\n[STEP 4] Sending failure notification..." << endl;
    notifManager.notify("Device 303 overheating detected");

    /* ================================
       LLR7: Log kapatma
       ================================ */
    cout << "\n[STEP 5] Closing logger..." << endl;
    Logger::getInstance()->close();

    cout << "\n========================================" << endl;
    cout << "  Basic scenario completed successfully!" << endl;
    cout << "========================================\n" << endl;
}

void showMenu() {
    cout << "\n========================================" << endl;
    cout << "   MSH LOGGING & NOTIFICATION SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "1. Run Basic Scenario" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Select option: ";
}

int main() {
    cout << "==================================================" << endl;
    cout << "  MSH Logging & Notification Module" << endl;
    cout << "  Developer G - Kubra Akpinar (220206032)" << endl;
    cout << "==================================================" << endl;
    cout << "\nDesign Patterns Used:" << endl;
    cout << " - Singleton Pattern (Logger)" << endl;
    cout << " - Factory Method Pattern (Formatter & Notification)" << endl;
    cout << " - Strategy Pattern (LogFormatter, Notification)" << endl;
    cout << "==================================================" << endl;

    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            testBasicScenario();
        } else if (choice == 0) {
            cout << "\nExiting program. Goodbye!" << endl;
            break;
        } else {
            cout << "\nInvalid option. Try again." << endl;
        }
    }

    return 0;
}
