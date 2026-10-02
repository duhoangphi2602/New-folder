# Solutions: Stack Overflow

## Solution 1: The Printf Trap
**Answer:** `printf` is notorious for consuming a massive amount of Stack memory (often 512 bytes to 1KB) because it has to allocate internal string buffers to format the `%f` floating-point numbers. If the microcontroller only has 2KB of RAM, the current function might already be using 1.5KB of the Stack. When `printf` is called, it pushes its own massive Stack Frame, overflowing the Stack, corrupting the system memory, and causing a watchdog timeout or a Hard Fault that reboots the chip.

## Solution 2: Watermark Canaries
**Answer:** If a Stack Overflow occurs, the global variables are silently corrupted, and the system begins behaving dangerously (e.g., spinning a motor at max speed uncontrollably). You must detect this corruption *as soon as it happens* so you can instantly shut down the hardware. If you wait until the end of `main()`, the system might run out of control for hours before it shuts down. A periodic background task (e.g., running every 10 milliseconds) guarantees that an overflow is caught almost immediately.
