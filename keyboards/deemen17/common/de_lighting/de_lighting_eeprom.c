#include "de_lighting_eeprom.h"
#include "eeconfig.h"

typedef struct {
    uint32_t magic;
    uint8_t  version;
    uint8_t  channel_count;
    bool     enabled[DE_LIGHTING_MAX_CHANNELS];
} de_lighting_eeprom_config_t;

bool de_lighting_eeprom_load(de_lighting_config_t *config) {
    de_lighting_eeprom_config_t stored = {0};

    if (!eeconfig_is_user_datablock_valid()) {
        return false;
    }

    eeconfig_read_user_datablock(&stored, 0, sizeof(stored));
    if (stored.magic != DE_LIGHTING_EEPROM_MAGIC || stored.version != DE_LIGHTING_CONFIG_VERSION) {
        return false;
    }

    config->magic         = stored.magic;
    config->version       = stored.version;
    config->channel_count = stored.channel_count;
    for (uint8_t i = 0; i < DE_LIGHTING_MAX_CHANNELS; i++) {
        config->enabled[i] = stored.enabled[i];
    }
    return true;
}

void de_lighting_eeprom_save(const de_lighting_config_t *config) {
    de_lighting_eeprom_config_t stored = {
        .magic         = DE_LIGHTING_EEPROM_MAGIC,
        .version       = DE_LIGHTING_CONFIG_VERSION,
        .channel_count = config->channel_count,
    };

    for (uint8_t i = 0; i < DE_LIGHTING_MAX_CHANNELS; i++) {
        stored.enabled[i] = config->enabled[i];
    }

    eeconfig_update_user_datablock(&stored, 0, sizeof(stored));
}
