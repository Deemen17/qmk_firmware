#include "quantum.h"

void board_init(void) {
    AFIO->MAPR |= AFIO_MAPR_SPI1_REMAP;
}