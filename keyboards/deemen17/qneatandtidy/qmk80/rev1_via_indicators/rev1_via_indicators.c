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
#include "eeprom.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {

/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
// First row
    {0, A_1,   B_1,   C_1},  //LED1-K00-0
    {0, D_1,   E_1,   F_1},  //LED2-K01-1
    {0, G_1,   H_1,   I_1},  //LED3-K02-2
    {0, J_1,   K_1,   L_1},  //LED4-K03-3
    {0, A_7,   B_7,   C_7},  //LED5-K04-4
    {0, D_7,   E_7,   F_7},  //LED6-K05-5
    {0, G_7,   H_7,   I_7},  //LED7-K06-6
    {0, J_7,   K_7,   L_7},  //LED8-K07-7
    {1, A_1,   B_1,   C_1},  //LED9-K08-8
    {1, D_1,   E_1,   F_1},  //LED10-K09-9
    {1, G_1,   H_1,   I_1},  //LED11-K0A-10
    {1, J_1,   K_1,   L_1},  //LED12-K0B-11
    {1, A_6,   B_6,   C_6},  //LED13-K0C-12
    {1, D_6,   E_6,   F_6},  //LED14-K0D-13
    {1, G_6,   H_6,   I_6},  //LED15-K0E-14
    {1, J_6,   K_6,   L_6},  //LED16-K0F-15
    {1, J_11,  K_11,  L_11}, //LED17-K0G-16
//Second row
    {0, A_2,   B_2,   C_2},  //LED18-K10-17
    {0, D_2,   E_2,   F_2},  //LED19-K11-18
    {0, G_2,   H_2,   I_2},  //LED20-K12-19
    {0, J_2,   K_2,   L_2},  //LED21-K13-20
    {0, A_8,   B_8,   C_8},  //LED22-K14-21
    {0, D_8,   E_8,   F_8},  //LED23-K15-22
    {0, G_8,   H_8,   I_8},  //LED24-K16-23
    {0, J_8,   K_8,   L_8},  //LED25-K17-24
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
    {0, A_3,   B_3,   C_3},  //LED35-K20-34
    {0, D_3,   E_3,   F_3},  //LED36-K21-35
    {0, G_3,   H_3,   I_3},  //LED37-K22-36
    {0, J_3,   K_3,   L_3},  //LED38-K23-37
    {0, A_9,   B_9,   C_9},  //LED39-K24-38
    {0, D_9,   E_9,   F_9},  //LED40-K25-39
    {0, G_9,   H_9,   I_9},  //LED41-K26-40
    {0, J_9,   K_9,   L_9},  //LED42-K27-41
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
    {0, A_4,   B_4,   C_4},  //LED52-K30-51
    {0, D_4,   E_4,   F_4},  //LED53-K31-52
    {0, G_4,   H_4,   I_4},  //LED54-K32-53
    {0, J_4,   K_4,   L_4},  //LED55-K33-54
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
    {0, A_5,   B_5,   C_5},  //LED65-K40-64
    {0, G_5,   H_5,   I_5},  //LED66-K42-65
    {0, J_5,   K_5,   L_5},  //LED67-K43-66
    {0, A_11,  B_11,  C_11}, //LED68-K44-67
    {0, D_11,  E_11,  F_11}, //LED69-K45-68
    {0, G_11,  H_11,  I_11}, //LED70-K46-69
    {0, J_11,  K_11,  L_11}, //LED71-K47-70
    {1, A_5,   B_5,   C_5},  //LED72-K48-71
    {1, D_5,   E_5,   F_5},  //LED73-K49-72
    {1, G_5,   H_5,   I_5},  //LED74-K4A-73
    {1, J_5,   K_5,   L_5},  //LED75-K4B-74
    {1, D_9,   E_9,   F_9},  //LED76-K4C-75
    {1, G_9,   H_9,   I_9},  //LED77-K4E-76
//Sixth row
    {0, A_6,   B_6,   C_6},  //LED78-K50-77
    {0, D_6,   E_6,   F_6},  //LED79-K51-78
    {0, G_6,   H_6,   I_6},  //LED80-K52-79
    {0, J_6,   K_6,   L_6},  //LED81-K56-80
    {1, J_10,  K_10,  L_10}, //LED82-K5B-81
    {1, D_10,  E_10,  F_10}, //LED83-K5C-82
    {1, G_10,  H_10,  I_10}, //LED84-K5D-83
    {1, A_10,  B_10,  C_10}, //LED85-K5E-84
    {1, J_9,   K_9,   L_9},  //LED86-K5F-85
    {1, J_9,   K_9,   L_9},  //LED87-K5G-86
};

led_config_t g_led_config = { {
    // Key Matrix to LED Index
        {0,           1,           2,           3,           4,           5,           6,           7,           8,           9,           10,           11,           12,           13,           14,           15,           16},
        {17,         18,          19,          20,          21,          22,          23,          24,          25,          26,           27,           28,           29,           30,           31,           32,           33},
        {34,         35,          36,          37,          38,          39,          40,          41,          42,          43,           44,           45,           46,           47,           48,           49,           50},
        {51,         52,          53,          54,          55,          56,          57,          58,          59,          60,           61,           62,       NO_LED,           63,       NO_LED,       NO_LED,       NO_LED},
        {64,     NO_LED,          65,          66,          67,          68,          69,          70,          71,          72,           73,           74,       NO_LED,           75,       NO_LED,           76,       NO_LED},
        {77,         78,          79,      NO_LED,      NO_LED,      NO_LED,          80,     NO_LED,       NO_LED,      NO_LED,       NO_LED,           81,           82,           83,           84,           85,           86}
    }, {
        {  0,0  }, { 16,0  }, { 29,0  }, { 42,0  }, { 55,0  }, { 71,0  }, { 84,0  }, { 97,0  }, {110,0  }, {127,0  }, {140,0  }, {153,0  }, {166,0  }, {182,0  }, {198,0  }, {211,0  }, {224,0  }, 
        {  0,15 }, { 13,15 }, { 26,15 }, { 39,15 }, { 52,15 }, { 65,15 }, { 78,15 }, { 91,15 }, {104,15 }, {117,15 }, {130,15 }, {143,15 }, {156,15 }, {175,15 }, {198,15 }, {211,15 }, {224,15 }, 
        {  3,27 }, { 19,27 }, { 32,27 }, { 45,27 }, { 58,27 }, { 71,27 }, { 84,27 }, { 97,27 }, {110,27 }, {123,27 }, {136,27 }, {149,27 }, {162,27 }, {179,27 }, {198,27 }, {211,27 }, {224,27 },
        {  5,40 }, { 23,40 }, { 36,40 }, { 49,40 }, { 62,40 }, { 75,40 }, { 88,40 }, {101,40 }, {114,40 }, {127,40 }, {140,40 }, {153,40 },            {174,40 }, 
        {  8,52 },            { 29,52 }, { 42,52 }, { 55,52 }, { 68,52 }, { 81,52 }, { 94,52 }, {107,52 }, {120,52 }, {133,52 }, {146,52 },            {170,52 },            {211,52 }, 
        {  3,64 }, { 19,64 }, { 36,64 },                                  { 91,64 },                                             {146,64 }, {162,64 }, {179,64 }, {198,64 }, {211,64 }, {224,64 }
    }, {
       1,        1,          1,           1,           1,           1,           1,           1,            1,            1,             1,             1,             1,             1,             1,             8,             1,
       1,        4,          4,           4,           4,           4,           4,           4,            4,            4,             4,             4,             4,             1,             1,             1,             1,
       1,        4,          4,           4,           4,           4,           4,           4,            4,            4,             4,             4,             4,             1,             1,             1,             1,
       8,        4,          4,           4,           4,           4,           4,           4,            4,            4,             4,             4,                            1,
       1,                    4,           4,           4,           4,           4,           4,            4,            4,             4,             4,                            1,                            1, 
       1,        1,          1,                                                  1,                                                                     1,             1,             1,             1,             1,             1
    } };

// PERSISTENT MEMORY (PMEM) CONFIGURATION ----------------------------------------------------------
#ifdef VIA_ENABLE
// Declaring a type indicator_config that stores color and enabled state
typedef struct _indicator_config_t {
// H, S, V store the color values; func stores the function (caps lock, scroll, num, layer indication); index stores the RGB LED index; and enabled stores the enabled state
        uint8_t h;
        uint8_t s;
        uint8_t v;
        uint8_t func ;
        uint8_t index ;
        bool enabled;    
} indicator_config ;

/* List of functions:
    0x0000 CAPS LOCK
    0x0001 NUM LOCK
    0x0002 SCROLL LOCK
    0x0003 LAYER 0
    0x0004 LAYER 1
    0x0005 LAYER 2
    0x0006 LAYER 3
*/

// Declaring a keyboard_indicators type that stores the indicators states

typedef struct _keyboard_indicators_t {
    indicator_config ind1 ;
    indicator_config ind2 ;
    indicator_config ind3 ;
    indicator_config ind4 ;
} keyboard_indicators ;

int indicator_number = (int)sizeof(keyboard_indicators)/(int)sizeof(indicator_config) ;

// Checks if the available EECONFIG DATA SIZE is exactly the size as keyboard_indicators
_Static_assert(sizeof(keyboard_indicators) == EECONFIG_KB_DATA_SIZE, "Mismatch in keyboard indicators stored data");

// Declaring a new variable indicators of the type keyboard_indicators
keyboard_indicators indicators;
uint8_t* pIndicators = (uint8_t*)&indicators ; // Gets a pointer to the first indicator

// This function returns the pointer to an indicator given an index
indicator_config* get_indicator_p (int index) {
    return (indicator_config*) (pIndicators + sizeof(indicator_config)*index) ;
}

// Initializing persistent memory configuration: default values are declared and stored in PMEM
void eeconfig_init_kb(void) {
    // Default values: all indicators start at white, 150 (roughly 60%) brightness value. Indicators 1 and 2 are active by default. Indicators 3 and 4 are disabled.
    // INDICATOR 1: CAPS LOCK
    indicators.ind1.h = 0;
    indicators.ind1.s = 0;
    indicators.ind1.v = 150;
    indicators.ind1.func = 0;
    indicators.ind1.index = 51;
    indicators.ind1.enabled = true;

    // INDICATOR 2: SCROLL LOCK
    indicators.ind2.h = 0;
    indicators.ind2.s = 0;
    indicators.ind2.v = 150;
    indicators.ind2.func = 2;
    indicators.ind2.index = 15;
    indicators.ind2.enabled = true;

    // INDICATOR 3: LAYER 1
    indicators.ind3.h = 0;
    indicators.ind3.s = 0;
    indicators.ind3.v = 150;
    indicators.ind3.func = 4;
    indicators.ind3.index = 0;
    indicators.ind3.enabled = false;

    // INDICATOR 4: LAYER 2
    indicators.ind4.h = 0;
    indicators.ind4.s = 0;
    indicators.ind4.v = 150;
    indicators.ind4.func = 5;
    indicators.ind4.index = 0;
    indicators.ind4.enabled = false;

    // Write default value to EEPROM now
    eeconfig_update_kb_datablock(&indicators);
}

void rgb_matrix_startup(void) {
    rgb_matrix_disable_noeeprom();
    wait_ms(20);
    rgb_matrix_reload_from_eeprom();
    rgb_matrix_enable_noeeprom();
}

// At the keyboard start, retrieves PMEM stored configs
void keyboard_post_init_kb(void) {
    debug_enable = true;
    debug_matrix = true;
    rgb_matrix_startup();
    eeconfig_read_kb_datablock(&indicators);
    rgb_matrix_indicators_kb();
}

bool set_indicator(indicator_config indicator) {
    switch (indicator.func)
    {
        case 0: // If indicator is set as caps lock
        {
            if (host_keyboard_led_state().caps_lock) return true;
        }
        case 1: // If indicator is set as num lock
        {
            if (host_keyboard_led_state().num_lock) return true;
        }
        case 2: // If indicator is set as scroll lock
        {
            if (host_keyboard_led_state().scroll_lock) return true;
        }
        case 3: // If indicator is set as layer 0
        case 4:
        case 5:
        case 6:
        {
            if ( IS_LAYER_ON( (int)(indicator.func) - 3  ) ) return true;
        }
        default:
        {
            return false;
        }
    }
    return false;
}

HSV return_indicator_hsv (indicator_config indicator){
    return (HSV){indicator.h, indicator.s, indicator.v};
}

// INDICATOR CALLBACK ------------------------------------------------------------------------------
bool rgb_matrix_indicators_kb(void) {
    // First decides if action is needed. If a user code is defined, or the indicator is disabled, then does not act.
    if (!rgb_matrix_indicators_user()) return false;

    RGB rgb_current_indicator ;
    indicator_config* current_indicator_p ;
    int index ;

    for (index = 0 ; index < indicator_number ; index++) {
        current_indicator_p = get_indicator_p(index) ;
        if (current_indicator_p -> enabled) {
            rgb_current_indicator = hsv_to_rgb(return_indicator_hsv( *(current_indicator_p) ));
            if (set_indicator( *(current_indicator_p)) ) rgb_matrix_set_color( current_indicator_p -> index, rgb_current_indicator.r, rgb_current_indicator.g, rgb_current_indicator.b);
            else rgb_matrix_set_color(current_indicator_p -> index, 0, 0, 0);
       }
    }
    return true;
}

// VIA CONFIGURATION -------------------------------------------------------------------------------
enum via_indicator_color {
    id_ind1_enabled = 1,
    id_ind1_brightness = 2,
    id_ind1_color = 3,
    id_ind1_func = 4,
    id_ind1_index = 5,
//
    id_ind2_enabled = 6,
    id_ind2_brightness = 7,
    id_ind2_color = 8,
    id_ind2_func = 9,
    id_ind2_index = 10,
//
    id_ind3_enabled = 11,
    id_ind3_brightness = 12,
    id_ind3_color = 13,
    id_ind3_func = 14,
    id_ind3_index = 15,
//
    id_ind4_enabled = 16,
    id_ind4_brightness = 17,
    id_ind4_color = 18,
    id_ind4_func = 19,
    id_ind4_index = 20
};

#define INDICATOR_PROPERTY_NUMBER 5

int indi_index;
int data_index;
void indicator_config_set_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id;
    value_id = &(data[0]);
    uint8_t *value_data = &(data[1]);

    /* Suppose that the brightness value of indicator 3 is being changed; then

       index = (12-1)/INDICATOR_PROPERTY_NUMBER = (12-1)/5 = 2 (integer division!), which indeed relates to indicator 3 (ind1 is 0, ind2 is 1 etc)
       data_index = (12 - index*INDICATOR_PROPERTY_NUMBER) = 12 - 2*5 = 2, which indeed relates to a brightness setting (0 is for enabled, 1 for brightness, 2 for color and 3 for func)

       Therefore, the basic idea is that index is about which indicator the set_value is about, and data_index about what indicator property it is
    */
    indi_index = ( (int)(*value_id) - 1) / (int)INDICATOR_PROPERTY_NUMBER;
    data_index = (int)(*value_id) - indi_index*(int)INDICATOR_PROPERTY_NUMBER;
    indicator_config* current_indicator_p = get_indicator_p(indi_index);
    switch ( data_index )
    {
        case 1 :
        {
                current_indicator_p -> enabled = value_data[0];
                break;
        }
        case 2 :
        {
                current_indicator_p -> v = value_data[0];
                break;
        }
        case 3:
        {
                current_indicator_p -> h = value_data[0];
                current_indicator_p -> s = value_data[1];
                break;
        }
        case 4:
        {
                current_indicator_p -> func = value_data[0];
                break;
        }
        case 5:
        {
                current_indicator_p -> index = value_data[0];
                break;
        }
    }
    // Run callback after update
    rgb_matrix_indicators_kb();
}


void indicator_config_get_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    indi_index = ( (int)(*value_id) - 1) / (int)INDICATOR_PROPERTY_NUMBER;
    data_index = (int)(*value_id) - indi_index*(int)INDICATOR_PROPERTY_NUMBER;
    indicator_config* current_indicator_p = get_indicator_p(indi_index);
    switch ( data_index )
    {
        case 1:
        {
            value_data[0] =  current_indicator_p -> enabled;
            break;
        }
        case 2:
        {

            value_data[0] = current_indicator_p -> v;
            break;
        }
        case 3:
        {

            value_data[0] = current_indicator_p -> h;
            value_data[1] = current_indicator_p -> s;
            break;
        }
        case 4:
        {

            value_data[0] = current_indicator_p -> func;
            break;
        }
        case 5:
        {

            value_data[0] = current_indicator_p -> index;
            break;
        }
    }
}

void indicator_config_save(void)
{
    eeconfig_update_kb_datablock(&indicators);
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
                indicator_config_save();
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

    *command_id = id_unhandled;
}
#endif // VIA_ENABLE

#endif //RGB_MATRIX_ENABLE