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

#define FORCE_NKRO

/* VIA related config */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// VIA KB level
#define VIA_FIRMWARE_VERSION 1
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 9

#ifdef RGB_MATRIX_ENABLE
<<<<<<< HEAD:keyboards/deemen17/deetkl/solder/rev1_indicator/config.h
// The pin connected to the data pin of the LEDs
#    define RGB_DI_PIN GP0
// The number of LEDs connected
#    define RGB_MATRIX_LED_COUNT 22
#    define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#    define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 220 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON

=======
>>>>>>> fc20e0b01434ed152481e3c778c24879ac116360:keyboards/input_club/k_type/config.h
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects

    // Heatmap, Rain
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    // REACTIVE, SPLASH modes
#    define RGB_MATRIX_KEYPRESSES

#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    // enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    // enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#endif // RGB_MATRIX_ENABLE

<<<<<<< HEAD:keyboards/deemen17/deetkl/solder/rev1_indicator/config.h
=======

// i2c_master defines
#    define I2C_COUNT 2
#    define I2C1_CLOCK_SPEED 400000

#    define I2C1_SCL_PIN B0 // A2 on pinout = B0
#    define I2C1_SDA_PIN B1 // A2 on pinout = B1
#    define I2C1_SCL_PAL_MODE PAL_MODE_ALTERNATIVE_2
#    define I2C1_SDA_PAL_MODE PAL_MODE_ALTERNATIVE_2

#    define USE_I2C2
#    define I2C2_SCL_PIN C10 // A2 on pinout = C10
#    define I2C2_SDA_PIN C11 // A2 on pinout = C11
#    define I2C2_SCL_PAL_MODE PAL_MODE_ALTERNATIVE_2
#    define I2C2_SDA_PAL_MODE PAL_MODE_ALTERNATIVE_2

#    define IS31FL3733_I2C_ADDRESS_1 IS31FL3733_I2C_ADDRESS_GND_GND
#    define IS31FL3733_I2C_ADDRESS_2 IS31FL3733_I2C_ADDRESS_GND_GND
#    define IS31FL3733_DRIVER_COUNT 2
#    define IS31FL3733_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
#    define DRIVER_1_LED_TOTAL 64
#    define DRIVER_2_LED_TOTAL 55
#    define RGB_MATRIX_LED_COUNT IS31FL3733_LED_COUNT
#endif
>>>>>>> fc20e0b01434ed152481e3c778c24879ac116360:keyboards/input_club/k_type/config.h
