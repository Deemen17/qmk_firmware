#include "de_lighting_channel.h"
#include "de_lighting_state.h"

static const de_lighting_channel_desc_t *registered_channels;
static uint8_t                           registered_channel_count;

void de_lighting_register_channels(const de_lighting_channel_desc_t *channels, uint8_t count) {
    registered_channels      = channels;
    registered_channel_count = count > DE_LIGHTING_MAX_CHANNELS ? DE_LIGHTING_MAX_CHANNELS : count;
}

uint8_t de_lighting_channel_count(void) {
    return registered_channel_count;
}

const de_lighting_channel_desc_t *de_lighting_channel_get(uint8_t channel) {
    return channel < registered_channel_count ? &registered_channels[channel] : NULL;
}

bool de_lighting_channel_enabled(uint8_t channel) {
    return channel < registered_channel_count && de_lighting_config_const()->enabled[channel];
}

bool de_lighting_channel_set_enabled(uint8_t channel, bool enabled) {
    if (channel >= registered_channel_count) {
        return false;
    }

    de_lighting_config()->enabled[channel] = enabled;
    de_lighting_config_mark_dirty();
    return true;
}

bool de_lighting_channel_toggle(uint8_t channel) {
    return de_lighting_channel_set_enabled(channel, !de_lighting_channel_enabled(channel));
}

uint8_t de_lighting_channel_flags(void) {
    uint8_t flags = 0;
    for (uint8_t i = 0; i < registered_channel_count; i++) {
        if (de_lighting_channel_enabled(i)) {
            flags |= registered_channels[i].led_flags;
        }
    }
    return flags;
}

uint32_t de_lighting_channel_default_mask(void) {
    uint32_t mask = 0;
    for (uint8_t i = 0; i < registered_channel_count && i < 32; i++) {
        if (registered_channels[i].default_enable) {
            mask |= 1UL << i;
        }
    }
    return mask;
}
