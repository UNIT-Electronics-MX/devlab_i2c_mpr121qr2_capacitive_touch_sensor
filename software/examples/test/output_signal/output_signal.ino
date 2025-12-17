Claro, Clau.
Aquí tienes un **README en inglés**, profesional, claro y listo para GitHub, explicando el uso del **MPR121QR2 with Touch Inputs (E0–E3) + GPIO Outputs (ELE8–ELE11)** exactamente como lo implementaste.

---

# 📘 **README — MPR121QR2 Touch + GPIO (ESP32-S3, No Libraries)**

## Overview

This project demonstrates how to use the **MPR121QR2 capacitive touch controller** with an **ESP32-S3** without any external libraries.
The configuration enables:

* **4 capacitive touch inputs** → Electrodes **E0–E3**
* **4 digital GPIO outputs** → Electrodes **ELE8–ELE11**
* **Push-pull output mode** for LED or logic control
* **Clean low-level I²C communication**
* **Full register-level configuration** based on the official MPR121 datasheet

The code is designed for hardware using the **MPR121QR2 module with breakouts for all electrodes**, including ELE8–ELE11.

---

## Features

### ✔ Capacitive Touch

* Touch channels: **E0, E1, E2, E3**
* Independent touch and release thresholds
* Polling-based detection (IRQ optional)

### ✔ GPIO Output Mode

* ELE8 → GPIO0
* ELE9 → GPIO1
* ELE10 → GPIO2
* ELE11 → GPIO3
* Configured as **push-pull digital outputs**
* Controlled through MPR121 registers:

  * `0x78` → SET
  * `0x79` → CLEAR
  * `0x7A` → TOGGLE

### ✔ Compatible with ESP32-S3

* SDA: **GPIO 5**
* SCL: **GPIO 6**
* 3.3V operation

---

## Why E4–E7 Are Not Used

The MPR121 supports **8 GPIO-capable pins (ELE4–ELE11)**, but **electrode mode always has higher priority than GPIO mode**.

To ensure reliable GPIO output:

* Only **E0–E3** are configured as touch inputs
* **E4–E11** are freed from electrode mode
* GPIO mode is explicitly enabled on **ELE8–ELE11**

This avoids conflicts where the MPR121 keeps pins in high-impedance mode if they remain assigned as electrodes.

---

## Hardware Connections

### ESP32-S3 → MPR121QR2

| ESP32-S3 | MPR121 |
| -------- | ------ |
| GPIO 5   | SDA    |
| GPIO 6   | SCL    |
| 3.3V     | VDD    |
| GND      | GND    |

### Outputs (on your PCB)

| GPIO Function | MPR121 Pin | Connector |
| ------------- | ---------- | --------- |
| GPIO0         | ELE8       | J6-1      |
| GPIO1         | ELE9       | J6-2      |
| GPIO2         | ELE10      | J6-3      |
| GPIO3         | ELE11      | J6-4      |

### Touch Inputs (on your PCB)

| Touch | Electrode | Connector |
| ----- | --------- | --------- |
| T0    | E0        | J4-1      |
| T1    | E1        | J4-2      |
| T2    | E2        | J4-3      |
| T3    | E3        | J4-4      |

---

## Software Behavior

1. Puts the MPR121 in **STOP mode**
2. Applies thresholds only to E0–E3
3. Disables electrode mode on E4–E11
4. Configures ELE8–ELE11 as **GPIO outputs**
5. Initializes them LOW
6. Enters RUN mode
7. Toggles GPIO outputs in a test sequence
8. Prints touch events for E0–E3

---

## Full Example Code

(Include exactly the full code I provided earlier.)

---

## Touch Detection

Touch values are read from register `0x00–0x01`.
Only the lower four bits (E0–E3) are used in this configuration.

Example output:

```
TOUCH E1
TOUCH E3
RELEASE E1
```

---

## GPIO Control

Digital output is controlled via:

```cpp
gpio_set(0);     // ELE8 → HIGH
gpio_clear(0);   // ELE8 → LOW
gpio_toggle(0);  // ELE8 → TOGGLE
```

This works independently of touch input.

---

## Notes

* If E4–E11 are unintentionally enabled as electrodes, **GPIO will not work**.
* Writing to CTL0/CTL1/SET/CLR will have **no effect** unless electrode mode is disabled.
* This implementation strictly follows register behavior described in the MPR121 datasheet.

---

## License

MIT License.
Use freely in commercial or educational projects.

---

If quieres, puedo:

✅ Añadir diagramas
✅ Poner imágenes del PCB
✅ Hacer una versión "Short" para documentación técnica
✅ Añadir una tabla de direcciones I2C y DIP switch

¿Quieres una versión más técnica o más amigable?
