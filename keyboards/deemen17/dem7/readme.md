# Deemen17 DEM.7 PCB

![deeTKL](updating image)

A EM7 keyboard PCB compatible which controlled by an RP2040 chipset.
Layout available here: [KLE]() 

* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: Deemen17 DEM.7 PCB
* Hardware Availability: None

Make example for this keyboard (after setting up your build environment):

    qmk compile -j 0 -kb deemen17/dem7 -km via

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Esc key) and plug in the keyboard
* **Physical reset button**: Press and hold the button on the back of the PCB, then plug USB onto PC
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available