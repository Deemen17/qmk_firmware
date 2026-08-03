/* Copyright 2024 Deemen17 <https://github.com/Deemen17>
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

#pragma once

// ── VIA custom EEPROM size ────────────────────────────────────────────────────
// Kích thước vùng lưu ext_led_state_t = 9 bytes (xem rev2.h)
// VIA_EEPROM_CUSTOM_CONFIG_ADDR được via.h định nghĩa tự động dựa vào size này.
// Fallback nếu QMK version chưa có: xem rev2.h
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE  4
#define DYNAMIC_KEYMAP_LAYER_COUNT     2

// EECONFIG: 5 indicator_config × 6 bytes + 66 perled_config × 4 bytes = 294 bytes
// #define EECONFIG_KB_DATA_SIZE (66 * 4)

// #define WEAR_LEVELING_LOGICAL_SIZE 2048
// #define WEAR_LEVELING_BACKING_SIZE 4096