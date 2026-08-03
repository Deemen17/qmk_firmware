#pragma once

#include "de_lighting_types.h"

void                              de_lighting_register_channels(const de_lighting_channel_desc_t *channels, uint8_t count);
uint8_t                           de_lighting_channel_count(void);
const de_lighting_channel_desc_t *de_lighting_channel_get(uint8_t channel);
bool                              de_lighting_channel_enabled(uint8_t channel);
bool                              de_lighting_channel_set_enabled(uint8_t channel, bool enabled);
bool                              de_lighting_channel_toggle(uint8_t channel);
uint8_t                           de_lighting_channel_flags(void);
uint32_t                          de_lighting_channel_default_mask(void);
