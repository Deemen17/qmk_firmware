#pragma once

#include "de_lighting_state.h"

bool de_lighting_eeprom_load(de_lighting_config_t *config);
void de_lighting_eeprom_save(const de_lighting_config_t *config);
