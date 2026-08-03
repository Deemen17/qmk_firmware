#include "de_lighting_state.h"
#include "de_lighting_channel.h"

static de_lighting_state_t  state = DE_LIGHTING_STATE_INIT;
static de_lighting_config_t config;
static bool                 dirty;

void de_lighting_state_reset_defaults(void) {
    config.magic          = DE_LIGHTING_EEPROM_MAGIC;
    config.version        = DE_LIGHTING_CONFIG_VERSION;
    config.channel_count  = de_lighting_channel_count();
    uint32_t default_mask = de_lighting_channel_default_mask();
    for (uint8_t i = 0; i < DE_LIGHTING_MAX_CHANNELS; i++) {
        config.enabled[i] = i < 32 && (default_mask & (1UL << i));
    }
    dirty = false;
}

de_lighting_state_t de_lighting_state_get(void) {
    return state;
}
void de_lighting_state_set(de_lighting_state_t new_state) {
    state = new_state;
}
de_lighting_config_t *de_lighting_config(void) {
    return &config;
}
const de_lighting_config_t *de_lighting_config_const(void) {
    return &config;
}
void de_lighting_config_mark_dirty(void) {
    dirty = true;
}
bool de_lighting_config_is_dirty(void) {
    return dirty;
}
void de_lighting_config_clear_dirty(void) {
    dirty = false;
}
