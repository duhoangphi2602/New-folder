# Solutions: Cross Compilation

## Solution 1: The Missing OS
**Answer:** The `arm-none-eabi` cross-compiler specifically targets "Bare-Metal" (the `none` field in the tuple). While it is a fully compliant C++ compiler for language syntax, the implementation of `<thread>` strictly requires an underlying Operating System (like Windows, Linux, or FreeRTOS) to manage the thread creation and scheduling via System Calls. Because the cross-compiler is configured for an environment with no OS, it physically cannot implement the threading library. You must use hardware timers or an RTOS to implement delays.

## Solution 2: `newlib` vs `glibc`
**Answer:** On a desktop PC, functions like `printf` or `malloc` are part of the OS's massive Shared Libraries (like `glibc.so` or `msvcrt.dll`). When you compile a desktop app, the compiler doesn't put the machine code for `printf` into your `.exe`; it just leaves a pointer saying "Ask Windows to do this at runtime." This keeps the `.exe` very small (120 KB).
In a bare-metal microcontroller, there is no OS. There are no shared libraries. The cross-compiler is forced to take the actual, physical machine code implementation of `printf` from `newlib` and statically link it directly into your `.bin` file. A full implementation of `printf` (with floating-point formatting support) is incredibly complex and can add 50 KB - 100 KB of raw code to your firmware. (The fix is to use the `-specs=nano.specs` flag to link `newlib-nano`, a highly stripped-down version of the library).
