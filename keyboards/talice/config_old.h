/*
Copyright 2021 LQT

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

#pragma once

#include "config_common.h"


/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { B5, D7, D4, B7, D2 }
#define MATRIX_COL_PINS { F6, F7, E2, C7, C6, B6, D6, B4, B2, B1, B0, E6, F0, F1, F4 }
/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_B { D5 }
#define ENCODERS_PAD_A { D3 }

#define USB_POLLING_INTERVAL_MS 1


#define FORCE_NKRO

/* disable these deprecated features by default */
// #define NO_ACTION_TAPPING
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
//#define NO_MUSIC_MODE

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0kbd
//#define BOOTMAGIC_LITE_COLUMN 0
