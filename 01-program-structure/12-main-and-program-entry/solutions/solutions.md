# Solutions: main() and Program Entry

## Solution 1: The Accidental Return
**Answer:** If `main()` returns `-1`, the CPU will jump back to the startup code that called `main()`. Most vendor startup code handles this by immediately dropping into a hidden infinite loop (`while(1) {}`), meaning the MCU will lock up completely, requiring a hard reset. Some poorly written startup code might just let the CPU continue executing garbage memory past the end of the stack, causing a Hard Fault.
**The Fix:** Instead of returning, trap the CPU in an intentional error loop, or trigger a hardware reset (Watchdog).
```cpp
if (temp > 100) {
    display_warning("FIRE!");
    while(1) { /* Blink error LED indefinitely */ }
    // OR trigger a system reset: NVIC_SystemReset();
}
```

## Solution 2: `argc` and `argv`
**Answer:** `argc` (argument count) and `argv` (argument vector) are passed by the Operating System when a user runs a program from a command line terminal (e.g., `./my_program --verbose`). A bare-metal microcontroller has no OS, no command line terminal, and no concept of passing arguments to the firmware at boot time. Therefore, they are meaningless.

## Solution 3: Order of Operations
**Answer:** B → E → C → A → D
1. (B) The CPU hardware jumps to the Reset Vector.
2. (E) Global variables are copied from Flash to RAM (by Startup code).
3. (C) Global C++ constructors are called (by Startup code).
4. (A) `main()` is called.
5. (D) The Super Loop begins executing.
