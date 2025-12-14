# Developer C – Light & TV Module
## My Sweet Home (BIL464 C++ Design Project)

This repository contains the implementation of the **Light** and **TV** device modules
developed by **Developer C** for the *My Sweet Home* smart home system project.

---

##  Developer Information
- **Role:** Developer C
- **Responsibility:** Light & TV devices, configuration, and device listing

---

##  Implemented Features (LLR Mapping)

### Light Device
- Light class derived from `Device`
- Configurable parameters:
  - Name
  - Color (RGB / Hex)
  - Illumination level
- `powerOn()` / `powerOff()` implementation  
- Input validation for color and illumination

**Related LLRs:** LLR10, LLR14, LLR35

---

### TV Device
- TV class derived from `Device`
- Mandatory model selection:
  - Samsung
  - LG
- Model information is displayed in device list
- Power control with logging support

**Related LLRs:** LLR10, LLR33

---

### Device Configuration
- Device-specific configuration during creation
- Configuration copy support from an existing device
- Automatic ID reassignment during copy

**Related LLRs:** LLR14, LLR15

---

### Device Listing
- Devices are listed with:
  - ID
  - Name
  - Type
  - Status (ON / OFF / FAILED)
- Output is formatted for readability

**Related LLRs:** LLR32

---

##  File Structure


---

##  Integration Notes
- Classes are designed to be compatible with the shared `Device` base class.
- No external libraries are required.
- Ready for integration into the main project repository.

---

##  Testing
- Manual tests performed:
  - Power on/off
  - Configuration assignment
  - Configuration copy validation
  - Device listing output

---

##  Status
✔ Module completed  
✔ Ready for integration



