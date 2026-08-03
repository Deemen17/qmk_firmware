#include "de_lighting.h"
#include "rgb_matrix.h"

static const de_lighting_channel_desc_t de65_lighting_channels[] = {
    {.name = "BACKLIGHT", .led_flags = LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR, .default_enable = true},
    {.name = "UNDERGLOW", .led_flags = LED_FLAG_UNDERGLOW, .default_enable = true},
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    return de_lighting_renderer_indicators_advanced(led_min, led_max);
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    de_lighting_via_custom_value_command(data, length);
}

void keyboard_post_init_user(void) {
    de_lighting_register_channels(de65_lighting_channels, ARRAY_SIZE(de65_lighting_channels));
    de_lighting_init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return de_lighting_process_record(keycode, record);
}

void housekeeping_task_user(void) {
    de_lighting_task();
}
