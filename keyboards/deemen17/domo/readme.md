# Deemen17 Domo PCB

![Domo](updating image)

Layout available here: [KLE]() 

* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: Deemen17 Domo PCB
* Hardware Availability: None

Make example for this keyboard (after setting up your build environment):

    make deemen17/domo:default

Flashing example for this keyboard:

    make deemen17/domo:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Esc key) and plug in the keyboard
* **Physical reset button**: Press and hold the button on the back of the PCB, then plug USB onto PC
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available