# ESP32 vs STM32 – Performance- und Stromverbrauchsanalyse

Dieses Repository enthält alle entwickelten Testprogramme zur Analyse und zum Vergleich von **Leistungsfähigkeit** und **Energieverbrauch** zweier Mikrocontroller:

- **ESP32-C3 (RISC-V, 80 MHz, ESP-IDF)**
- **STM32L476RG (ARM Cortex-M4, 80 MHz, STM32CubeIDE)**

Die Tests wurden im Rahmen der Bachelorarbeit von Muhammed Güzel durchgeführt.

---

## 🔧 Aufbau des Repositories

Das Projekt ist in zwei Hauptbereiche unterteilt – je Mikrocontroller:

esp32-vs-stm32-performance/
├── esp32-c3/
│ ├── active/
│ ├── light_sleep/
│ ├── deep_sleep/
│ ├── gpio_toggle_speed/
│ ├── pwm_quality/
│ ├── interrupt_latency/
│ └── coremark/
│
├── nucleo-l476rg/
│ ├── active_mode/
│ ├── stop_mode/
│ ├── standby_mode/
│ ├── pwm_quality/
│ ├── gpio_toggle_speed/
│ └── interrupt_latency/


Jeder Unterordner enthält:

- Eine vollständig lauffähige Projektstruktur
- Einen eigenen `README.md` mit Testbeschreibung
- Header-Kommentare im Code mit Erklärungen
- `.ioc`-Dateien bei STM32-Projekten

---

## 📋 Ziel der Tests

Die entwickelten Programme wurden eingesetzt zur:

- Vergleichsmessung des Stromverbrauchs (Active / Light / Deep / Stop / Standby)
- Beurteilung von PWM-Signalqualität (bei geringen Duty-Cycles)
- Bestimmung von GPIO-Toggle-Geschwindigkeiten
- Messung von Interrupt-Latenzen
- Vergleich der CoreMark-Leistung (Standardbenchmark)

---

## 🛠️ Entwicklungsumgebungen

| Plattform   | Toolchain         | Taktfrequenz | Sprache |
|-------------|-------------------|--------------|---------|
| ESP32-C3    | ESP-IDF v5.2.2     | 80 MHz       | C       |
| STM32L476RG | STM32CubeIDE (HAL)| 80 MHz       | C       |

---

## Lizenz und Hinweise

- Die CoreMark-Benchmark-Quellen stammen aus dem offiziellen EEMBC-Repository: [https://github.com/eembc/coremark](https://github.com/eembc/coremark)
- Alle anderen Codes wurden im Rahmen der Bachelorarbeit von Muhammed Güzel entwickelt.

---

## Hinweis zur Verwendung

Vor dem Build bitte sicherstellen:

- Der korrekte Port und das passende Board sind ausgewählt (ESP32 / STM32)
- Debugging und UART ggf. deaktivieren, wenn Strom gemessen wird
- Peripherie in `.ioc`-Dateien ggf. anpassen (bei STM32)

---

## Bachelorarbeit

Die vollständige Dokumentation, Analyse und Auswertung ist in der Bachelorarbeit enthalten.

