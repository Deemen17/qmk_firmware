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
  {   0,      1,      2,      3}
}, {
  // LED Index to Physical Position

  // Caps Lock Indicator and 3 Nav  (0 -> 3)
  { 0,0  }, { 0,13 }, { 0,26 }, { 19,28 }, 

  // Underglow (4 -> 34)
  {  0,32 }, {  0,44 }, { 0,53  }, {  0,64  }, 
  { 23,64 }, { 46,64 }, { 69,64 }, { 92,64  }, { 116,64 }, { 139,64 }, { 160,64 }, { 179,64 }, { 203,64 }, 
  {224,64 }, {224,53 }, {224,43 }, { 224,33 }, { 224,23 }, { 224,7  }, 
  { 224,0 }, {199,0  }, {174,0  }, { 148,0  }, { 123,0  }, {  98,0  }, {  74,0  }, {  55,0  }, {  29,0  }, {  10,0  }, 
  {   0,0 }, {  0,20 },

}, {
  // LED Index to Flag
  8, 4, 4, 4, 
  
  2, 2, 2, 2, 
  2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2,
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 255, 255);
    } else if (!(rgb_matrix_get_flags() & LED_FLAG_INDICATOR)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }

    return true;
}

#endif //RGB_MATRIX_ENABLE
