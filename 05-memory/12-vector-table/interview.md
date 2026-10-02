# Interview Questions: The Vector Table

## 1. What is a Vector Table in an ARM Cortex-M architecture?
**Answer:** The Vector Table is an array of 32-bit addresses located at the very beginning of the memory map (usually Flash memory). It contains the initial Stack Pointer value at index 0, followed by the memory addresses (function pointers) of all the Interrupt Service Routines (ISRs) and system Exception Handlers (like `Reset_Handler` and `HardFault_Handler`). The hardware uses this table to automatically route execution to the correct function when a hardware event occurs.

## 2. How does the concept of "Weak Aliasing" help in creating maintainable embedded projects?
**Answer:** In the vendor-provided startup code, all interrupt vectors are populated with "Weak" function definitions that point to a default infinite loop handler. "Weak" tells the linker: "Use this default function *unless* the developer writes a function with the exact same name." This allows the developer to easily implement `void TIM2_IRQHandler()` in their `main.cpp` to handle Timer 2, without ever having to modify the core startup code or manually edit the Vector Table array.

## 3. If you want to create a Bootloader that jumps to a Main Application, why do you have to modify the SCB->VTOR (Vector Table Offset Register)?
**Answer:** A Bootloader lives at the start of Flash (`0x08000000`), so it uses the default Vector Table. The Main Application is flashed further down (e.g., `0x08010000`), and it has its own, completely different Vector Table for its own interrupts. When the Bootloader jumps to the Main Application, if a UART interrupt fires, the CPU will still look at the Bootloader's Vector Table at `0x08000000` and crash. You must write to the hardware `VTOR` register to tell the CPU: "The new Vector Table is now located at `0x08010000`" before jumping to the application.
