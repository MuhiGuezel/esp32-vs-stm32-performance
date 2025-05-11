/**
 * @file main.c
 * @brief GPIO-Toggle-Geschwindigkeitstest für ESP32-C3
 *
 * Dieses Programm misst die maximale Toggle-Frequenz eines digitalen GPIO-Pins,
 * indem er in einer Dauerschleife direkt über das Low-Level-HAL (gpio_ll) gesetzt
 * und gelöscht wird. Dadurch wird der Overhead des Treibermodells umgangen und
 * die theoretisch maximale GPIO-Schaltgeschwindigkeit ermittelt.
 *
 * Verwendeter Pin: GPIO_NUM_3
 *
 * Hinweis: Dieser Code erzeugt ein Rechtecksignal mit minimaler Periodendauer,
 * das per Oszilloskop gemessen werden sollte.
 *
 * Verwendete ESP-IDF Version: 5.2.2
 * Mikrocontroller: ESP32-C3 Mini-1
 * Autor: Muhammed Güzel
 * Datum: Mai 2025
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "hal/gpio_ll.h"

#define TOGGLE_GPIO GPIO_NUM_3

void app_main(void) {
    gpio_set_direction(TOGGLE_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_ll_set_level(&GPIO, TOGGLE_GPIO, 1);
        gpio_ll_set_level(&GPIO, TOGGLE_GPIO, 0);
    }
}
