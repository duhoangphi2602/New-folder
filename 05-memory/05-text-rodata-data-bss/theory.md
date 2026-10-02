# Memory Segments (.text, .rodata, .data, .bss)

## 1. Concept
Every line of code and every global variable you write is sorted by the compiler into one of four buckets (segments).
- **.text**: The actual executable machine code instructions.
- **.rodata**: Read-Only Data (Constants).
- **.data**: Initialized global/static variables.
- **.bss**: Uninitialized global/static variables.

## 2. Why
The microcontroller needs to know where to put these buckets.
- `.text` and `.rodata` are burned permanently into **Flash (ROM)**.
- `.data` and `.bss` are loaded into **SRAM (RAM)** when the microcontroller boots up.

*(Note: Stack and Heap are also in RAM, but they are managed dynamically at runtime. `.data` and `.bss` are determined strictly at compile time).*

## 3. The Four Buckets Explained

### 1. `.text` (Code) -> FLASH
Contains the compiled Assembly instructions of your functions.
```cpp
void loop() { int x = 5; } // The machine instructions for this function go into .text
```

### 2. `.rodata` (Read-Only Data) -> FLASH
Contains all variables marked `const`, plus string literals.
```cpp
const int max_speed = 100;           // Goes into .rodata
printf("System Booting...");         // The string "System Booting..." goes into .rodata
```

### 3. `.data` (Initialized Data) -> RAM (and FLASH)
Contains global or static variables that have a **specific non-zero starting value**.
```cpp
int system_state = 5;                // Goes into .data
static float calibration_offset = 1.5f; // Goes into .data
```
*Wait, if RAM loses power, how does `system_state` start at 5?*
The compiler actually stores the number `5` in Flash! When the microcontroller boots, a tiny startup script copies the `5` from Flash into the `.data` section of RAM before `main()` is called.

### 4. `.bss` (Block Started by Symbol) -> RAM
Contains global or static variables that are **uninitialized** (or initialized to 0).
```cpp
int error_count;                     // Goes into .bss
static uint8_t rx_buffer[1024];      // Goes into .bss
int is_ready = 0;                    // Goes into .bss (optimized to 0)
```
*Why separate `.data` from `.bss`?*
To save Flash memory! If you have a 10KB `rx_buffer` filled with zeros, storing 10,000 zeros in Flash is a waste. Instead, the startup script simply loops through the `.bss` section in RAM and writes zeros to it. The `.bss` section takes up **zero bytes** in your firmware `.bin` file!

## 4. Example
*(See `examples/` for a practical breakdown of variables into segments).*

## 5. Embedded usage (The Linker Output)
When you compile an embedded project using GCC, it outputs a summary like this:
```
   text    data     bss     dec     hex filename
  24500     120    4500   29120    71c0 firmware.elf
```
- **Flash Consumed:** `text` + `data` = 24,620 bytes.
- **RAM Consumed:** `data` + `bss` = 4,620 bytes.

If your RAM usage is too high, you must look at your `.data` and `.bss` variables. If your Flash usage is too high, you must look at your `.text` (too much code) or `.rodata` (too many const arrays/strings).

## 6. Trade-offs (The `.data` Bloat)
Avoid `.data` if possible. Every byte of a `.data` variable consumes 1 byte of RAM **AND** 1 byte of Flash (to store the initial value). 
If you can logically initialize a variable at runtime (e.g., `buffer[i] = x;` inside a function) instead of at compile time, it moves from `.data` to `.bss`, saving you precious Flash memory.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
