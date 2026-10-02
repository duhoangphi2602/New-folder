# Solutions: Compiler Flags

## Solution 1: The Missing `-c` Flag
**Answer:** You forgot the **`-c`** flag.
The `-c` flag tells the toolchain: *"Compile this file into an Object file (`.o`), and then STOP. Do NOT run the Linker."* 
Because you omitted the `-c` flag, `g++` assumed you wanted to build the entire final executable. It compiled `main.cpp`, and then immediately invoked Stage 4 (The Linker) on the resulting object file. Because `main.cpp` calls hardware functions that exist in other `.cpp` files, the Linker panicked and threw "Undefined Reference" errors.

## Solution 2: `gnu++17` vs `c++17`
**Answer:** Variable Length Arrays (VLAs) are a feature of the **C** language (C99), but they are strictly illegal in the ISO **C++** standard. 
- `-std=gnu++17` enables the C++17 standard PLUS custom, non-standard GNU extensions. The GCC developers added VLAs into their C++ compiler as a custom feature.
- `-std=c++17` enforces strict ISO compliance. It disables all custom extensions.
**Which to use:** You should always use `-std=c++17`. If you use GNU extensions, your code will only ever compile on GCC. If your company decides to switch to Clang, MSVC, or the ARM Compiler, your code will instantly break. Furthermore, VLAs are incredibly dangerous in embedded systems because they dynamically allocate memory on the Stack, leading to unpredictable Stack Overflows.
