/*
Copyright 2023 Deemen17

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
#include "quantum.h"
#include "rev1.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0,      1},
  {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
  {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
  // LED Index to Physical Position
  {211,0  }, {  5,40 },
  {  0,0  }, { 30,0  }, { 60,0  }, { 80,0  }, {120,0  }, {150,0  }, {180,0  }, {210,0  },
  {  0,20 },                                                                   {210,20 },
  {  0,45 },                                                                   {210,45 },
  {  0,64 }, { 30,64 }, { 60,64 }, { 80,64 }, {120,64 }, {150,64 }, {180,64 }, {210,64 },
}, {
  // LED Index to Flag
  8, 8, 
  2, 2, 2, 2, 2, 2, 2, 2,
  2,                   2,
  2,                   2,
  2, 2, 2, 2, 2, 2, 2, 2
} };

#ifdef VIA_ENABLE
#include "eeprom.h"

indicator_settings_config g_config = {
    .caps_lock_indicator = {0, 0, 128},
    .scroll_lock_indicator = {120, 0, 128},
    .caps_lock_key = 1,
    .scroll_lock_key = 0,
    .enable_caps_lock = true,
    .enable_scroll_lock = true,
    .caps_override_bl = true,
    .scroll_override_bl = true
};

void values_load(void)
{
    eeprom_read_block( &g_config, ((void*)VIA_EEPROM_CUSTOM_CONFIG_ADDR), sizeof(g_config) );
}

void values_save(void)
{
    eeprom_update_block( &g_config, ((void*)VIA_EEPROM_CUSTOM_CONFIG_ADDR), sizeof(g_config) );
}

void via_init_kb(void)
{
    // If the EEPROM has the magic, the data is good.
    // OK to load from EEPROM
    if (via_eeprom_is_valid()) {
        values_load();
    } else	{
        values_save();
        // DO NOT set EEPROM valid here, let caller do this
    }
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if ( *channel_id == id_custom_channel ) {
        switch ( *command_id )
        {
            case id_custom_set_value:
            {
                indicator_config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value:
            {
                indicator_config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save:
            {
                values_save();
                break;
            }
            default:
            {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    // Return the unhandled state
    *command_id = id_unhandled;

    // DO NOT call raw_hid_send(data,length) here, let caller do this
}

void indicator_config_set_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id )
    {
        case id_caps_lock_enable:
            g_config.enable_caps_lock = *value_data;
            break;
        case id_scroll_lock_enable:
            g_config.enable_scroll_lock = *value_data;
            break;
        case id_caps_lock_brightness:
            g_config.caps_lock_indicator.v = *value_data;
            break;
        case id_scroll_lock_brightness:
            g_config.scroll_lock_indicator.v = *value_data;
            break;
        case id_caps_lock_color:
            _set_color( &(g_config.caps_lock_indicator), value_data );
            break;
        case id_scroll_lock_color:
            _set_color( &(g_config.scroll_lock_indicator), value_data );
            break;
        case id_caps_lock_key:
            g_config.caps_lock_key = *value_data;
            break;
        case id_scroll_lock_key:
            g_config.scroll_lock_key = *value_data;
            break;
        case id_caps_lock_override:
            g_config.caps_override_bl = *value_data;
            break;
        case id_scroll_lock_override:
            g_config.scroll_override_bl = *value_data;
            break;
    }
}

void indicator_config_get_value( uint8_t *data )
{
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id )
    {
        case id_caps_lock_enable:
            *value_data = g_config.enable_caps_lock;
            break;
        case id_scroll_lock_enable:
            *value_data = g_config.enable_scroll_lock;
            break;
        case id_caps_lock_brightness:
            *value_data = g_config.caps_lock_indicator.v;
            break;
        case id_scroll_lock_brightness:
            *value_data = g_config.scroll_lock_indicator.v;
            break;
        case id_caps_lock_color:
            _get_color( &(g_config.caps_lock_indicator), value_data );
            break;
        case id_scroll_lock_color:
            _get_color( &(g_config.scroll_lock_indicator), value_data );
            break;
        case id_caps_lock_key:
            *value_data = g_config.caps_lock_key;
            break;
        case id_scroll_lock_key:
            *value_data = g_config.scroll_lock_key;
            break;
        case id_caps_lock_override:
            *value_data = g_config.caps_override_bl;
            break;
        case id_scroll_lock_override:
            *value_data = g_config.scroll_override_bl;
            break;
    }
}

// Some helpers for setting/getting HSV
void _set_color( HSV *color, uint8_t *data )
{
    color->h = data[0];
    color->s = data[1];
}

void _get_color( HSV *color, uint8_t *data )
{
    data[0] = color->h;
    data[1] = color->s;
}

// Set the indicators with RGB Matrix subsystem
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    // caps lock cyan
    if (g_config.enable_caps_lock) {
        RGB rgb_caps = hsv_to_rgb( (HSV){ .h = g_config.caps_lock_indicator.h,
                                          .s = g_config.caps_lock_indicator.s,
                                          .v = g_config.caps_lock_indicator.v } );
        if (host_keyboard_led_state().caps_lock) {
            RGB_MATRIX_INDICATOR_SET_COLOR(g_config.caps_lock_key, rgb_caps.r, rgb_caps.g, rgb_caps.b);
        } else {
            if (g_config.caps_override_bl) {
                RGB_MATRIX_INDICATOR_SET_COLOR(g_config.caps_lock_key, 0, 0, 0);
            }
        }
    }

    // scroll lock cyan
    if (g_config.enable_scroll_lock) {
        RGB rgb_scroll = hsv_to_rgb( (HSV){ .h = g_config.scroll_lock_indicator.h,
                                            .s = g_config.scroll_lock_indicator.s,
                                            .v = g_config.scroll_lock_indicator.v } );
        if (host_keyboard_led_state().scroll_lock) {
            RGB_MATRIX_INDICATOR_SET_COLOR(g_config.scroll_lock_key, rgb_scroll.r, rgb_scroll.g, rgb_scroll.b);
        } else {
            if (g_config.scroll_override_bl) {
                RGB_MATRIX_INDICATOR_SET_COLOR(g_config.scroll_lock_key, 0, 0, 0);
            }
        }
    }

    return false;
}

#endif //VIA_ENABLE


#endif //RGB_MATRIX_ENABLE

