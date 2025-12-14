# SmartHome Device Framework - Device Core
**Developer B (İrem)** tarafından geliştirilen Akıllı Ev Cihaz Yönetim Sistemi.

## Proje Açıklaması
Bu proje, akıllı ev cihazlarını yönetmek için tasarlanmış nesne yönelimli bir C++ framework'üdür. Singleton, Factory, Prototype ve Observer tasarım kalıplarını kullanır.

## Gereksinimler
- CMake 3.10 veya üzeri
- C++17 destekleyen derleyici (g++, clang++, MSVC)

## Derleme ve Çalıştırma

### Linux / macOS
```bash
# Proje klasörüne git
cd SmartHome

# Build klasörü oluştur
mkdir build
cd build

# CMake ile yapılandır
cmake ..

# Derle
make -j4

# Çalıştır
./SmartHome
```

### Windows (Visual Studio)
```bash
# Proje klasörüne git
cd SmartHome

# Build klasörü oluştur
mkdir build
cd build

# CMake ile yapılandır
cmake ..

# Derle
cmake --build .

# Çalıştır
.\Debug\SmartHome.exe
```

### Windows (VS Code)
1. CMake Tools eklentisini yükle
2. Projeyi aç
3. `Ctrl+Shift+P` → "CMake: Configure" seç
4. `Ctrl+Shift+P` → "CMake: Build" seç
5. `Ctrl+Shift+P` → "CMake: Run Without Debugging" seç

## Proje Yapısı
```
SmartHome/
│
├── CMakeLists.txt                 # CMake yapılandırma dosyası
│
├── include/                       # Header dosyaları (.h)
│   ├── Alarm.h                    # Alarm sınıfı (Singleton + Subject)
│   ├── Camera.h                   # Kamera cihazı
│   ├── CriticalDeviceGuard.h      # Kritik cihaz koruma sınıfı
│   ├── Detector.h                 # Dedektör abstract sınıfı
│   ├── DetectorFactory.h          # Dedektör fabrikası (Factory)
│   ├── Device.h                   # Device temel sınıfı
│   ├── DeviceFactory.h            # Cihaz fabrikası (Factory Method)
│   ├── DeviceManager.h            # Cihaz yöneticisi (Singleton)
│   ├── GasDetector.h              # Gaz dedektörü
│   ├── Light.h                    # Işık cihazı (Observer)
│   ├── Logger.h                   # Loglama sistemi (Singleton)
│   ├── MusicSystem.h              # Müzik sistemi
│   ├── Observer.h                 # Observer interface
│   ├── SmokeDetector.h            # Duman dedektörü
│   ├── Subject.h                  # Subject (Observable) interface
│   └── TV.h                       # Televizyon cihazı
│
├── src/                           # Kaynak dosyaları (.cpp)
│   ├── Alarm.cpp
│   ├── Camera.cpp
│   ├── CriticalDeviceGuard.cpp
│   ├── Detector.cpp
│   ├── DetectorFactory.cpp
│   ├── Device.cpp
│   ├── DeviceFactory.cpp
│   ├── DeviceManager.cpp
│   ├── GasDetector.cpp
│   ├── Light.cpp
│   ├── Logger.cpp
│   ├── main.cpp
│   ├── MusicSystem.cpp
│   ├── SmokeDetector.cpp
│   └── TV.cpp
│
└── build/                         # Derleme çıktıları
    └── Debug/
        └── SmartHome.exe
```

## Uygulanan LLR Gereksinimleri

| LLR    | Açıklama                                      | Durum |
|--------|-----------------------------------------------|-------|
| LLR9   | Device temel sınıfı (name, id, powerState, type) | ✅ |
| LLR10  | DeviceManager singleton                       | ✅ |
| LLR11  | powerOn()/powerOff() metodları                | ✅ |
| LLR12  | Detector + DetectorFactory                    | ✅ |
| LLR13  | Alarm singleton implementasyonu               | ✅ |
| LLR15  | Prototype pattern ile cihaz kopyalama         | ✅ |
| LLR16  | Cihaz ekleme/çıkarma/id ile referans          | ✅ |
| LLR17  | Kritik cihazlar powerOff yapılamaz            | ✅ |
| LLR32  | Cihaz listesi (id + isim + durum)             | ✅ |
| LLR33  | TV model seçimi (Samsung/LG/Sony)             | ✅ |
| LLR34  | Kamera: motionDetection, FPS, nightVision     | ✅ |
| LLR35  | Light: name, color, illumination              | ✅ |
| LLR37  | ID otomatik artan sıra mekanizması            | ✅ |

## Kullanılan Tasarım Kalıpları

1. **Singleton Pattern**: Alarm, Logger, DeviceManager
2. **Factory Method Pattern**: DeviceFactory
3. **Factory Pattern**: DetectorFactory
4. **Prototype Pattern**: Device::clone()
5. **Observer Pattern**: Alarm (Subject) → Lights (Observers)

### Observer Pattern Örneği
```cpp
// Alarm tetiklendiğinde, tüm kayıtlı ışıklar otomatik olarak bilgilendirilir
Alarm* alarm = Alarm::getInstance();
Light* light = new Light("Living Room");

alarm->attach(light);  // Light'ı observer olarak kaydet
alarm->trigger("Fire detected!");  // Tüm observer'lar bilgilendirilir
// Light otomatik olarak kırmızıya döner ve tam parlaklıkta açılır
```

## SOLID Prensipleri

- **S - Single Responsibility**: Her sınıf tek bir sorumluluğa sahip
- **O - Open/Closed**: Yeni cihaz tipleri eklenebilir (mevcut kod değişmeden)
- **L - Liskov Substitution**: Alt sınıflar üst sınıfların yerine kullanılabilir
- **I - Interface Segregation**: Arayüzler küçük ve özelleştirilmiş
- **D - Dependency Inversion**: Üst seviye modüller soyutlamalara bağımlı

## Test Çıktısı

Program çalıştırıldığında 11 farklı test otomatik olarak çalışır:

1. ✅ Device Creation & Factory (LLR9, LLR37)
2. ✅ Device Listing (LLR32)
3. ✅ Device Operations (LLR11, LLR34, LLR35)
4. ✅ Prototype Pattern (LLR15)
5. ✅ Critical Device Protection (LLR17)
6. ✅ Alarm Singleton (LLR13)
7. ✅ Detector Functionality (LLR12)
8. ✅ Device Removal (LLR16)
9. ✅ ID Auto-Increment (LLR37)
10. ✅ Logger Integration
11. ✅ Observer Pattern

## Özellikler

- ✅ 10+ farklı cihaz tipi
- ✅ Kritik cihaz koruma sistemi (Alarm, Dedektörler kapatılamaz)
- ✅ Otomatik ID yönetimi
- ✅ Kapsamlı loglama sistemi
- ✅ Event-driven mimari (Observer Pattern)
- ✅ Fabrika kalıpları ile esnek cihaz üretimi
- ✅ Prototip kalıbı ile cihaz kopyalama

## Lisans

Bu proje eğitim amaçlı geliştirilmiştir.
