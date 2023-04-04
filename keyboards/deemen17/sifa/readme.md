# Deelab Sifa PCB

![Sifa](updating image)

A 65% hotswap PCB has 7U Space which controlled by an RP2040 chipset.
Layout available here: [KLE](http://www.keyboard-layout-editor.com/#/gists/2ddd09358f7353bb848a13b17710edf2) 

* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: Deelab Sifa PCB
* Hardware Availability: None

Make example for this keyboard (after setting up your build environment):

    qmk compile -j 0 -kb deelab/sifa -km via

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Esc key) and plug in the keyboard
* **Physical reset button**: Press and hold the button on the back of the PCB, then plug USB onto PC
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available