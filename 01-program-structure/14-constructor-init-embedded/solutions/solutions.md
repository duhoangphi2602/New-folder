# Solutions: Constructor Initialization

## Solution 1: The Hardware Crash
**Answer:** The Static Initialization Order Fiasco. The C++ standard does not guarantee the initialization order of global objects across different translation units (and even within the same file, the order is based on textual appearance). If the compiler constructs `g_i2c` before `g_clock`, the `I2C_Driver` constructor will attempt to write to hardware registers before the system clock is enabled, resulting in an immediate MCU Hard Fault before `main()` starts.

## Solution 2: Meyer's Singleton Drawback
**Answer:** To guarantee the object is constructed exactly once, the compiler secretly generates a hidden boolean flag (a guard variable). Every single time `get_uart()` is called, the CPU must execute an `if` statement:
```cpp
// What the compiler actually generates:
static Uart instance;
static bool initialized = false;
if (!initialized) {
    construct(&instance);
    initialized = true;
}
return instance;
```
This introduces a small, hidden runtime overhead (a branch instruction) on every single access. While negligible on a desktop, it can be problematic in ultra-tight RTOS interrupt loops.

## Solution 3: Global Destructors
**Answer:** In bare-metal embedded firmware, `main()` contains an infinite loop (`while(1)`) and is designed to **never return**. Because the program never exits, the code that cleans up global variables is completely dead code that will never be reached. Deleting the `.fini_array` and the destructor logic saves valuable Flash memory without causing any harm.
