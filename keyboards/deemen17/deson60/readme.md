# DESON60

![deemen17/deson60](imgur.com image replace me!)

A 60% PCB with per-key RGB LEDs, ungerglow RGB LEDs and supports only ANSI Tsangan layout.

* Keyboard Maintainer: [Pham Duc Minh](https://github.com/Deemen17)
* Hardware Supported: DESON60 PCB
* Hardware Availability: [Deemen17 Works Facebook Page](https://www.facebook.com/deemen17), [Deemen17 Works Instagram](https://www.instagram.com/deemen17.works)

Make example for this keyboard (after setting up your build environment):

    make deemen17/deson60:default

Flashing example for this keyboard:

    make deemen17/deson60:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly double press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
