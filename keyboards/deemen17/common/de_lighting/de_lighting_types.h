#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "quantum.h"

#ifndef DE_LIGHTING_MAX_CHANNELS
#    define DE_LIGHTING_MAX_CHANNELS 32
#endif

#define DE_LIGHTING_CONFIG_VERSION 1
#define DE_LIGHTING_EEPROM_MAGIC 0x44454C54u

typedef uint8_t de_lighting_channel_id_t;

typedef struct {
    const char *name;
    uint8_t     led_flags;
    bool        default_enable;
} de_lighting_channel_desc_t;

typedef struct {
    uint8_t channel;
    bool    enabled;
} de_lighting_channel_event_t;

typedef struct {
    uint16_t     keycode;
    keyrecord_t *record;
} de_lighting_keycode_event_t;
