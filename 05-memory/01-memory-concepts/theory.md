# Memory Concepts (RAM vs ROM)

## 1. Concept
An embedded microcontroller usually has two physically separate memory chips inside it:
- **Flash (ROM):** Non-Volatile. It holds data even when the power is turned off. It is relatively large (e.g., 512KB) but slow to write to.
- **SRAM (RAM):** Volatile. It loses all data the microsecond power is removed. It is very small (e.g., 64KB) but incredibly fast.

## 2. Why
To optimize costs, silicon manufacturers give you just enough RAM to hold your active variables, and a larger block of Flash to hold your compiled code (`.bin` or `.hex` file).
If you declare a massive array of sine-wave values, and you let the compiler put it in RAM, your program won't even compile because it won't fit. You must tell the compiler to leave that array in Flash.

## 3. Execute-In-Place (XIP)
On a PC, when you double-click a `.exe`, the OS copies the entire `.exe` from your SSD into RAM, and the CPU executes it from RAM.
On an ARM Cortex-M microcontroller, the CPU fetches instructions directly from the Flash memory over a dedicated hardware bus. The code is **never copied to RAM**. This is called Execute-In-Place (XIP). It is the reason microcontrollers can boot up and start running code in less than 1 millisecond.

## 4. Syntax (Saving RAM with `const`)

How do you tell the compiler to leave a variable in Flash and not copy it to RAM? In C/C++, you use the `const` keyword (or `constexpr` in modern C++).

```cpp
// 1. Goes into RAM (Volatile, can be changed)
int active_speed = 100;

// 2. Goes into RAM (Takes up 400 bytes of precious SRAM!)
int lookup_table[100] = {1, 2, 3, ...};

// 3. Stays in FLASH (Takes up 0 bytes of RAM, uses 400 bytes of Flash)
const int flash_lookup_table[100] = {1, 2, 3, ...};

// 4. Modern C++ way (Guaranteed compile-time evaluation and Flash storage)
constexpr int modern_lookup_table[100] = {1, 2, 3, ...};
```

## 5. Example
*(See `examples/` for runnable code demonstrating the difference in memory addresses).*

## 6. Embedded usage (Lookup Tables and Strings)
Strings are a notorious source of RAM bloat.
```cpp
void print_menu() {
    // If your compiler is poorly configured, it might copy this entire 
    // string into RAM every time the function is called!
    printf("1. Start\n2. Stop\n3. Config\n4. Exit\n"); 
}
```
In professional embedded C++, massive static datasets (like UI menus, font bitmaps for OLED screens, or audio samples) are always explicitly marked as `const` to ensure they remain in Flash memory.

## 7. Trade-offs (Flash vs RAM Access Speed)
Flash memory is inherently slower than RAM. If your CPU runs at 168MHz (like an STM32F4), it cannot read from Flash in 1 clock cycle; it might take 3 to 5 clock cycles (Wait States). Reading from RAM always takes 1 clock cycle.
Therefore, if you have a variable that you read millions of times per second inside an interrupt, it might actually be better to leave it in RAM (remove `const`), trading memory space for execution speed!

## 8. Exercises
Please proceed to the `exercises/` folder.

## 9. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
