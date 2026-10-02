# Interview Questions: Process, Thread, and Task

## 1. Can a Cortex-M4 microcontroller run a full Linux Operating System? Why or why not?
**Answer:** No, it cannot. A full Linux OS requires true Process Isolation to ensure that one application cannot overwrite the memory of another application. This isolation requires a hardware component called a Memory Management Unit (MMU), which maps virtual memory to physical RAM. Cortex-M series processors (like M0, M3, M4) do not have an MMU; they only have physical memory. Therefore, they must run RTOSs (like FreeRTOS) where all tasks share the same flat memory space. (Note: Cortex-A processors, like those in Raspberry Pi or smartphones, do have MMUs and run Linux).

## 2. In an RTOS, what happens to global variables? Are they duplicated for each Task?
**Answer:** No, global variables are perfectly shared across all Tasks. They reside in the single `.data` or `.bss` section of the firmware. If Task A modifies a global variable, Task B will instantly see the modified value. This makes data sharing extremely fast, but highly dangerous, requiring Mutexes or Atomic operations to prevent Race Conditions.

## 3. Why doesn't standard C++ `std::thread` work out-of-the-box on bare-metal microcontroller toolchains?
**Answer:** `std::thread` relies on the underlying Operating System's threading API (like POSIX `pthread` on Linux, or the Windows Thread API). A bare-metal microcontroller compiler (like standard `arm-none-eabi-gcc` without an OS layer) has no built-in Operating System to route those calls to. To use threads, you must manually integrate an RTOS, and usually use the RTOS's specific C API (e.g., `xTaskCreate`), unless you provide a custom port that maps C++ `std::thread` calls to the RTOS functions.
