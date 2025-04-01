# DU60

![du60](https://i.imgur.com/pyFWJbo.png)

DU60 PCB, a replacement PCB designed for the UTD 356 Mini case.
* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: DU60, STM32F103
* Hardware Availability: [Deemen17 Works](https://www.facebook.com/deemen17)

Make example for this keyboard (after setting up your build environment):

    make deemen17/du60:default

Flashing example for this keyboard:

    make deemen17/du60:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the RESET button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
