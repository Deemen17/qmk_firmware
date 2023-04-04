#include "dee1800fl.h"

//Initialize all RGB indicators to 'off'
__attribute__((weak))
void keyboard_post_init_user(void) {
    rgblight_setrgb_at(0, 0, 0, 0); // capslock
    rgblight_setrgb_at(0, 0, 0, 1); // numlock 
    rgblight_set_effect_range(2, 8);
}

//Indicator light function
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
    if (led_state.caps_lock) {
        rgblight_setrgb_at(255, 255, 255, 0);
    } else {
        rgblight_setrgb_at(0, 0, 0, 0);
    }
    if (!led_state.num_lock) {
        rgblight_setrgb_at(255, 255, 255, 1);
    } else {
        rgblight_setrgb_at(0, 0, 0, 1);
    }
}
    return res;
}
