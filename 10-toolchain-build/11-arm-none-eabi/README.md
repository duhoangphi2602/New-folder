# arm-none-eabi

## What is this topic?
This topic breaks down the incredibly common, yet cryptic, naming convention of the standard ARM Cortex-M toolchain: `arm-none-eabi-gcc`.

## Why is it important?
When you install a toolchain to program an STM32, ESP32, or Raspberry Pi, you are bombarded with hundreds of executables that look like `arm-linux-gnueabihf-gcc` or `xtensa-esp32-elf-g++`. Understanding the "Toolchain Tuple" naming convention allows you to instantly know exactly what hardware and OS the compiler is targeting.

## Prerequisites
- [03-assembly](../03-assembly/README.md)
- [10-gcc-gpp](../10-gcc-gpp/README.md)

## Learning Outcomes
1. Decode the standard 4-part toolchain naming tuple: `<arch>-<vendor>-<os>-<abi>`.
2. Understand the difference between `none` (Bare-metal) and `linux` (Operating System).
3. Understand what an ABI (Application Binary Interface) is.
