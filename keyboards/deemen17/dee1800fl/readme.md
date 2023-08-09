# dee1800FL

![dee1800FL](updating image)

A 1800 Frow-less keyboard PCB which controlled by an RP2040 chipset.
Layout available here: [KLE](http://www.keyboard-layout-editor.com/#/gists/2b73d56f989abd9a6dcb6a0afe722066) 

* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: Deelab dee1800FL PCB
* Hardware Availability: None

Make example for this keyboard (after setting up your build environment):

    qmk compile -j 12 -kb deemen17/dee1800fl -km via

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Esc key) and plug in the keyboard
* **Physical reset button**: Press and hold the button on the back of the PCB, then plug USB onto PC
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available