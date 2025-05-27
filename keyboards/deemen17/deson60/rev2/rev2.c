#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
const is31fl3733_led_t PROGMEM g_is31fl3733_leds[IS31FL3733_LED_COUNT] = {
    { 0, SW11_CS16, SW10_CS16, SW12_CS16 }, // LED1
    { 0, SW11_CS15, SW10_CS15, SW12_CS15 }, // LED2
    { 0, SW11_CS14, SW10_CS14, SW12_CS14 }, // LED3
    { 0, SW11_CS8,  SW10_CS8,  SW12_CS8  }, // LED4
    { 0, SW11_CS7,  SW10_CS7,  SW12_CS7  }, // LED5
    { 0, SW11_CS6,  SW10_CS6,  SW12_CS6  }, // LED6
    { 0, SW11_CS5,  SW10_CS5,  SW12_CS5  }, // LED7
    { 0, SW11_CS3,  SW10_CS3,  SW12_CS3  }, // LED8
    { 0, SW11_CS2,  SW10_CS2,  SW12_CS2  }, // LED9
    { 0, SW11_CS1,  SW10_CS1,  SW12_CS1  }, // LED10
    { 0, SW11_CS4,  SW10_CS4,  SW12_CS4  }, // LED11
    { 0, SW11_CS9,  SW10_CS9,  SW12_CS9  }, // LED12
    { 0, SW11_CS10, SW10_CS10, SW12_CS10 }, // LED13
    { 0, SW11_CS11, SW10_CS11, SW12_CS11 }, // LED14
  
    { 0, SW8_CS16,  SW7_CS16,  SW9_CS16  },  // LED15
    { 0, SW8_CS15,  SW7_CS15,  SW9_CS15  },  // LED16
    { 0, SW8_CS14,  SW7_CS14,  SW9_CS14  },  // LED17
    { 0, SW8_CS8,   SW7_CS8,   SW9_CS8   },  // LED18
    { 0, SW8_CS7,   SW7_CS7,   SW9_CS7   },  // LED19
    { 0, SW8_CS6,   SW7_CS6,   SW9_CS6   },  // LED20
    { 0, SW8_CS5,   SW7_CS5,   SW9_CS5   },  // LED21
    { 0, SW8_CS3,   SW7_CS3,   SW9_CS3   },  // LED22
    { 0, SW8_CS2,   SW7_CS2,   SW9_CS2   },  // LED23
    { 0, SW8_CS1,   SW7_CS1,   SW9_CS1   },  // LED24
    { 0, SW8_CS4,   SW7_CS4,   SW9_CS4   },  // LED25
    { 0, SW8_CS9,   SW7_CS9,   SW9_CS9   },  // LED26
    { 0, SW8_CS10,  SW7_CS10,  SW9_CS10  },  // LED27
    { 0, SW8_CS11,  SW7_CS11,  SW9_CS11  },  // LED28
  
    { 0, SW5_CS16,  SW4_CS16,  SW6_CS16  },  // LED29 & LED30
    { 0, SW5_CS15,  SW4_CS15,  SW6_CS15  },  // LED31
    { 0, SW5_CS14,  SW4_CS14,  SW6_CS14  },  // LED32
    { 0, SW5_CS8,   SW4_CS8,   SW6_CS8   },  // LED33
    { 0, SW5_CS7,   SW4_CS7,   SW6_CS7   },  // LED34
    { 0, SW5_CS6,   SW4_CS6,   SW6_CS6   },  // LED35
    { 0, SW5_CS5,   SW4_CS5,   SW6_CS5   },  // LED36
    { 0, SW5_CS3,   SW4_CS3,   SW6_CS3   },  // LED37
    { 0, SW5_CS2,   SW4_CS2,   SW6_CS2   },  // LED38
    { 0, SW5_CS1,   SW4_CS1,   SW6_CS1   },  // LED39
    { 0, SW5_CS4,   SW4_CS4,   SW6_CS4   },  // LED40
    { 0, SW5_CS9,   SW4_CS9,   SW6_CS9   },  // LED41
    { 0, SW5_CS11,  SW4_CS11,  SW6_CS11  },  // LED42
  
    { 0, SW2_CS16,  SW1_CS16,  SW3_CS16  },  // LED43
    { 0, SW2_CS14,  SW1_CS14,  SW3_CS14  },  // LED44
    { 0, SW2_CS8,   SW1_CS8,   SW3_CS8   },  // LED45
    { 0, SW2_CS7,   SW1_CS7,   SW3_CS7   },  // LED46
    { 0, SW2_CS6,   SW1_CS6,   SW3_CS6   },  // LED47
    { 0, SW2_CS5,   SW1_CS5,   SW3_CS5   },  // LED48
    { 0, SW2_CS3,   SW1_CS3,   SW3_CS3   },  // LED49
    { 0, SW2_CS2,   SW1_CS2,   SW3_CS2   },  // LED50
    { 0, SW2_CS1,   SW1_CS1,   SW3_CS1   },  // LED51
    { 0, SW2_CS4,   SW1_CS4,   SW3_CS4   },  // LED52
    { 0, SW2_CS9,   SW1_CS9,   SW3_CS9   },  // LED53
    { 0, SW2_CS10,  SW1_CS10,  SW3_CS10  },  // LED54
    { 0, SW2_CS11,  SW1_CS11,  SW3_CS11  },  // LED55
  
    { 0, SW5_CS13,  SW4_CS13,  SW6_CS13  },  // LED56
    { 0, SW2_CS15,  SW1_CS15,  SW3_CS15  },  // LED57
    { 0, SW2_CS13,  SW1_CS13,  SW3_CS13  },  // LED58
    { 0, SW8_CS13,  SW7_CS13,  SW9_CS13  },  // LED59
    { 0, SW8_CS12,  SW7_CS12,  SW9_CS12  },  // LED60
    { 0, SW5_CS12,  SW4_CS12,  SW6_CS12  },  // LED61
    { 0, SW2_CS12,  SW1_CS12,  SW3_CS12  },  // LED62
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(28, RGB_WHITE);
    }
    return true;
}

// Enable indicator support in RGB Matrix
void keyboard_post_init_kb(void) {
    rgb_matrix_set_flags(LED_FLAG_INDICATOR);
    keyboard_post_init_user();
}

#endif
