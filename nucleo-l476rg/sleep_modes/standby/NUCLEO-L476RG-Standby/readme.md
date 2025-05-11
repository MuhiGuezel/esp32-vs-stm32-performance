# NUCLEO-L476RG – Standby-Modus Stromverbrauchstest (mit RTC-Wakeup)

Dieses Projekt misst den Stromverbrauch des STM32L476RG im STANDBY-Modus mit Wakeup über den RTC-Wakeup-Timer nach 10 Sekunden.

## Testverhalten

- Der Mikrocontroller wird direkt in den STANDBY-Modus versetzt
- Wakeup erfolgt über den RTC-Wakeup-Timer (10 Sekunden, 1 Hz Takt)
- Nach Wakeup führt der Mikrocontroller einen vollständigen Reset durch
- Das PWR_FLAG_SB wird ausgelesen, um den STANDBY-Reset zu erkennen
- Kein SystemClock-Recovery erforderlich, da kompletter Neustart erfolgt

## Entwicklungsumgebung

- IDE: STM32CubeIDE
- HAL-Treiber: STM32CubeL4
- Mikrocontroller: STM32L476RG (NUCLEO-Board)
- Debug: deaktiviert (für realistische Stromverbrauchsmessung)

## .ioc-Einstellungen (wichtig)

### Clock Configuration:
- SYSCLK: 80 MHz (PLL mit HSI)
- RTC Clock Source: LSI (empfohlen für autarke Funktion)
- Wakeup Clock: CK_SPRE (1 Hz, 16-Bit Modus)

### RTC:
- RTC aktiviert
- Wakeup-Timer aktiviert
- RTC Wakeup Interrupt aktiviert (NVIC)

### Power Settings:
- Low Power Mode Support: aktiviert
- STANDBY-Mode ausgewählt über `HAL_PWR_EnterSTANDBYMode()`
- Reglerkonfiguration wird automatisch ignoriert, da STANDBY alles deaktiviert

## Projektstruktur

standby_mode/
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
    MX_RTC_Init();

    if (__HAL_PWR_GET_FLAG(PWR_FLAG_SB)) {
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);  // Flag löschen nach STANDBY
        HAL_Delay(100);  // Debug-Zeit nach Reset
    }

    HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);
    HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 10, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);

    HAL_PWR_EnterSTANDBYMode();  // System geht in STANDBY
}

Hinweise zur Strommessung

Board: NUCLEO-L476RG
ST-Link: vom Board trennen oder JP6/JP7 durchtrennen
Messung direkt zwischen VDD und VSS
Idealerweise VDD über Shunt/Power Analyzer einspeisen