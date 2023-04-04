/* Copyright 2023 deemen17
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,          KC_ESC,           KC_TAB,  KC_Q,    KC_W,   KC_E, KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_DEL,  KC_BSPC,
        KC_P4,   KC_P5,   KC_P6,                            KC_CAPS, KC_A,    KC_S,   KC_D, KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_BSLS, KC_ENT,
        KC_P1,   KC_P2,   KC_P3,          KC_UP,            KC_LSFT,          KC_Z,   KC_X, KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_P0,   KC_PDOT,       KC_LEFT,  KC_DOWN, KC_RGHT, KC_LCTL, KC_LALT, KC_SPC,       KC_SPC, KC_SPC, KC_SPC,                  KC_SPC,  KC_RALT, KC_RCTL, MO(1)
    ),
    [1] = LAYOUT(
        _______, _______, _______,        _______,          _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        _______, _______, _______,                          _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,        KC_VOLU,          _______,          RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,       _______,  KC_VOLD, _______, _______, _______, _______,      _______,  _______, _______,                      _______, _______, QK_BOOT, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______,        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,        _______,          _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,       _______,  _______, _______, _______, _______, _______,      _______,  _______, _______,                      _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______,        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,        _______,          _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,       _______,  _______, _______, _______, _______, _______,      _______,  _______, _______,                      _______, _______, _______, _______
    )
};

// Encoder
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [2] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
};
#endif


