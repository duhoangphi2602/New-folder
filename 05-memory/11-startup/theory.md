# The Startup Code

## 1. Concept
The Startup Code (often named `startup_stm32.s` or `startup.c`) is a small script provided by the silicon vendor. It bridges the gap between raw, uninitialized silicon hardware and the high-level C/C++ execution environment.

## 2. Why
To understand why it's needed, look at this code:
```cpp
int system_state = 5; // Global variable
int main() {
    if (system_state == 5) { boot(); }
}
```
`system_state` lives in RAM. When you plug in the battery, the RAM chip physically wakes up with random voltages (e.g., `0x8F3B91C2`). The number `5` is safely stored in the Flash memory. Something must physically copy the `5` from Flash into RAM *before* `main()` checks the variable. That "something" is the Startup Code.

## 3. The Boot Sequence (Step-by-Step)

When power is applied, the ARM Cortex-M CPU executes the following sequence:

1. **Hardware Init:** The CPU hardware automatically reads the first 4 bytes of Flash memory to find the starting address of the **Stack Pointer**, and loads it into the `SP` register.
2. **Reset Handler:** The CPU hardware reads the next 4 bytes of Flash memory. This is the address of the `Reset_Handler` function (the start of the Startup Code). The CPU jumps to it.
3. **Initialize `.data`:** The Startup Code loops through the `.data` section in Flash and copies every byte into the `.data` section in RAM.
4. **Initialize `.bss`:** The Startup Code loops through the `.bss` section in RAM and explicitly writes `0x00` to every byte.
5. **C++ Constructors (libc Init):** The Startup Code calls a C-library function (usually `__libc_init_array`) which executes the constructors for all global C++ objects.
6. **Call `main()`:** Finally, the Startup Code branches to `main()`.

## 4. Example
*(See `examples/` for a pseudo-code implementation of a C-based startup file).*

## 5. Embedded usage (C++ Global Objects)
In C, the startup code is simple. In C++, it is much more complex because of Constructors.
```cpp
class Sensor {
public:
    Sensor() { hardware_init(); }
};

Sensor my_sensor; // GLOBAL object

int main() {
    // By the time we reach here, my_sensor's constructor has ALREADY run!
}
```
If your startup code forgets to call `__libc_init_array`, your global C++ objects will never have their constructors executed. Their internal pointers will be null, and they will crash the moment you try to use them inside `main()`.

## 6. Trade-offs (Assembly vs C)
Historically, startup files were written in pure Assembly (`.s` files) because they require touching raw CPU registers (like the Stack Pointer) before the C environment exists. Modern toolchains often allow writing the startup file in bare-metal C (using linker-provided pointer symbols), which is vastly easier to read and maintain, though slightly less optimal than hand-tuned Assembly.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
