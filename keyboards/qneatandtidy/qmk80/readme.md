# QMK80

![QMK80]()

A TKL PCB comes with per-key RGB LEDs and RGB underglow pre-soldered.

* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: Refund TKL, RP2040
* Hardware Availability: [Q"neatandtidy"](https://www.facebook.com/qneatandtidy)

Make example for this keyboard (after setting up your build environment):

    make qneatandtidy/qmk80/hotswap:default
    make qneatandtidy/qmk80/solder:default

Flashing example for this keyboard:

    make qneatandtidy/qmk80/hotswap:default:flash
    make qneatandtidy/qmk80/solder:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the BOOT button or double-tap RESET button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available