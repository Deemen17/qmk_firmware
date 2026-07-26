#pragma once

#include <stdint.h>

#define DE_LIGHTING_VIA_CHANNEL_ID 0x44

typedef enum {
    DE_LIGHTING_VIA_GET_CHANNEL = 1,
    DE_LIGHTING_VIA_SET_CHANNEL = 2,
    DE_LIGHTING_VIA_SAVE        = 3,
} de_lighting_via_command_t;

void de_lighting_via_custom_value_command(uint8_t *data, uint8_t length);
