/*
Copyright 2025 DEEMEN17 WORKS

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "full_rgb_tg.h"
#include "rgb_matrix.h"

// Caps Lock Indicator
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_WHITE);
            }
        }
    }
    return false;
}

// Process commands from VIA
void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    if (data[1] == id_custom_channel) {
        switch (data[0]) {
            case id_custom_set_value:
                rgb_matrix_config_set_value(&data[2]);
                break;
            case id_custom_get_value:
                rgb_matrix_config_get_value(&data[2]);
                break;
            case id_custom_save:
                rgb_matrix_config_save();
                break;
            default:
                data[0] = id_unhandled;
        }
        return;
    }
    data[0] = id_unhandled;
}

// Set values
void rgb_matrix_config_set_value(uint8_t *data) {
    switch (data[0]) {
        case id_rgb_matrix_bl_toggle:
            g_custom_rgb_matrix_config.bl_enabled = data[1];
            break;
        case id_rgb_matrix_ug_toggle:
            g_custom_rgb_matrix_config.ug_enabled = data[1];
            break;
    }
    rgb_matrix_config_save();
    update_rgb_matrix();
}

// Get values
void rgb_matrix_config_get_value(uint8_t *data) {
    switch (data[0]) {
        case id_rgb_matrix_bl_toggle:
            data[1] = g_custom_rgb_matrix_config.bl_enabled;
            break;

        case id_rgb_matrix_ug_toggle:
            data[1] = g_custom_rgb_matrix_config.ug_enabled;
            break;
    }
}
// Save values to EEPROM
void rgb_matrix_config_save(void) {
    uint32_t eeprom_data = 0;

    eeprom_data |= g_custom_rgb_matrix_config.bl_enabled ? (1 << 0) : 0;
    eeprom_data |= g_custom_rgb_matrix_config.ug_enabled ? (1 << 1) : 0;

    eeconfig_update_user(eeprom_data);
}

// Load state from EEPROM
void rgb_matrix_config_load(void) {
    uint32_t eeprom_data = eeconfig_read_user();

    g_custom_rgb_matrix_config.bl_enabled = (eeprom_data >> 0) & 0x1;
    g_custom_rgb_matrix_config.ug_enabled = (eeprom_data >> 1) & 0x1;
}

// Update BL LED and UG LED
void update_rgb_matrix(void) {
    uint8_t flags = 0;

    if (g_custom_rgb_matrix_config.bl_enabled) {
        flags |= LED_FLAG_KEYLIGHT;
        flags |= LED_FLAG_MODIFIER;
        flags |= LED_FLAG_INDICATOR;
    }

    if (g_custom_rgb_matrix_config.ug_enabled) {
        flags |= LED_FLAG_UNDERGLOW;
    }

    // Nếu không bật gì → tắt toàn bộ RGB Matrix
    if (flags == 0) {
        rgb_matrix_disable_noeeprom();
        return;
    }

    // Bật RGB Matrix
    rgb_matrix_enable_noeeprom();

    // Set filter flags cho EFFECT
    rgb_matrix_set_flags(flags);

    // Force refresh (cực kỳ quan trọng cho STATIC / VIA)
    rgb_matrix_mode_noeeprom(rgb_matrix_get_mode());
}

void keyboard_post_init_user(void) {
    if(!rgb_matrix_is_enabled()) {
        g_custom_rgb_matrix_config.bl_enabled = 0;
        g_custom_rgb_matrix_config.ug_enabled = 0;
        rgb_matrix_config_save();
        rgb_matrix_disable_noeeprom();
        return;
    }
    rgb_matrix_config_load();
    wait_ms(10);
    update_rgb_matrix();
}