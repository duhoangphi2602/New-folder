# Interview Questions: Variables and Addresses

## 1. What does the `&` operator do when applied to a variable?
**Answer:** The `&` (address-of) operator retrieves the memory address where the variable is stored in RAM. 

## 2. If a `uint64_t` variable occupies 8 bytes of memory, which byte's address is returned by the `&` operator?
**Answer:** The `&` operator always returns the address of the **first** (lowest) byte of the variable, regardless of how many bytes the total variable consumes. 

## 3. What is the difference between physical addresses and virtual addresses?
**Answer:** A physical address corresponds to a literal, physical wire on the memory bus of the hardware (e.g., SRAM or Flash on an MCU). A virtual address is a fake address provided by a Desktop Operating System (via an MMU - Memory Management Unit) to isolate programs from each other; the OS translates this virtual address into a physical one in the background. Bare-metal embedded programming typically deals strictly with physical addresses.
