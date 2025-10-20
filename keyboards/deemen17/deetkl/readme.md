# Deemen17 DeeTKL PCB

![deeTKL](updating image)

Layout available here: [KLE]() 

* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: Deemen17 deeTKL PCB
* Hardware Availability: None

Make example for this keyboard (after setting up your build environment):

    qmk compile -j 0 -kb deemen17/deetkl -km via

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard
* **Physical reset button**: Press and hold the button on the back of the PCB, then plug USB onto PC
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available