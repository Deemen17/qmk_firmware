// Copyright 2024 Deemen17 (@Deemen17)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define RP2040_FLASH_GENERIC_03H

// EECONFIG data size: each indicator takes 5 bytes; there are 3 possible indicators.
#define EECONFIG_KB_DATA_SIZE (3*6)

#define WEAR_LEVELING_LOGICAL_SIZE 2048
#define WEAR_LEVELING_BACKING_SIZE 4096	
