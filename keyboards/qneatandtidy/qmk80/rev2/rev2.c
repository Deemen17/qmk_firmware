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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {

/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
// First row 
    {0, I_4,   H_4,   G_4},  //LED1-K00-0
    {0, L_4,   K_4,   J_4},  //LED2-K01-1
    {0, C_4,   B_4,   A_4},  //LED3-K02-2
    {0, F_4,   E_4,   D_4},  //LED4-K03-3

    {0, I_7,   H_7,   G_7},  //LED5-K04-4
    {0, L_7,   K_7,   J_7},  //LED6-K05-5
    {0, C_7,   B_7,   A_7},  //LED7-K06-6
    {0, F_7,   E_7,   D_7},  //LED8-K07-7

    {1, A_3,   B_3,   C_3},  //LED9-K08-8
    {1, D_3,   E_3,   F_3},  //LED10-K09-9
    {1, G_3,   H_3,   I_3},  //LED11-K0A-10
    {1, J_3,   K_3,   L_3},  //LED12-K0B-11

    {1, A_6,   B_6,   C_6},  //LED13-K0C-12
    {1, D_6,   E_6,   F_6},  //LED14-K0D-13
    {1, G_6,   H_6,   I_6},  //LED15-K0E-14
    {1, J_6,   K_6,   L_6},  //LED16-K0F-15

    {1, J_11,  K_11,  L_11}, //LED17-K0G-16
//Second row
    {0, I_3,   H_3,   G_3},  //LED18-K10-17
    {0, L_3,   K_3,   J_3},  //LED19-K11-18
    {0, C_3,   B_3,   A_3},  //LED20-K12-19
    {0, F_3,   E_3,   D_3},  //LED21-K13-20

    {0, I_8,   H_8,   G_8},  //LED22-K14-21
    {0, L_8,   K_8,   J_8},  //LED23-K15-22
    {0, C_8,   B_8,   A_8},  //LED24-K16-23
    {0, F_8,   E_8,   D_8},  //LED25-K17-24

    {1, A_2,   B_2,   C_2},  //LED26-K18-25
    {1, D_2,   E_2,   F_2},  //LED27-K19-26
    {1, G_2,   H_2,   I_2},  //LED28-K1A-27
    {1, J_2,   K_2,   L_2},  //LED29-K1B-28

    {1, A_7,   B_7,   C_7},  //LED30-K1C-29
    {1, D_7,   E_7,   F_7},  //LED31-K1D-30
    {1, G_7,   H_7,   I_7},  //LED32-K1E-31
    {1, J_7,   K_7,   L_7},  //LED33-K1F-32

    {1, D_11,  E_11,  F_11}, //LED34-K1G-33
//Third row
    {0, I_2,   H_2,   G_2},  //LED35-K20-34
    {0, L_2,   K_2,   J_2},  //LED36-K21-35
    {0, C_2,   B_2,   A_2},  //LED37-K22-36
    {0, F_2,   E_2,   D_2},  //LED38-K23-37

    {0, I_9,   H_9,   G_9},  //LED39-K24-38
    {0, L_9,   K_9,   J_9},  //LED40-K25-39
    {0, C_9,   B_9,   A_9},  //LED41-K26-40
    {0, F_9,   E_9,   D_9},  //LED42-K27-41

    {1, A_3,   B_3,   C_3},  //LED43-K28-42
    {1, D_3,   E_3,   F_3},  //LED44-K29-43
    {1, G_3,   H_3,   I_3},  //LED45-K2A-44
    {1, J_3,   K_3,   L_3},  //LED46-K2B-45

    {1, A_8,   B_8,   C_8},  //LED47-K2C-46
    {1, D_8,   E_8,   F_8},  //LED48-K2D-47
    {1, G_8,   H_8,   I_8},  //LED49-K2E-48
    {1, J_8,   K_8,   L_8},  //LED50-K2F-49 
    
    {1, G_11,  H_11,  I_11}, //LED51-K2G-50
//Forth row
    {0, I_1,   H_1,   G_1},  //LED52-K30-51
    {0, L_1,   K_1,   J_1},  //LED53-K31-52
    {0, C_1,   B_1,   A_1},  //LED54-K32-53
    {0, F_1,   E_1,   D_1},  //LED55-K33-54

    {0, A_10,  B_10,  C_10}, //LED56-K34-55
    {0, D_10,  E_10,  F_10}, //LED57-K35-56
    {0, G_10,  H_10,  I_10}, //LED58-K36-57
    {0, J_10,  K_10,  L_10}, //LED59-K37-58

    {1, A_4,   B_4,   C_4},  //LED60-K38-59
    {1, D_4,   E_4,   F_4},  //LED61-K39-60
    {1, G_4,   H_4,   I_4},  //LED62-K3A-61
    {1, J_4,   K_4,   L_4},  //LED63-K3B-62

    {1, A_11,  B_11,  C_11}, //LED64-K3D-63
//Fifth row
    {0, I_5,   H_5,   G_5},  //LED65-K40-64
    {0, C_5,   B_5,   A_5},  //LED66-K42-65
    {0, F_5,   E_5,   D_5},  //LED67-K43-66

    {0, I_6,   H_6,   G_6},  //LED68-K44-67
    {0, L_6,   K_6,   J_6},  //LED69-K45-68
    {0, C_6,   B_6,   A_6},  //LED70-K46-69
    {0, F_6,   E_6,   D_6},  //LED71-K47-70

    {1, A_5,   B_5,   C_5},  //LED72-K48-71
    {1, D_5,   E_5,   F_5},  //LED73-K49-72
    {1, G_5,   H_5,   I_5},  //LED74-K4A-73
    {1, J_5,   K_5,   L_5},  //LED75-K4B-74

    {1, D_9,   E_9,   F_9},  //LED76-K4C-75

    {1, G_9,   H_9,   I_9},  //LED77-K4E-76
//Sixth row
    {0, I_11,  H_11,  G_11}, //LED78-K50-77
    {0, L_11,  K_11,  J_11}, //LED79-K51-78
    {0, C_11,  B_11,  A_11}, //LED80-K52-79
    {0, F_11,  E_11,  D_11}, //LED81-K56-80

    {1, J_10,  K_10,  L_10}, //LED82-K5B-81
    {1, A_10,  B_10,  C_10}, //LED83-K5C-82
    {1, D_10,  E_10,  F_10}, //LED84-K5D-83
    {1, G_10,  H_10,  I_10}, //LED85-K5E-84

    {1, J_9,   K_9,   L_9},  //LED86-K5F-85
    {1, A_9,   B_9,   C_9},  //LED87-K5G-86
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (host_keyboard_led_state().scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 255, 255, 255);
    } else if (!(rgb_matrix_get_flags() & LED_FLAG_INDICATOR)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 0, 0, 0);
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(51, 255, 255, 255);
    } else if (!(rgb_matrix_get_flags() & LED_FLAG_INDICATOR)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(51, 0, 0, 0);
    }

    return true;
}

#endif //RGB_MATRIX_ENABLE