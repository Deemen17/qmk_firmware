/*
Copyright 2023 Deemen17

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

// VIA KB level
#define VIA_FIRMWARE_VERSION 1
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

#ifdef RGB_MATRIX_ENABLE
// The number of LEDs connected
// #    define RGB_MATRIX_LED_COUNT 22
#    define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#    define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
// #    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 220 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON

#endif // RGB_MATRIX_ENABLE
