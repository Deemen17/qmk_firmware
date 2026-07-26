#pragma once

#include <stdint.h>
#include "de_lighting_types.h"

typedef enum {
    DE_LIGHTING_EVENT_BOOT,
    DE_LIGHTING_EVENT_USB_CONNECTED,
    DE_LIGHTING_EVENT_USB_DISCONNECTED,
    DE_LIGHTING_EVENT_BLE_CONNECTED,
    DE_LIGHTING_EVENT_BLE_DISCONNECTED,
    DE_LIGHTING_EVENT_KEYCODE,
    DE_LIGHTING_EVENT_CONFIG_CHANGED,
    DE_LIGHTING_EVENT_EEPROM_LOADED,
    DE_LIGHTING_EVENT_EEPROM_SAVED,
    DE_LIGHTING_EVENT_LAYER_CHANGED,
    DE_LIGHTING_EVENT_BATTERY_CHANGED,
    DE_LIGHTING_EVENT_CHANNEL_CHANGED,
} de_lighting_event_t;

typedef struct {
    de_lighting_event_t type;
    const void         *data;
} de_lighting_event_record_t;
