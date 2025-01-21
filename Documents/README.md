# NXP IMXRT1050-EVKB

## Overview

The i.MX RT1050 EVK is a 4-layer through-hole USB-powered PCB. At its heart lies the i.MX RT1050 crossover MCU, featuring NXP's advanced implementation of the Arm Cortex-M7 core. This core operates at speeds up to 600 MHz to provide high CPU performance and great real-time response.

## Documentation

- [Board Hardware User’s Guide](./MIMXRT1050EVKHUG.pdf)
- [Quick Start Guide](./IMXRT1050EVKQSG.pdf)
- [Board schematic](./SPF-30168_B1.pdf)

## Power supply

A DC 5V external power supply is used to supply the board at J2, and a slide switch SW1 is used to turn the Power ON/OFF. J28 and J9 also can be used to supply the EVK Board. Different power supply need to configure different Jumper setting of J1:

| Power supply | J1 setting |
|:------------:|:----------:|
| J2           | 1-2        |
| J9           | 3-4        |
| J28          | 5-6        |

*Note*

If you do not have an external DC 5 V power supply, it is recommended to supply the board via J9 with a standard 5 V USB power supply. Supplying the board via J28 (which is connected to the on-board CMSIS-DAP debug adapter) is not recommended when using Arduino shields or Ethernet.

## CMSIS-Drivers

This board support pack contains a CMSIS-Driver for the [VIO](https://arm-software.github.io/CMSIS_6/latest/Driver/group__vio__interface__gr.html) interface. This is a virtual I/O abstraction for peripherals that are typically used in example projects. The **Blinky** example uses this interface to create a blinking light with the USER LED mounted on the board that can be controlled by the USER BUTTON (SW8).

| Virtual Resource  | Variable       | Physical Resource on IMXRT1050-EVKB |
|-------------------|----------------|-------------------------------------|
| vioBUTTON0        | vioSignalIn.0  | WAKEUP SW8 (USER_BUTTON)            |
| vioLED0           | vioSignalOut.0 | GPIO_AD_B0_09 (USER_LED)            |

Refer to the [schematics](#schematics) for board connection information.

## CMSIS-DAP Firmware

Make sure that you have updated your CMSIS-DAP firmware to the latest version. This makes the board compatible with [Keil Studio Cloud](https://keil.arm.com) that enables browser-based project creation and debugging. The following instructions apply if your board is equipped with at U23 a Kinetis K20DX device (marked as M20AGV).

### Using HyperFlash

If your board is configured for HyperFlash (**SW7** is set to OFF/ON/ON/OFF), use the following CMSIS-DAP firmware: [DAPLink 0254](../DAPLink/0254_k20dx_mimxrt1050_evk_hyper_0x8000.bin)

### Using QSPI Flash

If your board is configured for QSPI Flash (**SW7** is *not set* to OFF/ON/ON/OFF), use the following CMSIS-DAP firmware: [DAPLink 0254](../DAPLink/0254_k20dx_mimxrt1050_evk_qspi_0x8000.bin)

### Jumper settings

Close **1-2** on jumper block **J27** (top right corner of the board).

### Flashing instructions for Windows users

1. While holding down the **SW4** button, connect the board's USB debug port (**J28**) to the computer. It should enumerate and mount as **MAINTENANCE**.
1. Drag-and-drop the firmware file onto the mounted drive.
1. Wait for the file copy operation to complete.
1. Power cycle the board. It will now enumerate and mount as **RT1050-EVK**.

### Flashing instructions for MAC users

1. While holding down the **SW4** button, connect the board's USB debug port (**J28**) to the computer. It should enumerate as **MAINTENANCE**.
1. In a terminal execute  
   `sudo mount -u -w -o sync /Volumes/MAINTENANCE ; cp -X <path to firmware file> /Volumes/MAINTENANCE/`  
   *Note*: If your drive does not mount as MAINTENANCE make sure to change this to match the name of the mounted disk attached to your system.
1. Wait for the file copy operation to complete.
1. Power cycle the board. It will now enumerate and mount as **RT1050-EVK**.

### Flashing instructions for Linux users

1. While holding down the **SW4** button, connect the board's USB debug port (**J28**) to the computer. It should enumerate as **MAINTENANCE**.
1. In a terminal execute  
   `$ cp <path to firmware file> <MAINTENANCE> && sync`  
   *Note*: make sure to change MAINTENANCE to the name of the mount point of the drive on your system.
1. Power cycle the board. It will now enumerate and mount as **RT1050-EVK**.

## Accessing the board in Keil Studio under Linux

1. On Linux, permission to access USB devices from user space must be explicitly granted via udev rules. This repo contains [daplink.rules](./DAPLink/daplink.rules) that you can copy to make this work.
1. To install, copy the [daplink.rules](./DAPLink/daplink.rules) to `/etc/udev/rules.d/` on Ubuntu:  
   `$ sudo cp daplink.rules /etc/udev/rules.d`
1. To see your changes without a reboot, you can force the udev system to reload:  
   `$ sudo udevadm control --reload`  
   `$ sudo udevadm trigger`
