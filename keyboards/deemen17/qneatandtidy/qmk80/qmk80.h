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
#pragma once

#include "quantum.h"

#ifdef VIA_ENABLE
// custom ID codes
enum via_indicator_value {
    id_caps_lock_enable = 1,
    id_caps_lock_brightness,
    id_caps_lock_color,
    id_caps_lock_key,
    id_caps_lock_override,
    id_scroll_lock_enable,
    id_scroll_lock_brightness,
    id_scroll_lock_color,
    id_scroll_lock_key,
    id_scroll_lock_override
};

// struct to save things
typedef struct {
    bool enable_caps_lock:1;            // |
    bool enable_scroll_lock:1;          // |
    bool caps_override_bl:1;            // |
    bool scroll_override_bl:1;          // 1 byte
    HSV caps_lock_indicator;    // 3 bytes
    HSV scroll_lock_indicator;  // 3 bytes
    uint8_t caps_lock_key;      // 1 byte
    uint8_t scroll_lock_key;    // 1 byte
} indicator_settings_config;
// total 9 bytes

// function declaration
void indicator_config_set_value( uint8_t *data );
void indicator_config_get_value( uint8_t *data );
void indicator_config_save ( void );
void _set_color(HSV *color, uint8_t *data);
void _get_color(HSV *color, uint8_t *data);
#endif