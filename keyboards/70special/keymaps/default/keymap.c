#include QMK_KEYBOARD_H
#include "qp.h"
#include "wait.h"

#include "./images/tetris.qgf.c"
#include "./images/test_tft.qgf.c"
#include "./images/test_tft.qgf.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_65_all(KC_A), [1] = LAYOUT_65_all(KC_B)};

static painter_device_t tft;
static painter_image_handle_t img;


void keyboard_post_init_user(void) {
    tft = qp_st7735_make_spi_device(80, 160, TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN, 0, 0);
    img = qp_load_image_mem(gfx_test_tft);
    qp_init(tft, QP_ROTATION_0);


    // qp_rect(tft, 0, 0, 80, 160, 0, 0, 0, true);
    qp_drawimage(tft, (80 - img->width), (160 - img->height), img);


    // wait_ms(3000);

    // qp_rect(tft, 0, 0, 80, 160, 0, 0, 0, true);
    // qp_flush(tft);

    for (int i = 0; i < 239; i+=8) {
        qp_rect(tft, 0, i, 80, i+80, i, 255, 255, true);
    }
}
