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

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS {GP29,  GP2, GP3, GP23, GP24}
#define MATRIX_COL_PINS {GP4, GP5, GP6, GP7, GP8, GP19, GP18, GP17, GP15, GP14, GP13, GP12, GP11, GP10, GP9}
// GP27 GP28GP22, GP21, GP20,

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Forcing to use NKRO instead 6KRO */
#define FORCE_NKRO

/* RP2040 reset config*/
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP1
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* RGB Lighting */
#define RGB_DI_PIN GP0
#ifdef RGB_DI_PIN
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLED_NUM 10
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 255
#    define RGBLIGHT_SLEEP
#endif

/* RGB led layers for indication */
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

/* Encoder */
#define ENCODERS_PAD_A { GP25 }
#define ENCODERS_PAD_B { GP26 }
#define ENCODER_RESOLUTION 2

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1
