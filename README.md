# SmartHome Device Framework - Device Core

**Developer B (İrem)** tarafından geliştirilen Akıllı Ev Cihaz Yönetim Sistemi.

## Proje Açıklaması

Bu proje, akıllı ev cihazlarını yönetmek için tasarlanmış nesne yönelimli bir C++ framework'üdür. Factory, Singleton, Prototype tasarım kalıplarını kullanır.

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

```powershell
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
│   ├── Alarm.h                    # Alarm sınıfı (Singleton)
│   ├── Camera.h                   # Kamera cihazı
│   ├── CriticalDeviceGuard.h      # Kritik cihaz koruma sınıfı
│   ├── Detector.h                 # Dedektör abstract sınıfı
│   ├── DetectorFactory.h          # Dedektör fabrikası (Abstract Factory)
│   ├── Device.h                   # Device temel sınıfı
│   ├── DeviceFactory.h            # Cihaz fabrikası (Factory Method)
│   ├── DeviceManager.h            # Cihaz yöneticisi (Singleton)
│   ├── GasDetector.h              # Gaz dedektörü
│   ├── Light.h                    # Işık cihazı
│   ├── Logger.h                   # Loglama sistemi (Singleton)
│   ├── MusicSystem.h              # Müzik sistemi
│   ├── SmokeDetector.h            # Duman dedektörü
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

| LLR | Açıklama | Durum |
|-----|----------|-------|
| LLR9 | Device temel sınıfı (name, id, powerState, type) | ✅ |
| LLR11 | powerOn()/powerOff() metodları | ✅ |
| LLR12 | Detector + DetectorFactory (Abstract Factory) | ✅ |
| LLR13 | Alarm singleton implementasyonu | ✅ |
| LLR15 | Prototype pattern ile cihaz kopyalama | ✅ |
| LLR16 | Cihaz ekleme/çıkarma/id ile referans | ✅ |
| LLR17 | Kritik cihazlar powerOff yapılamaz | ✅ |
| LLR32 | Cihaz listesi (id + isim + durum) | ✅ |
| LLR33 | TV model seçimi (Samsung/LG) | ✅ |
| LLR34 | Kamera: motionDetection, FPS, nightVision | ✅ |
| LLR35 | Light: name, color, illumination | ✅ |
| LLR37 | ID otomatik artan sıra mekanizması | ✅ |

## Kullanılan Tasarım Kalıpları

- **Singleton**: Alarm, Logger, DeviceManager
- **Factory Method**: DeviceFactory
- **Abstract Factory**: DetectorFactory
- **Prototype**: Device::clone()

## SOLID Prensipleri

- **S** - Single Responsibility: Her sınıf tek bir sorumluluğa sahip
- **O** - Open/Closed: Yeni cihaz tipleri eklenebilir
- **L** - Liskov Substitution: Alt sınıflar üst sınıfların yerine kullanılabilir
- **I** - Interface Segregation: Arayüzler küçük ve özelleştirilmiş
- **D** - Dependency Inversion: Üst seviye modüller alt seviyeye bağımlı değil

## Test Çıktısı

Program çalıştırıldığında 10 farklı test otomatik olarak çalışır:

1. Device Creation & Factory (LLR9, LLR37)
2. Device Listing (LLR32)
3. Device Operations (LLR11, LLR34, LLR35)
4. Prototype Pattern (LLR15)
5. Critical Device Protection (LLR17)
6. Alarm Singleton (LLR13)
7. Detector Functionality (LLR12)
8. Device Removal (LLR16)
9. ID Auto-Increment (LLR37)
10. Logger Integration

## Lisans

Bu proje eğitim amaçlı geliştirilmiştir.
