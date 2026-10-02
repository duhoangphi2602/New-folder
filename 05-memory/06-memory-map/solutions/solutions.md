# Solutions: The Memory Map

## Solution 1: The Hard Fault
**Answer:** The address `0x10000000` falls within the Code/Flash region. Flash memory on a microcontroller is physically **Read-Only** during normal execution. The CPU's internal memory protection unit (or the physical bus matrix) detects an illegal "Write" operation targeting a Read-Only physical memory block and instantly triggers a Hard Fault hardware exception to prevent corruption. Address `0x20000000` is SRAM, which is explicitly designed for Read/Write operations.

## Solution 2: Peripherals
**Answer:** The memory map assigns distinct regions to prevent overlap. If a GPIO peripheral was mapped to `0x20000000`, and a C++ local variable (Stack) was also allocated at `0x20000000`, writing to the variable would accidentally turn on an LED! By segregating RAM to `0x20` and Peripherals to `0x40`, the silicon designers guarantee that software variables and hardware control registers will never collide in the address space.
