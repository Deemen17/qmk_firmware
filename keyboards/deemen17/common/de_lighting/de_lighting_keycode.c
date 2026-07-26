#include "de_lighting_keycode.h"
#include "de_lighting.h"

bool de_lighting_process_record(uint16_t keycode, keyrecord_t *record) {
    de_lighting_dispatch_event(&(de_lighting_event_record_t){.type = DE_LIGHTING_EVENT_KEYCODE, .data = &(de_lighting_keycode_event_t){.keycode = keycode, .record = record}});

    if (!record->event.pressed) {
        return true;
    }

    if (keycode >= DE_LIGHTING_CHANNEL_0_TOGGLE && keycode <= DE_LIGHTING_CHANNEL_7_TOGGLE) {
        uint8_t channel = keycode - DE_LIGHTING_CHANNEL_0_TOGGLE;
        if (de_lighting_channel_toggle(channel)) {
            de_lighting_dispatch_event(&(de_lighting_event_record_t){.type = DE_LIGHTING_EVENT_CHANNEL_CHANGED, .data = &(de_lighting_channel_event_t){.channel = channel, .enabled = de_lighting_channel_enabled(channel)}});
        }
        return false;
    }

    return true;
}
