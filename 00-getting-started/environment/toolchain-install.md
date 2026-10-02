# Toolchain Installation

A "toolchain" is the set of programs (compiler, linker, assembler) used to build software. 

## Native vs Cross-Compiler

1. **Native Compiler (`gcc`, `g++`)**: Compiles code to run on the machine you are using (e.g., your x86_64 PC).
2. **Cross-Compiler (`arm-none-eabi-gcc`)**: Compiles code on your PC to run on a different architecture (e.g., an ARM Cortex-M microcontroller).

For the first few chapters, we will use the **native** compiler. Later, we will install the cross-compiler.

## Installing ARM Cross-Compiler (For later chapters)

### Windows (MSYS2)
```bash
pacman -S mingw-w64-ucrt-x86_64-arm-none-eabi-gcc
```

### Linux / WSL
```bash
sudo apt install gcc-arm-none-eabi g++-arm-none-eabi binutils-arm-none-eabi
```

## CMake

CMake is a build system generator. Instead of writing complex Makefiles manually, we write a `CMakeLists.txt` file, and CMake generates the Makefiles (or Ninja files, or Visual Studio projects) for us. 

We use CMake extensively in this repository.
