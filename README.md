MSH Logging & Notification Project
Developer G - Kübra Akpınar (220206033)
Course: BIL464 - Design Patterns with C++
Project: My Sweet Home (MSH) - Logging & Notification Module
Project Folder: C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject

 Proje Özeti
Bu modül, MSH (My Sweet Home) akıllı ev sisteminin logging (kayıt tutma) ve notification (bildirim) altyapısını sağlar.
Sorumluluk Alanları

LLR6: Log dosyası başlatma
LLR7: Kapanışta log dosyası kapatma
LLR8: JSON/XML/YAML log format seçimi
LLR19: Arıza bildirim sistemi
LLR30: Her işlem loglanmalı (timestamp, action, deviceId)
LLR36: Kullanıcı bildirim tercihi (Console/SMS/Email/Alarm)


 Kullanılan Design Pattern'ler
1. Singleton Pattern

Nerede: Logger sınıfı
Neden: Tüm sistem tek bir logger instance kullanmalı
Avantaj: Log tutarlılığı, merkezi kontrol

2. Factory Method Pattern

Nerede: LogFormatterFactory, NotificationFactory
Neden: Strategy nesnelerini oluşturmak için merkezi fabrika
Avantaj: Nesne yaratımını merkezileştirir, SOLID prensiplerine uygun

3. Strategy Pattern 

Nerede: LogFormatter ve Notification ailesi
Neden: Runtime'da farklı format/bildirim stratejileri seçebilmek için
Context: Logger (LogFormatter stratejilerini kullanır), NotificationManager (Notification stratejilerini kullanır)
Concrete Strategies:

LogFormatter: JSON, XML, YAML
Notification: Console, SMS, Email, Alarm


Avantaj: Davranışları runtime'da değiştirebilme, yeni strateji eklemek kolay


 Sınıf Yapısı
 Logger (Singleton) + Strategy Pattern
├── LogFormatter (Strategy Interface)
│   ├── JSONLogFormatter (Concrete Strategy)
│   ├── XMLLogFormatter (Concrete Strategy)
│   └── YAMLLogFormatter (Concrete Strategy)
└── LogFormatterFactory (Factory Method)

NotificationManager (Context) + Strategy Pattern
├── Notification (Strategy Interface)
│   ├── ConsoleNotification (Concrete Strategy)
│   ├── SMSNotification (Concrete Strategy)
│   ├── EmailNotification (Concrete Strategy) 
│   └── AlarmNotification (Concrete Strategy)
└── NotificationFactory (Factory Method)

Dosya Yapısı
C-Design-Pattern-Project/
└── DeveloperG/
    └── MSH_Kubra_LoggingProject/
        ├── include/
        │   ├── Logger.h
        │   ├── LogFormatter.h
        │   ├── LogFormatterFactory.h
        │   ├── JSONLogFormatter.h
        │   ├── XMLLogFormatter.h
        │   ├── YAMLLogFormatter.h
        │   ├── NotificationManager.h
        │   ├── Notification.h
        │   ├── NotificationFactory.h
        │   ├── ConsoleNotification.h
        │   ├── SMSNotification.h
        │   ├── EmailNotification.h 
        │   └── AlarmNotification.h
        ├── src/
        │   ├── Logger.cpp
        │   ├── LogFormatterFactory.cpp
        │   ├── JSONLogFormatter.cpp
        │   ├── XMLLogFormatter.cpp
        │   ├── YAMLLogFormatter.cpp
        │   ├── NotificationManager.cpp
        │   ├── NotificationFactory.cpp
        │   ├── ConsoleNotification.cpp
        │   ├── SMSNotification.cpp
        │   ├── EmailNotification.cpp 
        │   ├── AlarmNotification.cpp
        │   └── main.cpp
        ├── .gitignore
        ├── CMakeLists.txt
        └── README.md

Derleme ve Çalıştırma
Gereksinimler

CMake 3.10+
C++98 uyumlu derleyici (g++, clang++, MSVC)
Visual Studio Code (önerilen) veya herhangi bir IDE

Derleme Adımları
Windows (Visual Studio Code):
cd C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject
mkdir build
cd build
cmake ..
cmake --build .
.\Debug\MSH_Logging.exe

Linux/Mac:
cd C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject
mkdir build
cd build
cmake ..
make
./MSH_Logging


Test Senaryoları
Program çalıştırıldığında interaktif menü görünür:
==================================================
  MSH Logging & Notification Module
  Developer G - Kubra Akpinar (220206033)
==================================================

Design Patterns Used:
 - Singleton Pattern (Logger)
 - Factory Method Pattern (Formatter & Notification)
 - Strategy Pattern (LogFormatter, Notification)
==================================================

========================================
   MSH LOGGING & NOTIFICATION SYSTEM
========================================
1. Run Basic Scenario
0. Exit
========================================
Select option:


Test Akışı:
1. Run Basic Scenario seçildiğinde:
[STEP 1] Select log format (json / xml / yaml): yaml
[LogFormatterFactory] Creating YAML formatter
[Logger] Initialized successfully with YAML format

[STEP 2] Select notification method (console / sms / email / alarm): sms
[NotificationFactory] Creating SMS notification (simulated)
[NotificationManager] Notification method set to: SMS

[STEP 3] Logging operations...
[Logger] Logged: TurnOnLight (DeviceID: 101)
[Logger] Logged: OpenDoor (DeviceID: 202)
[Logger] Logged: StartHeater_FAILED (DeviceID: 303)

[STEP 4] Sending failure notification...
A SMS is sent: Device 303 overheating detected

[STEP 5] Closing logger...
[Logger] Log file closed: msh_log.txt



Desteklenen Format ve Bildirim Türleri:
Log Formatları (LLR8):

json - JSON formatı
xml - XML formatı
yaml - YAML formatı

Bildirim Türleri (LLR36):

console - Konsol bildirimi
sms - SMS simülasyonu (LLR19: "A SMS is sent: ...")
email - Email simülasyonu 
alarm - Alarm simülasyonu


 Log Dosyası Örnekleri
JSON Format (msh_log.txt):
=== MSH Logging System Started ===
Format: JSON
Timestamp: 2025-12-12 15:30:00
===================================
{"timestamp":"2025-12-12 14:00:00","action":"TurnOnLight","deviceId":101}
{"timestamp":"2025-12-12 14:01:00","action":"OpenDoor","deviceId":202}
{"timestamp":"2025-12-12 14:02:00","action":"StartHeater_FAILED","deviceId":303}

=== MSH Logging System Closed ===
Timestamp: 2025-12-12 15:35:00
==================================

XML Format:
=== MSH Logging System Started ===
Format: XML
===================================
<log><timestamp>2025-12-12 14:00:00</timestamp><action>TurnOnLight</action><deviceId>101</deviceId></log>
<log><timestamp>2025-12-12 14:01:00</timestamp><action>OpenDoor</action><deviceId>202</deviceId></log>

YAML Format:
=== MSH Logging System Started ===
Format: YAML
===================================
---
timestamp: "2025-12-12 14:00:00"
action: "TurnOnLight"
deviceId: 101
---
timestamp: "2025-12-12 14:01:00"
action: "OpenDoor"
deviceId: 202


SOLID Prensipleri

 Single Responsibility Principle
Her sınıf tek bir sorumluluk üstlenir:

Logger: Sadece log yönetimi
LogFormatter: Sadece formatlama
NotificationManager: Sadece bildirim yönetimi

 Open/Closed Principle
Yeni format veya bildirim türü eklemek için mevcut kodu değiştirmeyiz:

Yeni LogFormatter türevi ekle
Factory'ye bir satır ekle → Mevcut kod değişmez

 Liskov Substitution Principle
Türev sınıflar, base sınıfın yerine geçebilir:

Tüm LogFormatter türevleri birbirinin yerine kullanılabilir
Tüm Notification türevleri birbirinin yerine kullanılabilir

 Interface Segregation Principle
Minimal ve özel amaçlı interface'ler:

LogFormatter: Sadece format() ve getFormatType()
Notification: Sadece send() ve getType()

 Dependency Inversion Principle
Concrete sınıflara değil, abstract sınıflara bağımlılık:

Logger → LogFormatter* (abstract)
NotificationManager → Notification* (abstract)


Diğer Modüllerle Entegrasyon
Logger Kullanımı (Diğer Developer'lar için):
#include "Logger.h"
#include "LogFormatterFactory.h"

// Başlatma (main'de bir kez)
LogFormatter* fmt = LogFormatterFactory::createFormatter("json");
Logger::getInstance()->initialize("system.log", fmt);

// Kullanım (her yerden)
Logger::getInstance()->logAction("2025-12-12 15:00:00", "DeviceAdded", 42);

// Kapanış (shutdown'da)
Logger::getInstance()->close();

NotificationManager Kullanımı:
#include "NotificationManager.h"

NotificationManager notifMgr;
notifMgr.setNotificationMethod("sms");  // veya "console", "email", "alarm"

// Arıza durumunda
notifMgr.notify("Device 5 failed!");
// Çıktı: A SMS is sent: Device 5 failed!



Bilinen Kısıtlamalar

Thread-safety: Singleton tam thread-safe değil (C++98 kısıtı)
Log rotation: Desteklenmez (manuel temizlik gerekir)
Gerçek SMS/Email: Simülasyon (konsol çıktısı)
Dosya yolu: Çalıştırıldığı dizinde log oluşturur


Entegrasyon Notu:
Diğer developer'lar Logger veya NotificationManager'ı kullanırken:

Header dosyalarını include edin
CMakeLists.txt'nize bağımlılık ekleyin
Örnek kullanımlar için main.cpp'ye bakın


LLR Karşılama Durumu
LLR6 (Log başlatma) -> Logger::initialize()
LLR7 (Log kapatma) -> Logger::close()
LLR8 (Format seçimi) -> Factory + JSON/XML/YAML
LLR19 (Arıza bildirimi) -> NotificationManager::notify()
LLR30 (İşlem loglama) -> Logger::logAction()
LLR36 (Bildirim tercihi) -> setNotificationMethod()


Commit Geçmişi
Tüm geliştirme süreci Git ile takip edilmiştir. Commit geçmişini görmek için:
git log --oneline --author="Kubra" --graph

