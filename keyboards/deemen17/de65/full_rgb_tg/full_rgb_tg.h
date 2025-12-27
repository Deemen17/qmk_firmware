/*
Copyright 2025 DEEMEN17 WORKS

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"
#include "rgb_matrix.h"
#include "via.h"
#include "eeconfig.h"

enum via_rgb_matrix_value {
    id_rgb_matrix_bl_toggle = 1,
    id_rgb_matrix_ug_toggle = 2,
};

typedef struct {
    bool bl_enabled;
    bool ug_enabled;
} custom_rgb_matrix_config_t;

#define CUSTOM_RGB_MATRIX_CONFIG_EEPROM_ADDR 0x2000
custom_rgb_matrix_config_t g_custom_rgb_matrix_config;

void rgb_matrix_config_set_value(uint8_t *data);
void rgb_matrix_config_get_value(uint8_t *data);
void rgb_matrix_config_save(void);
void update_rgb_matrix(void);
void rgb_matrix_config_load(void);