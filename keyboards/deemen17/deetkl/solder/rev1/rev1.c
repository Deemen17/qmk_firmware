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

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0,      1},
  {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
  {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
  {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
  {   NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (host_keyboard_led_state().scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 255, 255);
    } else if (!(rgb_matrix_get_flags() & LED_FLAG_INDICATOR)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 255, 255, 255);
    } else if (!(rgb_matrix_get_flags() & LED_FLAG_INDICATOR)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 0);
    }

    return true;
}

#endif //RGB_MATRIX_ENABLE

