# Solutions: Memory Concepts (RAM vs ROM)

## Solution 1: The Out-of-Memory Bug
**Answer:** The array is 40,000 bytes (40KB). Because it is not declared as `const`, the compiler assumes you might want to modify the image during runtime. Therefore, it instructs the system to allocate 40KB of RAM to hold the array. Since the microcontroller only has 32KB of RAM, the linker throws an overflow error.
**The Fix:** Add the `const` keyword.
`const uint8_t splash_screen_image[40000] = {...};`
Because it is `const`, the compiler leaves the array perfectly intact inside the 256KB Flash memory, consuming 0 bytes of RAM.

## Solution 2: Harvard vs Von Neumann
**Answer:** 
- In **Von Neumann** (PCs), data (RAM) and instructions (ROM/Code) share the exact same physical bus to the CPU. The CPU cannot fetch an instruction and read a data variable at the same exact time; they cause a traffic jam.
- In **Harvard** (Microcontrollers), there are physically separate buses for Instructions and Data. The CPU can fetch the next line of code from Flash (Instruction Bus) at the exact same microsecond it is reading a sensor value from RAM (Data Bus). This allows the microcontroller to execute instructions much faster per clock cycle.
