// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   =  |                    |   -  |   6  |   7  |   8  |   9  |   0  |Backsp|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |      |                    |   [  |   Y  |   U  |   I  |   O  |   P  |  ]   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Raise|   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  ||||||||  Del |      |      ||||||||   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |  `   |  \   |  ALt | Ctrl |||||||| Lower| Space|  LGui|||||||| Enter| Space| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
    [0] = LAYOUT(
        KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,                        KC_MINS, KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   XXXXXXX,                        KC_LBRC, KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_RBRC,
         MO(1),     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX,                        XXXXXXX, KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
       KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_DEL,        KC_PSCR,         KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_GRV,  KC_BSLS, KC_LALT, KC_LCTL,            MO(2),    KC_SPC, KC_LGUI,        KC_ENT ,KC_SPC , MO(1),          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
};
