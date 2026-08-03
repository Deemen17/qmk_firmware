#include "de_lighting.h"
#include "de_lighting_eeprom.h"
#include "de_lighting_renderer.h"

void de_lighting_init(void) {
    de_lighting_state_set(DE_LIGHTING_STATE_LOAD);
    de_lighting_task();
    de_lighting_dispatch_event(&(de_lighting_event_record_t){.type = DE_LIGHTING_EVENT_BOOT});
}

void de_lighting_task(void) {
    switch (de_lighting_state_get()) {
        case DE_LIGHTING_STATE_INIT:
            de_lighting_state_set(DE_LIGHTING_STATE_LOAD);
            break;
        case DE_LIGHTING_STATE_LOAD:
            if (!de_lighting_eeprom_load(de_lighting_config())) {
                de_lighting_state_reset_defaults();
                de_lighting_config_mark_dirty();
            } else if (de_lighting_config()->channel_count != de_lighting_channel_count()) {
                uint8_t  old_count                  = de_lighting_config()->channel_count;
                uint32_t default_mask               = de_lighting_channel_default_mask();
                de_lighting_config()->channel_count = de_lighting_channel_count();
                for (uint8_t i = old_count; i < de_lighting_channel_count(); i++) {
                    de_lighting_config()->enabled[i] = i < 32 && (default_mask & (1UL << i));
                }
                de_lighting_config_mark_dirty();
            }
            de_lighting_dispatch_event(&(de_lighting_event_record_t){.type = DE_LIGHTING_EVENT_EEPROM_LOADED});
            de_lighting_renderer_apply();
            de_lighting_state_set(de_lighting_config_is_dirty() ? DE_LIGHTING_STATE_DIRTY : DE_LIGHTING_STATE_RUNNING);
            break;
        case DE_LIGHTING_STATE_DIRTY:
            de_lighting_renderer_apply();
            de_lighting_state_set(DE_LIGHTING_STATE_SAVING);
            break;
        case DE_LIGHTING_STATE_SAVING:
            de_lighting_save();
            de_lighting_state_set(DE_LIGHTING_STATE_RUNNING);
            break;
        case DE_LIGHTING_STATE_RUNNING:
        case DE_LIGHTING_STATE_ERROR:
            break;
    }
}

void de_lighting_dispatch_event(const de_lighting_event_record_t *event) {
    if (!event) {
        return;
    }

    switch (event->type) {
        case DE_LIGHTING_EVENT_CONFIG_CHANGED:
        case DE_LIGHTING_EVENT_CHANNEL_CHANGED:
            de_lighting_config_mark_dirty();
            de_lighting_state_set(DE_LIGHTING_STATE_DIRTY);
            break;
        default:
            break;
    }
}

void de_lighting_save(void) {
    de_lighting_eeprom_save(de_lighting_config_const());
    de_lighting_config_clear_dirty();
    de_lighting_dispatch_event(&(de_lighting_event_record_t){.type = DE_LIGHTING_EVENT_EEPROM_SAVED});
}
