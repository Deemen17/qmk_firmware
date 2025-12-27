# DE65

![deemen17/de65](https://i.imgur.com/oZvFM0G.png)



* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: De65 PCB w/ STM32F103 MCU
* Hardware Availability: [Deemen17 Facebook Page](https://www.facebook.com/deemen17/), [Deemen17 Works Instagram](https://www.instagram.com/deemen17.works)

Make example for this keyboard (after setting up your build environment):

    make deemen17/de65:default

Flashing example for this keyboard:

    make deemen17/de65:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (ESC/Escape) and plug in the keyboard
* **Physical reset button**: Double tap the button RESET on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
