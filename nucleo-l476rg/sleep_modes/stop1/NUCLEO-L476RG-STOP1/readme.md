# NUCLEO-L476RG – STOP1-Modus Stromverbrauchstest (mit RTC-Wakeup)

Dieses Projekt misst den Stromverbrauch des STM32L476RG im STOP1-Modus bei Wakeup über den RTC-Wakeup-Timer nach ca. 10 Sekunden.

## Testverhalten

- Der Mikrocontroller wird regelmäßig in den STOP1-Modus versetzt
- Wakeup erfolgt über den RTC-Wakeup-Timer nach 10 Sekunden
- Die SystemClock wird nach jedem Wakeup erneut initialisiert
- Der SysTick-Timer wird vor dem Sleep deaktiviert und nach dem Wakeup reaktiviert

## Entwicklungsumgebung

- IDE: STM32CubeIDE
- HAL-Treiber: STM32CubeL4
- Mikrocontroller: STM32L476RG (NUCLEO-Board)
- Debug: deaktiviert (für Strommessung)

## .ioc-Einstellungen (wichtig)

Folgende Einstellungen müssen im .ioc-File korrekt gesetzt sein:

### Clock Configuration:
- System Clock Source: PLLCLK
- PLL Source: HSE oder HSI (konfiguriert auf 80 MHz)
- RTC Clock Mux: LSI (empfohlen für autarke Funktion)
- WakeUp Timer Clock: CK_SPRE (1 Hz, 16-Bit)

### RTC:
- Aktiviert (Asynchronous Mode)
- Wakeup-Timer: aktiviert
- NVIC: RTC Wakeup Interrupt aktiviert

### Power Settings:
- Low Power Mode Support: aktiviert
- Stop Mode Entry: über WFI (`HAL_PWR_EnterSTOPMode(...)`)
- Regulator: Low Power Regulator aktiviert

## Projektstruktur

stop_mode/
├── Core/
│ ├── Inc/
│ │ └── main.h
│ └── Src/
│ └── main.c
├── Drivers/
├── .ioc (CubeMX-Konfiguration)
├── .project / .cproject
└── README.md


## Codeausschnitt

```c
int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_RTC_Init();

    while (1) {
        HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);
        HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 10, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);

        HAL_SuspendTick();
        HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
        HAL_ResumeTick();

        SystemClock_Config();  // Nach STOP1 wiederherstellen
    }
}

Hinweise zur Strommessung

Board: NUCLEO-L476RG
Messung erfolgt zwischen VDD (Messpunkt JP6/JP7) und LDO-Eingang
ST-Link sollte für die Messung getrennt sein (ST-Link-Teil abtrennen oder VDD-Messbrücke entfernen)
