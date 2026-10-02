# Interview Questions: main() and Program Entry

## 1. What happens before `main()` is called on a bare-metal microcontroller?
**Answer:** When powered on, the hardware reads the Reset Vector and jumps to the Startup Code (often written in assembly). The startup code copies initialized global variables (`.data`) from Flash memory into RAM, zeroes out uninitialized global variables (`.bss`) in RAM, configures the system clock, calls global C++ constructors, and finally calls `main()`.

## 2. Why does embedded firmware typically contain an infinite loop inside `main()`?
**Answer:** Because there is no Operating System to return to. If `main()` exits, the CPU has no valid instructions left to execute and will either crash, hard-fault, or get trapped in a hidden default loop provided by the startup assembly. The infinite "Super Loop" ensures the application runs continuously as long as the device has power.

## 3. What is the difference between `main()` on a Linux OS versus FreeRTOS on a microcontroller?
**Answer:** On Linux, `main()` contains the entire lifecycle of the program and returns when the program finishes. On an MCU using FreeRTOS, `main()` is only used to configure hardware and create RTOS tasks. `main()` then calls the RTOS scheduler (e.g., `vTaskStartScheduler()`). The scheduler takes over the CPU entirely, and `main()` never actually returns or executes further code.
