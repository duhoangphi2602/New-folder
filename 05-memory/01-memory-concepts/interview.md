# Interview Questions: Memory Concepts

## 1. What is the difference between Volatile and Non-Volatile memory? Give an example of each in an embedded system.
**Answer:** Volatile memory loses all of its contents the moment electrical power is removed. SRAM (Static RAM) is the primary volatile memory in microcontrollers, used for variables and the call stack. Non-Volatile memory retains its data without power. NOR Flash is the primary non-volatile memory in microcontrollers, used to store the compiled application code (`.bin` firmware) and constant data like lookup tables.

## 2. What does Execute-In-Place (XIP) mean?
**Answer:** Execute-In-Place means the CPU fetches and executes machine code instructions directly from the Flash (ROM) memory over the internal hardware bus. The code is not copied into RAM first. This allows microcontrollers to boot almost instantaneously and allows them to function with extremely small amounts of RAM (e.g., 20KB of RAM running a 500KB program).

## 3. You have a constant lookup table that is accessed heavily inside a high-frequency Interrupt Service Routine. Should you put it in Flash or RAM?
**Answer:** While putting it in Flash (using `const`) saves RAM, Flash memory access is generally slower than SRAM access, often requiring CPU "Wait States" at higher clock frequencies (e.g., > 100MHz). If the lookup table is small enough to fit comfortably in RAM, and the interrupt requires absolute maximum performance (e.g., a 100kHz motor control loop), you should intentionally leave it in RAM to guarantee 1-cycle access times. This is a classic Space vs. Speed trade-off.
