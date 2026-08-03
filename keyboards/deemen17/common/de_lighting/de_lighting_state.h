#pragma once

#include "de_lighting_types.h"

typedef enum {
    DE_LIGHTING_STATE_INIT,
    DE_LIGHTING_STATE_LOAD,
    DE_LIGHTING_STATE_RUNNING,
    DE_LIGHTING_STATE_DIRTY,
    DE_LIGHTING_STATE_SAVING,
    DE_LIGHTING_STATE_ERROR,
} de_lighting_state_t;

typedef struct {
    uint32_t magic;
    uint8_t  version;
    uint8_t  channel_count;
    bool     enabled[DE_LIGHTING_MAX_CHANNELS];
} de_lighting_config_t;

void                        de_lighting_state_reset_defaults(void);
de_lighting_state_t         de_lighting_state_get(void);
void                        de_lighting_state_set(de_lighting_state_t state);
de_lighting_config_t       *de_lighting_config(void);
const de_lighting_config_t *de_lighting_config_const(void);
void                        de_lighting_config_mark_dirty(void);
bool                        de_lighting_config_is_dirty(void);
void                        de_lighting_config_clear_dirty(void);
