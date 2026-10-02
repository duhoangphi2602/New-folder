# Solutions: Static Allocation

## Solution 1: The Wasted RAM Problem
**Answer:** 
4 sensors * 1KB/sec = 4KB generated per second.
Worst-case radio outage = 10 seconds.
4KB/sec * 10 seconds = 40KB.
You must permanently reserve a 40KB `std::array` in the `.bss` section. Even if the radio connection is perfect 99% of the time, that 40KB of RAM can never be used for anything else. This is the main trade-off of Static Allocation.

## Solution 2: Static Local vs Global
**Answer:** No, it does not live on the Stack. Because of the `static` keyword, the compiler places `temp_buffer` into the `.bss` section alongside global variables. It is allocated exactly once. If multiple RTOS tasks call `process_packet()` simultaneously, they will both read and write to the exact same memory address at the same time, corrupting each other's data (a Race Condition).
