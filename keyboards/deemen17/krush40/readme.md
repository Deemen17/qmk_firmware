# Krush40

![deemen17/krush40]()

* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: Nuxros Krush40 PCB w/ STM32F103 MCU
* Hardware Availability: Private Commission

Make example for this keyboard (after setting up your build environment):

    make deemen17/krush40:default

Flashing example for this keyboard:

    make deemen17/krush40:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (ESC/Escape) and plug in the keyboard
* **Physical reset button**: Double tap the button RESET on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
