# Compiler Flags

## 1. What are Flags?
Flags are command-line arguments passed to the `gcc` or `g++` executable. 
They usually start with a hyphen (`-`).
`arm-none-eabi-g++ -std=c++17 -mcpu=cortex-m4 main.cpp -o app.elf`

## 2. Language Standard Flags
C++ is a constantly evolving language (C++98, C++11, C++14, C++17, C++20).
By default, older GCC versions might compile your code as C++98. If you try to use a modern feature like `std::string_view` or `std::variant`, the compiler will throw a Syntax Error.
- **`-std=c++17`**: Forces the compiler to strictly obey the 2017 ISO C++ standard.
- **`-std=gnu++17`**: Allows C++17, but also enables GNU-specific extensions (non-standard features). It is best practice to stick to pure `-std=c++17` for portability.

## 3. Architecture Flags (The `-m` flags)
When cross-compiling, the tuple `arm-none-eabi` just means "Generic ARM". But ARM makes dozens of different chips (Cortex-M0, M3, M4, M7). 
You must explicitly tell the compiler *exactly* which silicon you are targeting, so it can generate the correct machine code dictionary.
- **`-mcpu=cortex-m4`**: Tells the Assembler exactly which instruction set to use.
- **`-mthumb`**: Forces the compiler to use the compressed 16-bit Thumb-2 instructions (mandatory for Cortex-M).
- **`-mfloat-abi=hard`**: Tells the compiler to use hardware registers (`S0`) for decimals.
- **`-mfpu=fpv4-sp-d16`**: Tells the compiler exactly which physical math coprocessor is on the chip.

## 4. Include Paths (`-I`)
If you write `#include "sensor.h"`, the Preprocessor searches the current folder. 
What if `sensor.h` is inside a folder named `drivers/`? 
You use the Include flag to tell the Preprocessor where to look.
- **`-I drivers/`**: Adds the `drivers/` directory to the search path. Now `#include "sensor.h"` works perfectly.

## 5. Defines (`-D`)
You can define Macros directly from the command line, without touching the C++ code!
- **`-DDEBUG_MODE`**: This is exactly the same as writing `#define DEBUG_MODE` at the top of every single file. It is heavily used to switch between Debug and Release builds.
- **`-DSTM32F401xC`**: Informs the manufacturer's HAL libraries exactly which chip variant is being used.

## 6. Example
*(See `examples/` for a fully constructed compiler command).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
