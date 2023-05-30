/*
Copyright 2020 Evy Dekkers

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


RGB_MATRIX_EFFECT(solid_f13)
RGB_MATRIX_EFFECT(breathing_f13)
RGB_MATRIX_EFFECT(band_val_f13)
RGB_MATRIX_EFFECT(cycle_up_down_f13)
RGB_MATRIX_EFFECT(cycle_out_in_dual_f13)
RGB_MATRIX_EFFECT(rainbow_moving_chevron_f13)
RGB_MATRIX_EFFECT(cycle_pimwheel_f13)
RGB_MATRIX_EFFECT(rainbow_beacon_f13)
RGB_MATRIX_EFFECT(raindrops_f13)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool effect_runner_f13(effect_params_t* params, i_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, i, time));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    for (uint8_t i = 0; i < 91; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

bool effect_runner_dx_dy_f13(effect_params_t* params, dx_dy_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 2);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        int16_t dx  = g_led_config.point[i].x - k_rgb_matrix_center.x;
        int16_t dy  = g_led_config.point[i].y - k_rgb_matrix_center.y;
        RGB     rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, dx, dy, time));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    for (uint8_t i = 0; i < 91; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

bool effect_runner_sin_cos_f13(effect_params_t* params, sin_cos_i_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t time      = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 4);
    int8_t   cos_value = cos8(time) - 128;
    int8_t   sin_value = sin8(time) - 128;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, cos_value, sin_value, i, time));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    for (uint8_t i = 0; i < 91; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

static void raindrops_set_color_f13(int i, effect_params_t* params) {
    if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
    HSV hsv = {0, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};

    // Take the shortest path between hues
    int16_t deltaH = ((rgb_matrix_config.hsv.h + 180) % 360 - rgb_matrix_config.hsv.h) / 4;
    if (deltaH > 127) {
        deltaH -= 256;
    } else if (deltaH < -127) {
        deltaH += 256;
    }

    hsv.h   = rgb_matrix_config.hsv.h + (deltaH * (rand() & 0x03));
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    for (uint8_t i = 0; i < 91; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
}

static HSV BAND_VAL_CUSTOM(HSV hsv, uint8_t i, uint8_t time) {
    int16_t v = hsv.v - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv.v     = scale8(v < 0 ? 0 : v, hsv.v);
    return hsv;
}

static HSV CYCLE_UP_DOWN_CUSTOM(HSV hsv, uint8_t i, uint8_t time) {
        hsv.h = g_led_config.point[i].y - time;
    return hsv;
}

static HSV CYCLE_OUT_IN_DUAL_CUSTOM(HSV hsv, int16_t dx, int16_t dy, uint8_t time) {
    dx           = (k_rgb_matrix_center.x / 2) - abs8(dx);
    uint8_t dist = sqrt16(dx * dx + dy * dy);
    hsv.h        = 3 * dist + time;
    return hsv;
}

static HSV RAINBOW_MOVING_CHEVRON_CUSTOM(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h += abs8(g_led_config.point[i].y - k_rgb_matrix_center.y) + (g_led_config.point[i].x - time);
    return hsv;
}

static HSV CYCLE_PINWHEEL_CUSTOM(HSV hsv, int16_t dx, int16_t dy, uint8_t time) {
    hsv.h = atan2_8(dy, dx) + time;
    return hsv;
}

static HSV RAINBOW_BEACON_CUSTOM(HSV hsv, int8_t sin, int8_t cos, uint8_t i, uint8_t time) {
    hsv.h += ((g_led_config.point[i].y - k_rgb_matrix_center.y) * 2 * cos + (g_led_config.point[i].x - k_rgb_matrix_center.x) * 2 * sin) / 128;
    return hsv;
}

// Solid F13
static bool solid_f13(effect_params_t* params) {
    HSV hsv = rgb_matrix_config.hsv;
    RGB rgb = hsv_to_rgb(hsv);
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min ; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    rgb_matrix_set_color(91, rgb.r, rgb.g, rgb.b);
    return led_max < RGB_MATRIX_LED_COUNT;
}

// Breathing F13
static bool breathing_f13(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min ; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    rgb_matrix_set_color(91, rgb.r, rgb.g, rgb.b);
    return led_max < RGB_MATRIX_LED_COUNT;  
}

// Band Val F13
bool band_val_f13(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min ; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return effect_runner_f13(params, &BAND_VAL_CUSTOM); 
}

// Cycle up down F13
static bool cycle_up_down_f13(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min ; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return effect_runner_f13(params, &CYCLE_UP_DOWN_CUSTOM);
}

// Cycle out in dual f13
static bool cycle_out_in_dual_f13(effect_params_t* params) { 
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min ; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return effect_runner_dx_dy_f13(params, &CYCLE_OUT_IN_DUAL_CUSTOM); 
}

// Moving chevron F13
static bool rainbow_moving_chevron_f13(effect_params_t* params) { 
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min ; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return effect_runner_f13(params, &RAINBOW_MOVING_CHEVRON_CUSTOM); 
}

// Moving cycle pimwheel f13
static bool cycle_pimwheel_f13(effect_params_t* params) { 
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min ; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return effect_runner_dx_dy_f13(params, &CYCLE_PINWHEEL_CUSTOM); 
}

// Moving rainbow beacon f13
static bool rainbow_beacon_f13(effect_params_t* params) { 
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min ; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    return effect_runner_sin_cos_f13(params, &RAINBOW_BEACON_CUSTOM); 
}

// Raindrops F13
static bool raindrops_f13(effect_params_t* params) { 
    if (!params->init) {
        // Change one LED every tick, make sure speed is not 0
        if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 16)) % 10 == 0) {
            raindrops_set_color_f13(rand() % RGB_MATRIX_LED_COUNT, params);
        }
        return false;
    }

    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (int i = led_min; i < led_max; i++) {
        raindrops_set_color_f13(i, params);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}



#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
