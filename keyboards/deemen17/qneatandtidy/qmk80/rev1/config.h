/* Copyright 2023 Deemen17 <https://github.com/Deemen17>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11
#define I2C_DRIVER I2CD1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#ifdef RGB_MATRIX_ENABLE
#    define DRIVER_ADDR_1 0b1010000
#    define DRIVER_ADDR_2 0b1010011
#    define DRIVER_COUNT 2
#    define DRIVER_1_LED_TOTAL 43
#    define DRIVER_2_LED_TOTAL 44
#    define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
#    define RGB_MATRIX_TIMEOUT 1800000 // turn off LED RGB Matrix after 30 minutes without use
#    define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_KEYPRESSES
#endif // RGB_MATRIX_ENABLE
