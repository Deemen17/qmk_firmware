#pragma once

#include <stdint.h>

// VIA custom UI value IDs. VIA supplies id_custom_channel in data[1], one of
// these IDs in data[2], and the value in data[3] for set/get operations.
typedef enum {
    DE_LIGHTING_VIA_CHANNEL_0 = 1,
    DE_LIGHTING_VIA_CHANNEL_1 = 2,
    DE_LIGHTING_VIA_CHANNEL_2 = 3,
    DE_LIGHTING_VIA_CHANNEL_3 = 4,
    DE_LIGHTING_VIA_CHANNEL_4 = 5,
    DE_LIGHTING_VIA_CHANNEL_5 = 6,
    DE_LIGHTING_VIA_CHANNEL_6 = 7,
    DE_LIGHTING_VIA_CHANNEL_7 = 8,
} de_lighting_via_value_t;

void de_lighting_via_custom_value_command(uint8_t *data, uint8_t length);
