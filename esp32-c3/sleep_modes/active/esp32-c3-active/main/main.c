/**
 * @file main.c
 * @brief Active Mode Stromverbrauchstest für ESP32-C3
 *
 * Dieses Programm konfiguriert den ESP32-C3 auf einen konstant aktiven Zustand
 * bei fester Taktrate von 80 MHz. Funkmodule (Wi-Fi/Bluetooth) werden deaktiviert,
 * und Light Sleep wird explizit ausgeschaltet.
 *
 * Ziel ist es, den Stromverbrauch im Dauerbetrieb als Referenz zu messen.
 *
 * Verwendete ESP-IDF Version: 5.2.2
 * Mikrocontroller: ESP32-C3 Mini-1
 * Autor: Muhammed Güzel
 * Datum: Mai 2025
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_pm.h"
#include "esp_wifi.h"

void configure_power_management() {
    esp_pm_config_esp32c3_t pm_config = {
        .max_freq_mhz = 80,   // 80 MHz fest eingestellt
        .min_freq_mhz = 80,
        .light_sleep_enable = false
    };
    esp_pm_configure(&pm_config);
}

void disable_funk() {
    esp_wifi_stop();
    esp_wifi_deinit();
    // Bluetooth-Funktionen entfernt
}

void app_main(void) {
    configure_power_management();
    disable_funk();

    while (1) {
        // CPU dauerhaft beschäftigt halten
        for (volatile int i = 0; i < 1000; i++);
    }
}
