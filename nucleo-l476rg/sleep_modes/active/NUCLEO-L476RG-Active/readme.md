# NUCLEO-L476RG – Active Mode Stromverbrauchstest

Dieses Projekt misst den Stromverbrauch des STM32L476RG im aktiven Betriebsmodus bei 80 MHz Systemtakt. Der Mikrocontroller führt eine dauerhaft laufende Schleife mit einer Dummy-Berechnung aus, um die CPU konstant zu beschäftigen.

## Testverhalten

- Die SystemClock ist auf 80 MHz konfiguriert (über PLL)
- Die CPU führt eine leere Schleife mit hoher Auslastung aus
- Sleep-, Stop- oder Standby-Modi sind nicht aktiviert
- Ziel ist die Messung des typischen Verbrauchs im aktiven Zustand

## Entwicklungsumgebung

- IDE: STM32CubeIDE
- HAL-Treiber: STM32CubeL4
- Mikrocontroller: STM32L476RG (NUCLEO-Board)
- Debug: deaktiviert (für reale Stromverbrauchsmessung)

## Projektstruktur

Typische Dateien des STM32CubeIDE-Projekts:

active_mode/
├── Core/
│ ├── Inc/
│ │ └── main.h
│ └── Src/
│ └── main.c
├── Drivers/
├── .ioc (CubeMX-Konfiguration)
├── .project / .cproject (IDE-Projektdateien)
└── README.md


## Codeausschnitt (Hauptfunktion)

```c
int main(void)
{
  HAL_Init();
  SystemClock_Config();  // 80 MHz konfigurieren
  MX_GPIO_Init();

  while (1)
  {
    for (volatile uint32_t i = 0; i < 1000000; i++) {
      // keine Aktion, reine CPU-Auslastung
    }
  }
}

Hinweise zur Konfiguration

Clock Source: PLL auf 80 MHz (über HSE oder HSI)
Keine aktive Peripherie (UART, ADC etc.)
GPIO in Default-Status (konfiguriert über MX_GPIO_Init)
USB-Debugverbindung sollte während der Messung getrennt sein
