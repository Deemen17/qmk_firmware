#pragma once

#include "de_lighting_types.h"

enum de_lighting_keycodes {
    DE_LIGHTING_CHANNEL_0_TOGGLE = QK_KB_0,
    DE_LIGHTING_CHANNEL_1_TOGGLE,
    DE_LIGHTING_CHANNEL_2_TOGGLE,
    DE_LIGHTING_CHANNEL_3_TOGGLE,
    DE_LIGHTING_CHANNEL_4_TOGGLE,
    DE_LIGHTING_CHANNEL_5_TOGGLE,
    DE_LIGHTING_CHANNEL_6_TOGGLE,
    DE_LIGHTING_CHANNEL_7_TOGGLE,
};

bool de_lighting_process_record(uint16_t keycode, keyrecord_t *record);
