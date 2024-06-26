// Copyright Kumao Kobo <kumaokobo@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NUMB 2

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)
#define NUM_L   MO(_NUMB)

#define KC_ALES LALT_T(KC_ESC)

#define KC_RGENT MT(KC_RGUI, KC_ENT)
#define KC_LGUI2 RALT_T(KC_LNG2)

#define KC_L1SYM LT(_SYMB, KC_LNG1)
#define KC_L2SYM LT(_SYMB, KC_LNG2)

#define KC_L1NUM LT(_NUMB, KC_LNG1)
#define KC_ENNUM LT(_NUMB, KC_ENT)

#define KC_FSYM LT(_SYMB, KC_F)
#define KC_JNUM LT(_NUMB, KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                   KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_L2SYM,                 KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_SLSH ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘                └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_FSYM ,KC_G    ,                                   KC_H    ,KC_JNUM ,KC_K    ,KC_L    ,KC_SCLN ,KC_ENT  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                                   KC_L1NUM,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                ┌────────┼────────┼────────┴────────┼────────┼────────┼────────┤
     KC_ALES ,KC_QUOT ,KC_MINS ,KC_EQL  ,KC_ENNUM,KC_LGUI ,KC_SPC  ,                 KC_RGENT,KC_DEL  ,SYM_L   ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┘                └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                   KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_DQUO ,KC_QUOT ,KC_GRV  ,KC_ASTR ,KC_PLUS ,KC_EQL  ,                 KC_LPRN ,KC_RPRN ,KC_PIPE ,KC_ASTR ,KC_TILD ,KC_CIRC ,KC_INT3 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘                └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_AT   ,KC_COLN ,KC_GRV  ,_______ ,KC_MINS ,                                   KC_LBRC ,KC_RBRC ,KC_DOT  ,KC_SLSH ,KC_MINS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_DOT  ,KC_SLSH ,                                   _______ ,KC_LCBR ,KC_RCBR ,KC_DOT  ,KC_SLSH ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                ┌────────┼────────┼────────┴────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                 _______ ,_______ ,_______ ,KC_LT   ,KC_UNDS ,KC_CIRC ,KC_GT
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┘                └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_NUMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_7    ,KC_8    ,KC_9    ,KC_ASTR ,KC_PLUS ,KC_EQL  ,                 XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘                └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_4    ,KC_5    ,KC_6    ,KC_0    ,KC_MINS ,                                   XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_1    ,KC_2    ,KC_3    ,KC_DOT  ,KC_SLSH ,                                   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                ┌────────┼────────┼────────┴────────┼────────┼────────┼────────┤
     _______ ,KC_INT3 ,KC_0    ,_______ ,_______ ,_______ ,_______ ,                 XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴────────┴────────┘                └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  )

};
