// Copyright 2024 Omkbd (@Omkbd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #define RP2040_FLASH_GENERIC_03H

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

#define SERIAL_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral
#define SERIAL_USART_TX_PIN GP5
