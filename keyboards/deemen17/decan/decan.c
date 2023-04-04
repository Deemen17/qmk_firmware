/* Copyright 2023 Deemen17
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

#include "decan.h"

//Initialize all RGB indicators to 'off'
__attribute__((weak))
void keyboard_post_init_user(void) {
    rgblight_setrgb_at(0, 0, 0, 0); // capslock
    rgblight_set_effect_range(1, 43);
}

//Indicator light function
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        if (led_state.caps_lock) {
            rgblight_setrgb_at(255, 255, 255, 0);
        } else {
            rgblight_setrgb_at(0, 0, 0, 0);
        }
    }
    return res;
}