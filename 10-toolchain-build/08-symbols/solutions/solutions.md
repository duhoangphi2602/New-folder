# Solutions: Symbols

## Solution 1: The Size of an Array
**Answer:** The addresses in the Symbol Table are in Hexadecimal.
- `sensor_data` starts at `0x20000400`.
- The very next variable, `rx_buffer`, starts at `0x20000590`.
- This means `sensor_data` takes up the space between them. 
- `0x590 - 0x400 = 0x190` bytes.
- Convert Hex `0x190` to Decimal: `1 * 256 + 9 * 16 + 0 = 400` bytes.
- A `uint32_t` is 4 bytes. `400 bytes / 4 bytes per int = 100 ints`.
The math perfectly proves the array size!

## Solution 2: `extern "C"`
**Answer:** The Linker failed because of **C++ Name Mangling**.
When `g++` compiled `main.cpp`, it saw the call to `init_driver()` and mangled the requirement into something like `_Z11init_driverv`. It left an Undefined ('U') symbol for `_Z11init_driverv`.
However, `gcc` compiled the C driver. C does not support function overloading, so C compilers *never* mangle names. It generated a Defined ('T') symbol for exactly `init_driver`.
The Linker looked for `_Z11init_driverv`, couldn't find it, and crashed.
Wrapping the `#include` in an `extern "C" { }` block tells the C++ compiler: *"Do not mangle the names of the functions in this header file. Leave them as raw C names."* The C++ compiler then asks the Linker for `init_driver`, which perfectly matches the C object file.
