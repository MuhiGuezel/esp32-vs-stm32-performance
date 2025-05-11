/**
 * @file main.c
 * @brief Light Sleep Stromverbrauchstest für ESP32-C3
 *
 * Dieses Programm versetzt den ESP32-C3 alle 10 Sekunden in den Light-Sleep-Modus.
 * Die CPU wird angehalten, jedoch bleiben ausgewählte Peripherien aktiv.
 *
 * Ziel ist es, den Stromverbrauch im Light Sleep zu ermitteln und mit
 * Active- und Deep-Sleep-Werten zu vergleichen.
 *
 * Verwendete ESP-IDF Version: 5.2.2
 * Mikrocontroller: ESP32-C3 Mini-1
 * Autor: Muhammed Güzel
 * Datum: Mai 2025
 */

#include "esp_sleep.h"
#include "esp_log.h"

void app_main(void) {
    while (1) {
        esp_sleep_enable_timer_wakeup(10 * 1000000); // 10 Sekunden
        esp_light_sleep_start();

    }
}
