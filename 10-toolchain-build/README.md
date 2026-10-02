# 10 — Toolchain & Build System

Understanding the build pipeline is not optional for embedded engineers. You must know how source code becomes a flashable binary, and how to control the compiler, linker, and build system.

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [Preprocessing](./01-preprocessing/) | `#include`, macros |
| 02 | [Compilation](./02-compilation/) | C++ → assembly |
| 03 | [Assembly](./03-assembly/) | Assembly language basics |
| 04 | [Object Files](./04-object-files/) | `.o` files, symbols, relocations |
| 05 | [Linking](./05-linking/) | Symbol resolution |
| 06 | [ELF](./06-elf/) | ELF format, sections |
| 07 | [BIN/HEX](./07-bin-hex/) | `objcopy`, flashing |
| 08 | [Symbols](./08-symbols/) | `nm`, `readelf`, `objdump` |
| 09 | [Linker Script](./09-linker-script/) | → See [05-memory/13-linker-script](../05-memory/13-linker-script/) |
| 10 | [gcc / g++](./10-gcc-gpp/) | C vs C++ compilation |
| 11 | [arm-none-eabi](./11-arm-none-eabi/) | ARM cross-compiler |
| 12 | [Cross-compilation](./12-cross-compilation/) | Host → Target |
| 13 | [Compiler Flags](./13-compiler-flags/) | `-std=c++17`, `-Wall`, etc. |
| 14 | [Optimization](./14-optimization/) | `-O0` to `-Os` |
| 15 | [Debug vs Release](./15-debug-vs-release/) | Build configurations |
| 16 | [Warnings](./16-warnings/) | `-Wall`, `-Wextra`, `-Wpedantic` |
| 17 | [Make](./17-make/) | Makefile basics |
| 18 | [CMake](./18-cmake/) | CMakeLists.txt, toolchain files |
