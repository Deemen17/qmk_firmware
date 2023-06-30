/* Copyright 2023 Deemen17 <https://github.com/Deemen17>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
// First row
    {0, CS15_SW1, CS14_SW1, CS13_SW1},  // 0
    {0, CS15_SW2, CS14_SW2, CS13_SW2},  // 1
    {0, CS15_SW3, CS14_SW3, CS13_SW3},  // 2
    {0, CS15_SW4, CS14_SW4, CS13_SW4},  // 3
    {0, CS15_SW5, CS14_SW5, CS13_SW5},  // 4
    {0, CS15_SW6, CS14_SW6, CS13_SW6},  // 5 
    {0, CS15_SW7, CS14_SW7, CS13_SW7},  // 6
    {0, CS15_SW8, CS14_SW8, CS13_SW8},  // 7 
    {0, CS18_SW9, CS17_SW9, CS16_SW9},  // 8
    {0, CS18_SW8, CS17_SW8, CS16_SW8},  // 9
    {0, CS18_SW7, CS17_SW7, CS16_SW7},  // 10
    {0, CS18_SW6, CS17_SW6, CS16_SW6},  // 11
    {0, CS18_SW5, CS17_SW5, CS16_SW5},  // 12
    {0, CS18_SW4, CS17_SW4, CS16_SW4},  // 13
    {0, CS18_SW3, CS17_SW3, CS16_SW3},  // 14
// Second row
    {0, CS12_SW1, CS11_SW1, CS10_SW1},  // 15
    {0, CS12_SW2, CS11_SW2, CS10_SW2},  // 16
    {0, CS12_SW3, CS11_SW3, CS10_SW3},  // 17
    {0, CS12_SW4, CS11_SW4, CS10_SW4},  // 18
    {0, CS12_SW5, CS11_SW5, CS10_SW5},  // 19
    {0, CS12_SW6, CS11_SW6, CS10_SW6},  // 20
    {0, CS12_SW7, CS11_SW7, CS10_SW7},  // 21
    {0, CS12_SW8, CS11_SW8, CS10_SW8},  // 22
    {0, CS21_SW9, CS20_SW9, CS19_SW9},  // 23
    {0, CS21_SW8, CS20_SW8, CS19_SW8},  // 24
    {0, CS21_SW7, CS20_SW7, CS19_SW7},  // 25
    {0, CS21_SW6, CS20_SW6, CS19_SW6},  // 26
    {0, CS21_SW5, CS20_SW5, CS19_SW5},  // 27
    {0, CS21_SW4, CS20_SW4, CS19_SW4},  // 28
    {0, CS21_SW3, CS20_SW3, CS19_SW3},  // 29
// Third row
    {0, CS9_SW1, CS8_SW1, CS7_SW1},  // 30
    {0, CS9_SW2, CS8_SW2, CS7_SW2},  // 31
    {0, CS9_SW3, CS8_SW3, CS7_SW3},  // 32
    {0, CS9_SW4, CS8_SW4, CS7_SW4},  // 33
    {0, CS9_SW5, CS8_SW5, CS7_SW5},  // 34
    {0, CS9_SW6, CS8_SW6, CS7_SW6},  // 35
    {0, CS9_SW7, CS8_SW7, CS7_SW7},  // 36
    {0, CS9_SW8, CS8_SW8, CS7_SW8},  // 37
    {0, CS24_SW9, CS23_SW9, CS22_SW9},  // 38
    {0, CS24_SW8, CS23_SW8, CS22_SW8},  // 39
    {0, CS24_SW7, CS23_SW7, CS22_SW7},  // 40
    {0, CS24_SW6, CS23_SW6, CS22_SW6},  // 41
    {0, CS24_SW4, CS23_SW4, CS22_SW4},  // 42
    {0, CS24_SW3, CS23_SW3, CS22_SW3},  // 43
// Forth row
    {0, CS6_SW1, CS5_SW1, CS4_SW1},  // 44
    {0, CS6_SW3, CS5_SW3, CS4_SW3},  // 45
    {0, CS6_SW4, CS5_SW4, CS4_SW4},  // 46
    {0, CS6_SW5, CS5_SW5, CS4_SW5},  // 47
    {0, CS6_SW6, CS5_SW6, CS4_SW6},  // 48
    {0, CS6_SW7, CS5_SW7, CS4_SW7},  // 49
    {0, CS6_SW8, CS5_SW8, CS4_SW8},  // 50
    {0, CS27_SW9, CS26_SW9, CS25_SW9},  // 51
    {0, CS27_SW8, CS26_SW8, CS25_SW8},  // 52
    {0, CS27_SW7, CS26_SW7, CS25_SW7},  // 53
    {0, CS27_SW6, CS26_SW6, CS25_SW6},  // 54
    {0, CS27_SW5, CS26_SW5, CS25_SW5},  // 55
    {0, CS27_SW4, CS26_SW4, CS25_SW4},  // 56
    {0, CS27_SW3, CS26_SW3, CS25_SW3},  // 57
// Fifth row
    {0, CS3_SW1, CS2_SW1, CS1_SW1},  // 58
    {0, CS3_SW2, CS2_SW2, CS1_SW2},  // 59
    {0, CS3_SW4, CS2_SW4, CS1_SW4},  // 60
    {0, CS3_SW7, CS2_SW7, CS1_SW7},  // 61
    {0, CS30_SW7, CS29_SW7, CS28_SW7},  // 62
    {0, CS30_SW6, CS29_SW6, CS28_SW6},  // 63
    {0, CS30_SW5, CS29_SW5, CS28_SW5},  // 64
    {0, CS30_SW4, CS29_SW4, CS28_SW4},  // 65
    {0, CS30_SW3, CS29_SW3, CS28_SW3},  // 66
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_INDICATOR) {
                rgb_matrix_set_color(i, RGB_WHITE);
            }
        }
    }
    return false;
}

#endif