[![Latest release](https://img.shields.io/github/v/release/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP?label=Latest%20release)](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/releases/latest)
[![Latest tag](https://img.shields.io/github/v/tag/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP?label=Latest%20tag)](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tags)
[![License](https://img.shields.io/github/license/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP?label=License)](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/blob/main/LICENSE)
[![Build examples](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/examples.yml?logo=arm&logoColor=0091bd&label=Build%20examples)](/.github/workflows/examples.yml)
[![Build pack](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/pack.yml?logo=arm&logoColor=0091bd&label=Build%20pack)](/.github/workflows/pack.yml)


# NXP_IMXRT1050-EVKB_BSP

This is the development repository for the **NXP IMXRT1050-EVKB Board Support Pack (BSP)** - a CMSIS software pack that is designed to work with all compiler toolchains (Arm Compiler, GCC, IAR, LLVM). It is released as [CMSIS software pack](https://www.keil.arm.com/packs/imxrt1050-evkb_bsp-keil) and therefore accessible by CMSIS-Pack enabled software development tools.

> **Note:** This is currently Work in Progress. Final release is expected in Q3'2024.

## Repository top-level structure

Directory                   | Description
:---------------------------|:--------------
[.github/workflows](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tree/main/.github/workflows)  | [GitHub Actions](#github-actions).
[CMSIS/Driver](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tree/main/CMSIS/Driver)            | Contains a [CMSIS-Driver VIO](https://arm-software.github.io/CMSIS_6/latest/Driver/group__vio__interface__gr.html) that is configured for the board peripherals.
[DAPLink](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tree/main/DAPLink)                      | CMSIS-DAP firmware for DAPLink.
[Documents](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tree/main/Documents)                  | Board documentation.
[Examples/Blinky](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tree/main/Examples/Blinky)      | Blinky example in *csolution project format* using [CMSIS-Driver VIO](https://arm-software.github.io/CMSIS_6/latest/Driver/group__vio__interface__gr.html) and [CMSIS-Compiler](https://arm-software.github.io/CMSIS-Compiler/main/index.html) for printf I/O retargeting.
[Layers](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tree/main/Layers)                        | Board layers for using the board with [CMSIS-Toolbox - Reference Applications](https://github.com/ReinhardKeil/cmsis-toolbox/blob/main/docs/ReferenceApplications.md).

## Usage

This BSP requires the [Device Family Pack (DFP) for MIMXRT1052 ](https://www.keil.arm.com/packs/mimxrt1052_dfp-nxp) and [Board Support Pack (BSP) for EVKB-IMXRT1050](https://www.keil.arm.com/packs/evkb-imxrt1050_bsp-nxp).

- [Examples/Blinky](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tree/main/Examples/Blinky) shows the usage in a [*csolution project*](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/blob/main/Examples/Blinky/Blinky.csolution.yml).
  
- [Board Layers](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/tree/main/Layers) are designed for [Reference Applications](https://github.com/ReinhardKeil/cmsis-toolbox/blob/main/docs/ReferenceApplications.md) and allow to run various device-agnostic examples on this board.

## Using the development repository

This development repository can be used in a local directory and [mapped as software pack](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/build-tools.md#install-a-repository) using for example `cpackget` with:

    cpackget add <path>/Keil.IMXRT1050-EVKB_BSP.pdsc

## Generate software pack

The software pack is generated using bash shell scripts.

- `./gen_pack.sh` based on [Open-CMSIS-Pack/gen-pack](
https://github.com/Open-CMSIS-Pack/gen-pack) generates the software pack. Run this script locally with:

      NXP_IMXRT1050-EVKB_BSP $ ./gen_pack.sh

### GitHub Actions

The repository uses GitHub Actions to generate the pack:

- `.github/workflows/pack.yml` based on [Open-CMSIS-Pack/gen-pack-action](https://github.com/Open-CMSIS-Pack/gen-pack-action) generates pack using the [Generate software pack](#generate-software-pack) scripts.

## License

The BSP is licensed under [![License](https://img.shields.io/github/license/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP?label)](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/blob/main/LICENSE).

## Issues

Please feel free to raise an [issue on GitHub](https://github.com/Open-CMSIS-Pack/NXP_IMXRT1050-EVKB_BSP/issues)
to report misbehavior (i.e. bugs) or start discussions about enhancements. This
is your best way to interact directly with the maintenance team and the community.
We encourage you to append implementation suggestions as this helps to decrease the
workload of the maintenance team.
