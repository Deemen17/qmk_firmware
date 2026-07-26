#include "de_lighting_renderer.h"
#include "de_lighting_channel.h"
#include "rgb_matrix.h"

void de_lighting_renderer_apply(void) {
    uint8_t flags = de_lighting_channel_flags();

    if (flags == 0) {
        rgb_matrix_disable_noeeprom();
        return;
    }

    rgb_matrix_enable_noeeprom();
    rgb_matrix_set_flags(flags);
    rgb_matrix_mode_noeeprom(rgb_matrix_get_mode());
}

bool de_lighting_renderer_indicators_advanced(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_WHITE);
            }
        }
    }
    return false;
}
