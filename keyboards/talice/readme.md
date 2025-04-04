# Talice

![talice](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [LQT](https://github.com/yourusername)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make talice:default

Flashing example for this keyboard:

    make talice:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available



led_config_t g_led_config = {

    {
        {     0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14     },
        {     15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29     },
        {     30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     NO_LED, 43     },
        {     NO_LED, 44,     45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57     },
        {     NO_LED, 58,     59,     NO_LED, 60,     NO_LED, 61,     NO_LED, 62,     NO_LED, 63,     NO_LED, NO_LED, 64,     NO_LED },
    },
    {
        // Color Matrix
        { 0, 0 },   { 16, 0 },   { 32, 0 },   { 48, 0 },   { 64, 0 },   { 80, 0 },   { 96, 0 },   { 112, 0 },   { 128, 0 },   { 144, 0 },   { 160, 0 },   { 176, 0 },   { 192, 0 },   { 208, 0 },    { 224, 0 },
        { 0, 16 },  { 16, 16 },  { 32, 16 },  { 48, 16 },  { 64, 16 },  { 80, 16 },  { 96, 16 },  { 112, 16 },  { 128, 16 },  { 144, 16 },  { 160, 16 },  { 176, 16 },  { 192, 16 },  { 208, 16 },   { 224, 16 },
        { 0, 32 },  { 16, 32 },  { 32, 32 },  { 48, 32 },  { 64, 32 },  { 80, 32 },  { 96, 32 },  { 112, 32 },  { 128, 32 },  { 144, 32 },  { 160, 32 },  { 176, 32 },                { 208, 32 },   { 224, 32 },
                    { 16, 48 },  { 32, 48 },  { 48, 48 },  { 64, 48 },  { 80, 48 },  { 96, 48 },  { 112, 48 },  { 128, 48 },  { 144, 48 },  { 160, 48 },  { 176, 48 },  { 192, 48 },  { 208, 48 },   { 224, 48 },
                    { 16, 64 },  { 32, 64 },               { 64, 64 },               { 96, 64 },                { 128, 64 },                { 160, 64 },                              { 208, 64 },   
        // Underglow
        { 208, 64 }, { 160, 64 }, { 100, 64 }, { 40, 64 }, { 10, 64 }, { 8, 32 }, { 8, 0 }, { 112, 0 }, { 176, 0 }, { 224, 0 },{ 224, 32 },
    },
    {
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
        4, 4, 4, 4, 4, 4, 4, 
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
    }
};

