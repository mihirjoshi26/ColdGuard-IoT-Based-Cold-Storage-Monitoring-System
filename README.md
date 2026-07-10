<p align="center">
  <img src="https://img.shields.io/badge/MCU-LPC2148-blue?style=for-the-badge&logo=arm&logoColor=white" alt="MCU Badge"/>
  <img src="https://img.shields.io/badge/Sensor-DHT11-green?style=for-the-badge" alt="Sensor Badge"/>
  <img src="https://img.shields.io/badge/WiFi-ESP--01-orange?style=for-the-badge&logo=espressif&logoColor=white" alt="WiFi Badge"/>
  <img src="https://img.shields.io/badge/Cloud-ThingSpeak-red?style=for-the-badge" alt="Cloud Badge"/>
  <img src="https://img.shields.io/badge/IDE-Keil%20µVision-purple?style=for-the-badge" alt="IDE Badge"/>
  <img src="https://img.shields.io/badge/Language-Embedded%20C-yellow?style=for-the-badge&logo=c&logoColor=white" alt="Language Badge"/>
</p>

# 🧊 ColdGuard — ARM LPC2148 IoT Cold Storage Monitoring System

<p align="center">
  <strong>🌡️ Real-time IoT-enabled monitoring system for cold storage environments</strong><br/>
  <em>Built on ARM7 (NXP LPC2148) • DHT11 Sensor • ESP-01 Wi-Fi • ThingSpeak Cloud Dashboard</em>
</p>

---

## 📌 Table of Contents

| # | Section | Description |
|---|---------|-------------|
| 1 | [Project Overview](#-project-overview) | What ColdGuard does and why |
| 2 | [Features](#-features) | Complete feature list |
| 3 | [Project Images](#-project-images) | Hardware board, display & ThingSpeak dashboard photos |
| 4 | [Hardware Components](#-hardware-components) | Full Bill of Materials |
| 5 | [Circuit Details & Pin Connections](#-circuit-details--pin-connections) | Pinout, clock, wiring diagrams |
| 6 | [Circuit Block Diagram](#-circuit-block-diagram) | Visual system architecture |
| 7 | [Software Architecture](#-software-architecture) | Code structure & main loop flow |
| 8 | [ThingSpeak IoT Dashboard](#-thingspeak-iot-dashboard) | Cloud data fields & protocol |
| 9 | [LCD Display States](#-lcd-display-states) | All display screen layouts |
| 10 | [System Configuration](#-system-configuration) | Configurable parameters |
| 11 | [Menu & Password System](#-menu--password-system) | Secure settings access |
| 12 | [Build & Flash Instructions](#-build--flash-instructions) | How to compile and deploy |
| 13 | [File Structure](#-file-structure) | Source code organization |

---

## 📖 Project Overview

**ColdGuard** is an embedded systems major project designed to solve a critical real-world problem: **unmonitored temperature and humidity excursions in cold storage facilities** can lead to spoilage of perishable goods, pharmaceutical degradation, and significant financial losses.

Built on the **NXP LPC2148 ARM7TDMI-S** microcontroller, ColdGuard provides:

- ✅ **Continuous environmental monitoring** (temperature + humidity)
- ✅ **Instant local alerts** via buzzer when thresholds are exceeded
- ✅ **Door-open tracking** with countdown timer and configurable timeout
- ✅ **Cloud-based remote monitoring** via ThingSpeak IoT dashboard
- ✅ **Password-protected configuration** stored in non-volatile EEPROM
- ✅ **Real-time LCD feedback** with flicker-free display updates

### 🔧 System Specifications

| Parameter | Specification |
|-----------|---------------|
| **Microcontroller** | NXP LPC2148 — ARM7TDMI-S core, 60 MHz, 512 KB Flash, 32+8 KB SRAM |
| **Temperature Sensor** | DHT11 — Range: 0–50 °C, Accuracy: ±2 °C, Resolution: 1 °C |
| **Humidity Sensor** | DHT11 — Range: 20–90 %RH, Accuracy: ±5 %RH |
| **Display** | 16×2 Character LCD — HD44780 controller, 8-bit parallel interface |
| **Wi-Fi Module** | ESP-01 (ESP8266) — 802.11 b/g/n, UART AT-command interface, 9600 baud |
| **Non-volatile Storage** | AT24C256 — 256 Kbit I2C EEPROM, 64-byte page write |
| **User Input** | 4×4 Matrix Keypad (16 keys) + 2 External Interrupt Push Buttons |
| **Cloud Platform** | ThingSpeak IoT — 4-field channel, 60-second update interval |
| **Alert System** | Active piezo buzzer — threshold, door timeout, and composite alarms |
| **Development IDE** | Keil µVision4 — ARM MDK toolchain |
| **System Clock** | 60 MHz (PLL: 12 MHz × 5), Peripheral clock: 15 MHz (CCLK/4) |

---

## ✨ Features

### Core Monitoring
| Feature | Description |
|---------|-------------|
| 🌡️ **Temperature Monitoring** | DHT11 sensor sampled every 1 second with configurable setpoint (0–50 °C) |
| 💧 **Humidity Monitoring** | Simultaneous humidity tracking with configurable setpoint (20–95 %RH) |
| 📟 **Live LCD Dashboard** | Real-time display: `T:24°C/35 H:58%` — no clear-and-redraw flicker |

### Alert & Safety
| Feature | Description |
|---------|-------------|
| 🔔 **Threshold Alarms** | Buzzer activates immediately when temperature OR humidity exceeds setpoint |
| 🚪 **Door Open Detection** | External interrupt (EINT2) detects door state via magnetic reed switch |
| ⏱️ **Door Countdown Timer** | LCD shows live countdown; buzzer sounds if door stays open > 15 seconds |

### IoT & Cloud
| Feature | Description |
|---------|-------------|
| ☁️ **ThingSpeak Upload** | Temperature, humidity, door status, and alarm code pushed every 60 seconds |
| 📊 **Remote Dashboard** | View live graphs and historical trends from any browser or phone |
| 🚨 **Door Event Logging** | Two-point door-open/close timestamps enable duration calculation on ThingSpeak |

### Security & Configuration
| Feature | Description |
|---------|-------------|
| 🔒 **Password Protection** | 4-digit PIN required to access configuration menu (max 3 attempts before lockout) |
| 💾 **EEPROM Persistence** | All settings (temp/humidity setpoints, password) survive power cycles |
| 🔁 **Fault Tolerance** | DHT11 auto-retries up to 3×; falls back to last known value on persistent failure |

---

## 📸 Project Images

### 1. Full Hardware Board

> *Complete ColdGuard hardware assembly showing the LPC2148 development board with all peripheral modules connected — DHT11 sensor, ESP-01 Wi-Fi module, 16×2 LCD, 4×4 keypad, buzzer, door switch, and EEPROM.*

<!-- 📌 INSTRUCTION: Replace the path below with your actual hardware board image -->
<!-- Example: ![Hardware Board](images/hardware_board.jpg) -->
![Full Hardware Board](images/hardware_board.jpg)

---

### 2. LCD Display Output

> *ColdGuard running in monitoring mode — LCD shows real-time temperature, humidity, setpoint values, and door status.*

<!-- 📌 INSTRUCTION: Replace the path below with your actual display image -->
<!-- Example: ![LCD Display](images/lcd_display.jpg) -->
![LCD Display Output](images/display.jpg)

---

## 🔧 Hardware Components

### Bill of Materials (BOM)

| # | Component | Model / Specification | Interface | Qty |
|:-:|-----------|----------------------|-----------|:---:|
| 1 | **Microcontroller** | NXP LPC2148 (ARM7TDMI-S, 60 MHz, 512 KB Flash, 32 KB RAM) | — | 1 |
| 2 | **Temp & Humidity Sensor** | DHT11 (0–50 °C / 20–90 %RH, single-wire protocol) | GPIO (P0.4) | 1 |
| 3 | **Character LCD** | 16×2 HD44780-compatible (8-bit parallel mode) | 8-bit GPIO | 1 |
| 4 | **Wi-Fi Module** | ESP-01 (ESP8266, 802.11 b/g/n, AT-command firmware) | UART0 @ 9600 | 1 |
| 5 | **EEPROM** | AT24C256 (256 Kbit, I2C, 64-byte page, 400 kHz) | I2C0 | 1 |
| 6 | **Matrix Keypad** | 4×4 membrane keypad (0–9, A–D, *, #) | GPIO (Port 1) | 1 |
| 7 | **Active Buzzer** | 5V piezoelectric buzzer (active, no driver needed) | GPIO (P0.19) | 1 |
| 8 | **Door Sensor** | Magnetic reed switch / tactile push button | EINT2 (P0.7) | 1 |
| 9 | **Menu Button** | Tactile push button (momentary, NO) | EINT3 (P0.20) | 1 |
| 10 | **Crystal Oscillator** | 12 MHz HC49 quartz crystal + 22 pF load capacitors | XTAL1/XTAL2 | 1 |
| 11 | **Voltage Regulators** | LM7805 (5V, 1A) + AMS1117-3.3 (3.3V for ESP-01) | — | 1 each |
| 12 | **Pull-up Resistors** | 4.7 kΩ (I2C SDA/SCL, DHT11 data line) | — | 3 |
| 13 | **Contrast Pot** | 10 kΩ trimmer potentiometer (LCD VO adjustment) | — | 1 |
| 14 | **Decoupling Caps** | 100 nF ceramic (per IC VCC pin) + 10 µF electrolytic | — | as needed |

---

## ⚡ Circuit Details & Pin Connections

### 🕐 System Clock Configuration

The LPC2148 clock tree is configured in `Startup.s` and `main.c`:

```
┌─────────────────────────────────────────────────────────────┐
│                    CLOCK CONFIGURATION                      │
├─────────────────────────────────────────────────────────────┤
│  Crystal (FOSC)    │  12 MHz  (external HC49 quartz)        │
│  PLL Multiplier    │  M = 5   (PLLCFG bits [4:0])           │
│  PLL Divider       │  P = 2   (PLLCFG bits [6:5])           │
│  System Clock      │  CCLK = 12 × 5 = 60 MHz                │
│  VPB Divider       │  VPBDIV = 0x00 → PCLK = CCLK / 4       │
│  Peripheral Clock  │  PCLK = 15 MHz                         │
│  UART Baud Rate    │  9600 → Divisor = 15M / (16×9600) = 97 │
│  MAM               │  Fully enabled (MAMCR=2, MAMTIM=4)     │
└─────────────────────────────────────────────────────────────┘
```

---

### 📍 Complete Pin Mapping — LPC2148

#### Port 0 — Main Peripheral Bus

| Pin | Alternate Function | Signal | Connected To | Direction | Notes |
|:---:|:------------------:|--------|-------------|:---------:|-------|
| P0.0 | TXD0 | UART0 TX | ESP-01 RX | OUT | 3.3V level shift required |
| P0.1 | RXD0 | UART0 RX | ESP-01 TX | IN | 3.3V level shift required |
| P0.2 | SCL0 | I2C0 Clock | AT24C256 SCL | OD | 4.7 kΩ pull-up to VCC |
| P0.3 | SDA0 | I2C0 Data | AT24C256 SDA | OD | 4.7 kΩ pull-up to VCC |
| P0.4 | — | DHT11 Data | DHT11 DATA | I/O | 4.7 kΩ pull-up, single-wire |
| P0.7 | EINT2 | Door IRQ | Reed Switch → GND | IN | Active-LOW, edge-triggered |
| P0.8 | — | LCD D0 | LCD pin 7 | OUT | 8-bit data bus (LSB) |
| P0.9 | — | LCD D1 | LCD pin 8 | OUT | |
| P0.10 | — | LCD D2 | LCD pin 9 | OUT | |
| P0.11 | — | LCD D3 | LCD pin 10 | OUT | |
| P0.12 | — | LCD D4 | LCD pin 11 | OUT | |
| P0.13 | — | LCD D5 | LCD pin 12 | OUT | |
| P0.14 | — | LCD D6 | LCD pin 13 | OUT | |
| P0.15 | — | LCD D7 | LCD pin 14 | OUT | 8-bit data bus (MSB) |
| P0.16 | — | LCD RS | LCD pin 4 | OUT | 0=Command, 1=Data |
| P0.17 | — | LCD EN | LCD pin 6 | OUT | High-to-low pulse to latch |
| P0.19 | — | Buzzer | Buzzer (+) | OUT | Active-HIGH drive |
| P0.20 | EINT3 | Menu IRQ | Push Button → GND | IN | Active-LOW, edge-triggered |

#### Port 1 — 4×4 Keypad Matrix

| Pin | Function | Direction | Notes |
|:---:|----------|:---------:|-------|
| P1.16 | Column 0 | IN | Internal pull-up enabled |
| P1.17 | Column 1 | IN | Internal pull-up enabled |
| P1.18 | Column 2 | IN | Internal pull-up enabled |
| P1.19 | Column 3 | IN | Internal pull-up enabled |
| P1.20 | Row 0 | OUT | Active-LOW scan |
| P1.21 | Row 1 | OUT | Active-LOW scan |
| P1.22 | Row 2 | OUT | Active-LOW scan |
| P1.23 | Row 3 | OUT | Active-LOW scan |

---

### 🔌 Individual Module Wiring

<details>
<summary><strong>🌡️ DHT11 Temperature & Humidity Sensor</strong></summary>

```
      DHT11                   LPC2148
    ┌─────────┐
    │  VCC    │──────────────── +5V
    │  DATA   │──────┬──────── P0.4 (GPIO, bi-directional)
    │  NC     │      │
    │  GND    │──┐   │ 4.7kΩ
    └─────────┘  │   │ pull-up
                 │   │
                GND  +5V
```

> **Protocol:** Single-wire, host-initiated. MCU pulls DATA low for 18 ms, then reads 40-bit response (8-bit humidity integer + 8-bit humidity decimal + 8-bit temp integer + 8-bit temp decimal + 8-bit checksum). All interrupts disabled during read for microsecond timing accuracy.

</details>

<details>
<summary><strong>📡 ESP-01 (ESP8266) Wi-Fi Module</strong></summary>

```
      ESP-01                  LPC2148 / Power
    ┌─────────┐
    │  VCC    │──────────────── +3.3V (AMS1117 regulated)
    │  GND    │──────────────── GND
    │  CH_PD  │──────────────── +3.3V (chip enable, must be HIGH)
    │  TX     │──────────────── P0.1 (UART0 RX) [via voltage divider]
    │  RX     │──────────────── P0.0 (UART0 TX) [via voltage divider]
    │  GPIO0  │──────────────── +3.3V (normal run mode)
    │  GPIO2  │──────────────── (floating / not connected)
    │  RST    │──────┬──────── +3.3V
    └─────────┘      │
                   10kΩ pull-up
```

> ⚠️ **CRITICAL:** The ESP-01 operates at **3.3V logic**. The LPC2148 GPIO is 5V. Use a resistor voltage divider (1 kΩ + 2 kΩ) or a bi-directional logic level converter on the TX/RX lines to prevent damage.

> **Communication:** AT-command firmware at 9600 baud. Commands: `AT+CWJAP` (join AP), `AT+CIPSTART` (TCP connect), `AT+CIPSEND` (send data). HTTP GET to `api.thingspeak.com:80`.

</details>

<details>
<summary><strong>💾 AT24C256 EEPROM (I2C)</strong></summary>

```
    AT24C256                  LPC2148
    ┌─────────┐
    │  VCC    │──────────────── +5V
    │  GND    │──────────────── GND
    │  SCL    │──────┬──────── P0.2 (I2C0 SCL, open-drain)
    │  SDA    │──┬   │         P0.3 (I2C0 SDA, open-drain)
    │  A0     │──┤   │ 4.7kΩ
    │  A1     │──┤  GND pull-ups
    │  A2     │──┤   to +5V
    │  WP     │──┘
    └─────────┘
    A0=A1=A2=GND → I2C address = 0xA0 (write) / 0xA1 (read)
    WP = GND → Write protection disabled
```

> **Usage:** Stores `SystemConfig` struct — temperature setpoint (s16), humidity setpoint (u8), password length (u8), password string (5 bytes). Magic byte at address 0x0000 validates data integrity.

</details>

<details>
<summary><strong>📟 16×2 Character LCD (HD44780, 8-bit mode)</strong></summary>

```
    LCD Pin    Signal           LPC2148 / Power
    ──────────────────────────────────────────
    Pin 1      VSS (GND)       GND
    Pin 2      VDD (+5V)       +5V
    Pin 3      VO  (Contrast)  10kΩ pot wiper → GND
    Pin 4      RS              P0.16 (0=CMD, 1=DATA)
    Pin 5      RW              GND (write-only mode)
    Pin 6      EN              P0.17 (pulse HIGH→LOW to latch)
    Pin 7      D0              P0.8
    Pin 8      D1              P0.9
    Pin 9      D2              P0.10
    Pin 10     D3              P0.11
    Pin 11     D4              P0.12
    Pin 12     D5              P0.13
    Pin 13     D6              P0.14
    Pin 14     D7              P0.15
    Pin 15     BL Anode (+)    +5V via 100Ω current-limit resistor
    Pin 16     BL Cathode (-)  GND
```

</details>

<details>
<summary><strong>⌨️ 4×4 Matrix Keypad</strong></summary>

```
    Keypad Layout:
    ┌─────┬─────┬─────┬─────┐
    │  1  │  2  │  3  │  A  │  ← Row 0 (P1.20)
    ├─────┼─────┼─────┼─────┤
    │  4  │  5  │  6  │  B  │  ← Row 1 (P1.21)
    ├─────┼─────┼─────┼─────┤
    │  7  │  8  │  9  │  C  │  ← Row 2 (P1.22)
    ├─────┼─────┼─────┼─────┤
    │  *  │  0  │  #  │  D  │  ← Row 3 (P1.23)
    └─────┴─────┴─────┴─────┘
       ↑     ↑     ↑     ↑
     Col0  Col1  Col2  Col3
    P1.16 P1.17 P1.18 P1.19

    Scan method: Rows driven LOW one at a time;
    Columns read with pull-ups (pressed key = LOW).
```

</details>

<details>
<summary><strong>🔔 Buzzer & 🚪 Door Switch & 📋 Menu Button</strong></summary>

```
    Active Buzzer (P0.19):
    P0.19 ──── [Buzzer +] ──── GND
    Drive: Active-HIGH (IOSET0 to activate, IOCLR0 to silence)

    Door Reed Switch (P0.7 / EINT2):
    P0.7 ────┬──── [Reed Switch] ──── GND
             │
           10kΩ pull-up to +3.3V
    Trigger: Active-LOW, falling-edge external interrupt

    Menu Push Button (P0.20 / EINT3):
    P0.20 ───┬──── [Push Button] ──── GND
             │
           10kΩ pull-up to +3.3V
    Trigger: Active-LOW, falling-edge external interrupt
```

</details>

---

## 🗺️ Circuit Block Diagram

> **Complete system interconnection diagram showing all modules, communication buses, and data flow.**

```
 ═══════════════════════════════════════════════════════════════════════════════════
 ║                          COLDGUARD SYSTEM BLOCK DIAGRAM                        ║
 ═══════════════════════════════════════════════════════════════════════════════════

                              ┌──────────────────────┐
                              │    POWER SUPPLY       │
                              │                      │
                              │  VIN (7-12V DC)      │
                              │    │         │       │
                              │  ┌─▼──┐   ┌──▼───┐  │
                              │  │7805│   │1117  │  │
                              │  │    │   │ 3.3  │  │
                              │  └─┬──┘   └──┬───┘  │
                              │    │         │       │
                              │  +5V       +3.3V    │
                              └────┬─────────┬──────┘
                                   │         │
          ┌────────────────────────┼─────────┼────────────────────────┐
          │                        │         │                        │
          │    ╔═══════════════════╧═════════╧══════════════════╗     │
          │    ║                                                ║     │
          │    ║           ╔═══════════════════════╗            ║     │
          │    ║           ║      LPC2148          ║            ║     │
          │    ║           ║   ARM7TDMI-S Core     ║            ║     │
          │    ║           ║     60 MHz CCLK       ║            ║     │
          │    ║           ║     15 MHz PCLK       ║            ║     │
          │    ║           ║                       ║            ║     │
          │    ║           ║  512 KB Flash         ║            ║     │
          │    ║           ║   32 KB SRAM          ║            ║     │
          │    ║           ╚═══════════════════════╝            ║     │
          │    ║                                                ║     │
          │    ╚════════════════════════════════════════════════╝     │
          │         │        │       │       │       │       │        │
          │         │        │       │       │       │       │        │
          │    ┌────┘   ┌────┘  ┌────┘  ┌────┘   ┌───┘  ┌───┘   ┌────┘
          │    │        │       │       │        │      │       │
          │    │ P0.4   │P0.0   │P0.2   │P0.8    │P0.19 │P0.7   │P0.20
          │    │(GPIO)  │P0.1   │P0.3   │-P0.17  │(GPIO)│EINT2  │EINT3
          │    │        │(UART0)│(I2C0) │(GPIO)  │      │       │
          │    │        │       │       │        │      │       │
   ┌──────▼──┐ │  ┌─────▼──┐ ┌─▼────┐ ┌▼──────┐ │ ┌────▼──┐ ┌──▼───┐
   │         │ │  │        │ │      │ │       │ │ │       │ │      │
   │  DHT11  │ │  │ ESP-01 │ │ AT24 │ │ 16x2  │ │ │ Reed  │ │ Menu │
   │         │ │  │ESP8266 │ │ C256 │ │  LCD  │ │ │Switch │ │Button│
   │  Temp   │ │  │        │ │      │ │       │ │ │       │ │      │
   │  Humid  │ │  │  Wi-Fi │ │EEPROM│ │HD44780│ │ │ Door  │ │Config│
   │  Sensor │ │  │ Module │ │      │ │       │ │ │Sensor │ │Access│
   └─────────┘ │  └───┬────┘ └──────┘ └───────┘ │ └───────┘ └──────┘
               │      │                          │
               │      │ HTTP GET                  │
         ┌─────▼────┐ │ port 80            ┌──────▼──────┐
         │  4 x 4   │ │                    │   Active    │
         │  Matrix  │ ▼                    │   Buzzer    │
         │  Keypad  │                      │  (Piezo)    │
         │          │ ┌─────────────┐      └─────────────┘
         │ P1.16-23 │ │ ThingSpeak  │
         └──────────┘ │   Cloud     │
                      │             │
                      │ ┌─────────┐ │
                      │ │ field1: │ │
                      │ │  Temp   │ │
                      │ │ field2: │ │
                      │ │ Humid   │ │
                      │ │ field3: │ │
                      │ │  Door   │ │
                      │ │ field4: │ │
                      │ │ Alarm   │ │
                      │ └─────────┘ │
                      └─────────────┘
```

### Data Flow Summary

```
┌──────────────┐    Single-Wire     ┌────────────┐     In-place      ┌──────────┐
│   DHT11      │ ──────────────────►│            │ ───────────────► │  16×2    │
│  (Temp/RH)   │    every 1 sec     │            │    overwrite      │   LCD    │
└──────────────┘                    │            │                   └──────────┘
                                    │  LPC2148   │
┌──────────────┐    EINT2 (IRQ)     │  ARM7 MCU  │     GPIO HIGH     ┌──────────┐
│ Door Switch  │ ──────────────────►│            │ ───────────────► │  Buzzer  │
└──────────────┘    edge-trigger    │            │   on alarm/door   └──────────┘
                                    │            │
┌──────────────┐    Row/Col Scan    │            │   UART0 + AT     ┌──────────┐
│  4×4 Keypad  │ ──────────────────►│            │ ───────────────► │  ESP-01  │──► ThingSpeak
└──────────────┘                    │            │   every 60 sec    └──────────┘
                                    │            │
┌──────────────┐    EINT3 (IRQ)     │            │   I2C0 R/W       ┌──────────┐
│ Menu Button  │ ──────────────────►│            │ ◄──────────────► │ AT24C256 │
└──────────────┘                    └────────────┘                   └──────────┘
```

### Interrupt Map

| Interrupt | Source | Pin | Trigger | Purpose |
|-----------|--------|-----|---------|---------|
| **EINT2** | Door reed switch | P0.7 | Falling edge (Active-LOW) | Wake main loop for door event |
| **EINT3** | Menu push button | P0.20 | Falling edge (Active-LOW) | Enter configuration menu |
| **Timer0** | Internal | — | Match register | Microsecond/millisecond delay generation |

---

## 🏗️ Software Architecture

The firmware follows a **modular driver architecture** — each peripheral has its own `.c`/`.h` pair with a clean public API:

```
┌─────────────────────────────────────────────────────────────────────────┐
│                          APPLICATION LAYER                              │
│                                                                         │
│   main.c ── Init_All() → Main Loop (sensor → display → alarm → cloud)  │
│                                                                         │
├──────────────┬──────────────┬──────────────┬────────────────────────────┤
│   MIDDLEWARE │              │              │                            │
│              │              │              │                            │
│  password.c  │   menu.c     │  logger.c    │  app_config.h (struct)     │
│  (PIN gate)  │  (settings)  │ (UART debug) │  config.h (constants)      │
│              │              │              │                            │
├──────────────┴──────────────┴──────────────┴────────────────────────────┤
│                           DRIVER LAYER                                  │
│                                                                         │
│  dht11.c   lcd.c    uart0.c   esp01.c   eeprom.c   i2c.c   keypad.c   │
│  buzzer.c  door_interrupt.c   delay.c   rtc.c                          │
│                                                                         │
├─────────────────────────────────────────────────────────────────────────┤
│                           HARDWARE LAYER                                │
│                                                                         │
│  Startup.s (PLL, MAM, stack init)   │   LPC214x.h (register map)       │
│  defines.h (SETBIT, CLRBIT macros)  │   types.h (u8, u16, s16, u32)    │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### Source File Reference

| File | Lines | Purpose |
|------|:-----:|---------|
| `main.c` | 406 | Application entry, Init_All(), main loop with 8 stages |
| `config.h` | 105 | All hardware pins, clock settings, thresholds, credentials |
| `dht11.c` / `.h` | — | Single-wire protocol: start signal, 40-bit read, checksum verify |
| `lcd.c` / `.h` | — | HD44780 init, command/data write, goto, print string/int |
| `uart0.c` / `.h` | — | UART0 init (9600 baud), TX/RX byte, TX string, RX with timeout |
| `esp01.c` / `.h` | — | AT-command sequencer: CWJAP, CIPSTART, CIPSEND, HTTP GET builder |
| `eeprom.c` / `.h` | — | I2C byte/page/buffer R/W, config load/save with magic-byte validation |
| `i2c.c` / `.h` | — | I2C0 start, stop, write, read, ACK/NACK handling |
| `keypad.c` / `.h` | — | Row scan, column read, debounce, key-to-char mapping |
| `buzzer.c` / `.h` | — | Init pin direction, Buzzer_On(), Buzzer_Off() |
| `door_interrupt.c` / `.h` | — | EINT2 ISR registration, Door_IsOpen() status read |
| `password.c` / `.h` | — | Keypad-based 4-digit PIN entry, verification against EEPROM config |
| `menu.c` / `.h` | — | Interactive LCD menu: temp/humidity setpoint, password change |
| `delay.c` / `.h` | — | Timer0 match-based delay_us() and delay_ms() |
| `logger.c` / `.h` | — | UART0 debug print (string, integer, hex) |
| `Startup.s` | 489 | ARM7 vector table, PLL setup, MAM config, stack init, jump to main |

### Main Loop State Machine

```
    ┌─────────────────────────────────────────────────────────────┐
    │                     BOOT SEQUENCE                           │
    │                                                             │
    │  SystemClock_Init()  →  Timer0_Init()  →  UART0_Init()     │
    │  LCD_Init()  →  Buzzer_Init()  →  Keypad_Init()            │
    │  EEPROM_Init() + LoadConfig()  →  DHT11_Init() (1.2s)      │
    │  ESP01_Init() (AT+RST, CWJAP)  →  DoorInterrupt_Init()    │
    │                                                             │
    │  LCD shows: "ColdGuard" → "Running..."                     │
    └─────────────────────────┬───────────────────────────────────┘
                              │
                              ▼
    ╔═════════════════════════════════════════════════════════════╗
    ║                      MAIN LOOP                              ║
    ║                                                             ║
    ║  ┌─── 1. EINT3 Menu? ──► Password_Verify → Menu_Run()     ║
    ║  │                                                         ║
    ║  ├─── 2. Keypad poll (flush buffer)                        ║
    ║  │                                                         ║
    ║  ├─── 3. DHT11_Read()                                      ║
    ║  │       ├── Success → update temp & humidity               ║
    ║  │       ├── Fail ≤3 → "Retrying..." + 1s delay            ║
    ║  │       └── Fail >3 → use last known value                ║
    ║  │                                                         ║
    ║  ├─── 4. DisplayMonitorScreen()                            ║
    ║  │       Line 1: "T:24°C/35 H:58%"                        ║
    ║  │       Line 2: "Door:Closed" or "Door:Open T Xs"         ║
    ║  │                                                         ║
    ║  ├─── 5. HandleSensorAlarms()                              ║
    ║  │       alarmCode: bit0=temp, bit1=humidity                ║
    ║  │       → Buzzer_On() if any threshold exceeded            ║
    ║  │                                                         ║
    ║  ├─── 6. HandleDoorLogic(1000ms)                           ║
    ║  │       ├── Door open <15s → LCD countdown                ║
    ║  │       ├── Door open ≥15s → "DOOR >15s ALERT" + buzzer  ║
    ║  │       └── Door closes after ≥15s → send ThingSpeak      ║
    ║  │           (field3=1, wait 16s, field3=0)                 ║
    ║  │                                                         ║
    ║  ├─── 7. ThingSpeak periodic upload (every 60s)            ║
    ║  │       ESP01_SendUpdate(temp, humidity, door, alarm)      ║
    ║  │                                                         ║
    ║  └─── 8. Wait 1s (50ms chunks, interruptible by EINT3)    ║
    ║                                                             ║
    ║  ◄─────────────────── REPEAT ──────────────────────────►    ║
    ╚═════════════════════════════════════════════════════════════╝
```

---

## ☁️ ThingSpeak IoT Dashboard

Data is uploaded to **ThingSpeak** via HTTP GET requests through the ESP-01 Wi-Fi module. The free-tier update interval is **60 seconds** (ThingSpeak requires ≥15 s between channel updates).

### Channel Field Mapping

| Field | Data Type | Unit | Range | Description |
|:-----:|-----------|:----:|-------|-------------|
| `field1` | Temperature | °C | 0–50 | DHT11 integer temperature reading |
| `field2` | Humidity | %RH | 20–90 | DHT11 integer relative humidity reading |
| `field3` | Door Status | flag | 0 / 1 | `1` = door-opened event, `0` = door-closed event |
| `field4` | Alarm Code | enum | 0–3 | `0`=OK, `1`=Temp high, `2`=Humidity high, `3`=Both |

### HTTP Request Format

```
GET /update?api_key=<WRITE_KEY>&field1=<temp>&field2=<humidity>&field3=<door>&field4=<alarm>
Host: api.thingspeak.com
```

### Door Event Protocol (Dual-Timestamp)

When the door is held open **longer than 15 seconds**, ColdGuard sends **two sequential updates** to enable open-duration calculation on ThingSpeak:

```
    Time ──────────────────────────────────────────────────────►

    Door opens              15s threshold           Door closes
        │                        │                       │
        │    countdown on LCD    │   ALERT + buzzer      │
        │◄──────────────────────►│◄─────────────────────►│
        │                        │                       │
                                 │                       │
                         ┌───────▼────────┐      ┌───────▼────────┐
                         │ ThingSpeak #1  │      │ ThingSpeak #2  │
                         │ field3 = 1     │      │ field3 = 0     │
                         │ (Door Open)    │      │ (Door Closed)  │
                         │ timestamp = T₁ │      │ timestamp = T₂ │
                         └────────────────┘      └────────────────┘
                                                        │
                              ◄── 16s gap ──►           │
                                                        │
                         Open Duration = T₂ − T₁ (calculated on ThingSpeak)
```

---

## 📟 LCD Display States

The 16×2 LCD shows different screens depending on system state:

### Normal Monitoring
```
╔══════════════════╗
║ T:24°C/35 H:58%  ║  ← actual temp / setpoint / humidity
║ Door:Closed      ║  ← door status
╚══════════════════╝
```

### Door Open — Countdown Active
```
╔══════════════════╗
║ T:24°C/35 H:58%  ║
║ Door:Open T 12s  ║  ← seconds remaining until alert
╚══════════════════╝
```

### Door Alert — Timeout Exceeded
```
╔══════════════════╗
║ T:24°C/35 H:58%  ║
║ DOOR >15s ALERT  ║  ← buzzer ON, alert active
╚══════════════════╝
```

### DHT11 Error — Using Last Value
```
╔══════════════════╗
║ DHT11 Err(last)  ║  ← sensor failed, using cached value
║ Door:Closed      ║
╚══════════════════╝
```

### Boot Sequence Screens
```
"ColdGuard"          "Config Loaded"     "DHT11 Sensor"     "ColdGuard"
"Initialising..."    "From EEPROM"       "Ready"             "Running..."
     ↓ 800ms              ↓ 700ms             ↓ 400ms             ↓ 600ms
```

---

## ⚙️ System Configuration

All user-adjustable settings are defined in [`config.h`](config.h):

### Sensor & Alarm Thresholds

| Macro | Default | Range | Description |
|-------|:-------:|:-----:|-------------|
| `DEFAULT_TEMP_SETPOINT` | 35 °C | 0–50 | Temperature alarm trigger point |
| `DEFAULT_HUMIDITY_SETPOINT` | 65 %RH | 20–95 | Humidity alarm trigger point |
| `DOOR_OPEN_ALERT_SECONDS` | 15 s | — | Door open duration before alarm |
| `SENSOR_SAMPLE_DELAY_MS` | 1000 ms | ≥1000 | DHT11 sample interval (min 1s per datasheet) |

### Security

| Macro | Default | Description |
|-------|:-------:|-------------|
| `DEFAULT_PASSWORD` | `"1234"` | Factory-default 4-digit PIN |
| `PASSWORD_MIN_LEN` | 4 | Minimum allowed PIN length |
| `PASSWORD_MAX_LEN` | 4 | Maximum allowed PIN length |
| `MAX_PASSWORD_ATTEMPTS` | 3 | Wrong entries before lockout |

### Wi-Fi & ThingSpeak

| Macro | Default | Description |
|-------|---------|-------------|
| `ESP_ENABLE` | 1 | Set to `0` to disable all Wi-Fi features |
| `WIFI_SSID` | `"Mihir"` | Your Wi-Fi network name |
| `WIFI_PASSWORD` | `"********"` | Your Wi-Fi password |
| `THINGSPEAK_WRITE_API_KEY` | `"YOUR_KEY"` | ThingSpeak channel write API key |
| `THINGSPEAK_HOST` | `"api.thingspeak.com"` | ThingSpeak API endpoint |
| `THINGSPEAK_PORT` | 80 | HTTP port |

### EEPROM

| Macro | Default | Description |
|-------|:-------:|-------------|
| `EEPROM_FIRST_TIME_SETUP` | 0 | Set to `1` **once** for factory reset, then set back to `0` |

> ⚠️ **Security Warning:** Before pushing to GitHub, move `WIFI_SSID`, `WIFI_PASSWORD`, and `THINGSPEAK_WRITE_API_KEY` to a separate `secrets.h` file and add it to `.gitignore`.

---

## 🔒 Menu & Password System

The configuration menu is hardware-gated behind an external interrupt and software-gated behind a PIN:

```
┌──────────────┐     EINT3        ┌──────────────────┐     PIN OK      ┌─────────────────┐
│  Menu Button │ ────────────────►│  Password Entry  │ ──────────────► │  Config Menu    │
│   (P0.20)    │   falling-edge   │  (4-digit PIN    │   verified      │                 │
└──────────────┘                  │   via keypad)    │                 │  1. Temp SP     │
                                  └────────┬─────────┘                 │  2. Humid SP    │
                                           │                           │  3. Password    │
                                      PIN wrong                       └────────┬────────┘
                                     (≤3 tries)                                │
                                           │                              Changes saved
                                           ▼                              to EEPROM
                                  ┌────────────────┐                    immediately
                                  │ "Wrong Password"│
                                  │   retry / lock  │
                                  └────────────────┘

    After >3 wrong attempts → system locks out and returns to monitoring mode.
```

### Menu Options

| Option | Input Range | Stored In | Notes |
|--------|:-----------:|-----------|-------|
| Temperature Setpoint | 0 – 50 °C | EEPROM + RAM | Immediate effect on alarm logic |
| Humidity Setpoint | 20 – 95 %RH | EEPROM + RAM | Immediate effect on alarm logic |
| Change Password | 4 digits | EEPROM + RAM | New PIN required on next menu access |

---

## 🛠️ Build & Flash Instructions

### Prerequisites

| Tool | Version | Purpose |
|------|---------|---------|
| **Keil µVision** | v4 or v5 (legacy pack) | IDE + ARM MDK compiler |
| **LPC2148 Device Pack** | — | CMSIS headers + startup files |
| **Flash Magic** | v14+ | ISP flash programming via UART |
| *or* **Keil ULINK** | — | JTAG/SWD flash programming |

### Step-by-Step Build & Deploy

```
Step 1: Clone Repository
────────────────────────
    $ git clone https://github.com/<your-username>/coldguard.git
    $ cd coldguard

Step 2: Configure Wi-Fi Credentials
────────────────────────────────────
    Open config.h and edit:
    #define WIFI_SSID            "YourNetworkName"
    #define WIFI_PASSWORD        "YourPassword"
    #define THINGSPEAK_WRITE_API_KEY  "YourAPIKey"

Step 3: Open in Keil µVision
────────────────────────────
    File → Open Project → major.uvproj

Step 4: Build
─────────────
    Press F7 or Project → Build Target
    Output: major.hex (in project root)
    Expected: "0 Error(s), 0 Warning(s)"

Step 5: Flash via ISP
─────────────────────
    Open Flash Magic:
      Device     : LPC2148
      COM Port   : COMx @ 9600 baud
      Oscillator : 12 MHz
      Hex File   : major.hex
    → Click "Start" to program

Step 6: First-Time EEPROM Setup (one-time only)
───────────────────────────────────────────────
    1. In config.h: set EEPROM_FIRST_TIME_SETUP to 1
    2. Rebuild + Flash → writes factory defaults to EEPROM
    3. IMMEDIATELY set EEPROM_FIRST_TIME_SETUP back to 0
    4. Rebuild + Flash again for normal operation
```

---

## 📁 File Structure

```
coldguard/
│
├── 📄 README.md                 ← This file
│
├── 🖼️ images/                   ← Project photos
│   ├── hardware_board.jpg       ← Full hardware assembly
│   └── display.jpg              ← LCD display output
│
├── ⚙️ Core Application
│   ├── main.c                   ← Entry point, Init_All(), main loop
│   ├── config.h                 ← All pin definitions, clocks, thresholds, credentials
│   ├── app_config.h             ← SystemConfig struct (setpoints + password)
│   ├── defines.h                ← Bit-manipulation macros (SETBIT, CLRBIT, etc.)
│   └── types.h                  ← Portable type aliases: u8, u16, u32, s16
│
├── 🌡️ Sensor Drivers
│   ├── dht11.c / dht11.h       ← DHT11 single-wire temperature & humidity
│   └── door_interrupt.c / .h   ← EINT2 ISR, Door_IsOpen() status
│
├── 📟 Display
│   └── lcd.c / lcd.h           ← HD44780 8-bit driver, goto, print, clear
│
├── 📡 Communication
│   ├── uart0.c / uart0.h       ← UART0 driver (9600 baud)
│   ├── esp01.c / esp01.h       ← ESP-01 AT commands + ThingSpeak HTTP upload
│   ├── i2c.c / i2c.h           ← I2C0 hardware driver
│   └── eeprom.c / eeprom.h     ← AT24C256 EEPROM config load/save
│
├── ⌨️ User Input
│   ├── keypad.c / keypad.h     ← 4×4 matrix scan + debounce
│   ├── password.c / password.h ← PIN entry & verification
│   └── menu.c / menu.h         ← Interactive configuration menu
│
├── 🔔 Output
│   └── buzzer.c / buzzer.h     ← Buzzer on/off control
│
├── 🔧 Utilities
│   ├── delay.c / delay.h       ← Timer0-based microsecond/millisecond delays
│   ├── logger.c / logger.h     ← UART debug print
│   └── rtc.c / rtc.h           ← Real-time clock utilities
│
├── 🏗️ Build System
│   ├── Startup.s               ← ARM7 startup assembly (PLL, MAM, stacks)
│   ├── major.uvproj            ← Keil µVision project file
│   ├── major.sct               ← Linker scatter file (memory layout)
│   └── major.hex               ← Compiled firmware (ready to flash)
│
└── 📋 Build Artifacts (generated)
    ├── *.o                      ← Object files
    ├── *.crf                    ← Cross-reference files
    ├── *.d                      ← Dependency files
    ├── major.axf                ← ELF executable
    └── major.map                ← Linker memory map
```

---

## 🧠 Technical Deep-Dive

<details>
<summary><strong>How DHT11 Single-Wire Protocol Works</strong></summary>

```
MCU Start Signal:
    MCU pulls DATA low for 18 ms → releases (pull-up goes HIGH)

DHT11 Response:
    DHT11 pulls low 80 µs → high 80 µs (ACK)

40-bit Data Transmission:
    Each bit: 50 µs LOW (start) + 26-28 µs HIGH (bit=0) or 70 µs HIGH (bit=1)

    Byte order: [Humid_Int] [Humid_Dec] [Temp_Int] [Temp_Dec] [Checksum]
    Checksum = Humid_Int + Humid_Dec + Temp_Int + Temp_Dec (lower 8 bits)
```

> **Important:** All interrupts are disabled during the DHT11 read to protect microsecond timing. This is why `DHT11_Read()` briefly blocks the system for ~4 ms.

</details>

<details>
<summary><strong>EEPROM Memory Layout</strong></summary>

```
Address   Size    Field
──────────────────────────────────
0x0000    1 byte  Magic byte (0xA5 = valid config present)
0x0001    2 bytes Temperature setpoint (s16, little-endian)
0x0003    1 byte  Humidity setpoint (u8)
0x0004    1 byte  Password length (u8)
0x0005    5 bytes Password string (null-terminated)
──────────────────────────────────
Total:    10 bytes per config block
```

If the magic byte is not `0xA5` on boot, `EEPROM_LoadConfig()` writes factory defaults and returns `0` (false).

</details>

<details>
<summary><strong>ESP-01 AT Command Sequence</strong></summary>

```
Boot:
    AT+RST                          → Reset module
    AT+CWMODE=1                     → Station mode
    AT+CWJAP="SSID","PASSWORD"      → Join access point

Each Update (every 60s):
    AT+CIPSTART="TCP","api.thingspeak.com",80
    AT+CIPSEND=<length>
    GET /update?api_key=<KEY>&field1=<T>&field2=<H>&field3=<D>&field4=<A>\r\n\r\n
    AT+CIPCLOSE
```

</details>

---

## 👨‍💻 Author

**Mihir** — ARM Embedded Systems Major Project

| | |
|---|---|
| **Project** | ColdGuard — IoT Cold Storage Monitor |
| **Platform** | NXP LPC2148 (ARM7TDMI-S) |
| **IDE** | Keil µVision4 |
| **Cloud** | ThingSpeak IoT Platform |
| **Language** | Embedded C (ANSI C89) |

---

## 📄 License

This project is developed for **academic and educational purposes** as part of a Major Project in ARM Embedded Systems.

---

<p align="center">
  <strong>Built with ❤️ on ARM7 — ColdGuard keeps the cold in check.</strong>
</p>
