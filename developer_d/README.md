# Developer D - Camera + Motion System

## Proje Yapısı

```
developer_d/
├── include/              # Header dosyaları (.h)
│   ├── EventType.h
│   ├── Device.h
│   ├── Event.h
│   ├── MotionEvent.h
│   ├── AlarmEvent.h
│   ├── DeviceFailureEvent.h
│   ├── EventObserver.h
│   ├── EventQueue.h
│   ├── EventObjectPool.h
│   ├── EventDispatcher.h
│   ├── Camera.h
│   ├── CameraBuilder.h
│   ├── SecuritySystem.h
│   ├── DeviceManager.h
│   └── DebugSimulator.h
├── src/                  # Kaynak dosyaları (.cpp)
│   ├── Device.cpp
│   ├── Event.cpp
│   ├── MotionEvent.cpp
│   ├── AlarmEvent.cpp
│   ├── DeviceFailureEvent.cpp
│   ├── EventQueue.cpp
│   ├── EventObjectPool.cpp
│   ├── EventDispatcher.cpp
│   ├── Camera.cpp
│   ├── CameraBuilder.cpp
│   ├── SecuritySystem.cpp
│   ├── DeviceManager.cpp
│   └── DebugSimulator.cpp
├── build/                # Build çıktıları (oluşturulur)
├── main.cpp             # Ana program
├── CMakeLists.txt       # CMake yapılandırma
└── README.md            # Bu dosya
```

## Derleme ve Çalıştırma

### Gereksinimler
- CMake 3.10 veya üzeri
- C++ derleyici (g++, clang++, vb.)
- Make

### Adımlar

1. **Build dizini oluştur ve derle:**
```bash
mkdir -p build && cd build && cmake .. && make
```

2. **Programı çalıştır:**
```bash
./main
```

### Tek Komutla (Build + Çalıştır)
```bash
mkdir -p build && cd build && cmake .. && make && ./main
```

## Test Sonuçları

Program çalıştırıldığında 6 test otomatik olarak çalışır. Başarılı çalıştırmada şu çıktı görülür:

```
Başarılı Testler: 6/6
>>> TÜM TESTLER BAŞARILI! ✓✓✓
```

## Tasarım Desenleri

- Singleton Pattern (EventQueue, EventObjectPool, DeviceManager)
- Builder Pattern (CameraBuilder)
- Observer Pattern (EventDispatcher + SecuritySystem)
- Object Pool Pattern (EventObjectPool)

## LLR'ler

- LLR10: Camera Device Class
- LLR25: Motion Detection -> Alarm Sequence
- LLR29: Event Queue/Scheduler
- LLR34: Camera Configuration (Builder)
- LLR38: Debug Simulator
