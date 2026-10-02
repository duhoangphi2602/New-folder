# CMake

## 1. The Meta-Build System
CMake does **not** compile your code. It does **not** link your code. 
CMake is a "Meta-Build System". Its only job is to look at your project folder, read a configuration file (`CMakeLists.txt`), and automatically *write the Makefile for you*.
Once CMake generates the Makefile, you run standard `make` to actually invoke GCC and build the project.

## 2. Why use CMake?
- **Cross-Platform:** If a developer on Linux runs CMake, it generates a `Makefile`. If a developer on Windows runs CMake, it can generate a Visual Studio `.sln` file. You only maintain one `CMakeLists.txt` file!
- **Auto-Dependencies:** You never have to manually list header files as prerequisites again. CMake scans your `.cpp` files, finds every `#include`, and automatically wires up the complex dependency graph.
- **Library Management:** CMake makes linking 3rd-party libraries (like GoogleTest or FreeRTOS) incredibly easy using the `target_link_libraries` command.

## 3. The `CMakeLists.txt` File
Every CMake project requires a file explicitly named `CMakeLists.txt` in the root folder.
```cmake
# 1. Require a minimum version of CMake
cmake_minimum_required(VERSION 3.20)

# 2. Name the project and the language
project(MyFirmware CXX)

# 3. Create an Executable Target from source files
add_executable(firmware.elf main.cpp sensor.cpp)

# 4. Add Include Directories (The -I flag)
target_include_directories(firmware.elf PRIVATE include/)

# 5. Apply Compiler Flags (The -O2, -Wall flags)
target_compile_options(firmware.elf PRIVATE -Wall -O2)
```

## 4. The Standard Workflow (Out-of-Source Build)
You never want CMake to dump hundreds of generated temporary files into your clean source code folder. You use an "Out-of-Source" build.
1. Create a build folder: `mkdir build && cd build`
2. Run CMake (pointing it to the parent directory where `CMakeLists.txt` is): `cmake ..`
3. Run the generated Makefile: `make`

## 5. CMake for Embedded (The Toolchain File)
By default, CMake will search your PC and find your desktop compiler (e.g., Apple Clang or MSVC). 
To force CMake to use the `arm-none-eabi-g++` cross-compiler, you must pass it a **Toolchain File** (`-DCMAKE_TOOLCHAIN_FILE=...`). This file overrides the default OS compiler and hardcodes the paths to the ARM bare-metal toolchain.

## 6. Example
*(See `examples/` for a simulated CMake output).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
