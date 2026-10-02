# Interview Questions: Safe Dynamic Allocation

## 1. In what scenario is Dynamic Allocation completely unavoidable in embedded systems?
**Answer:** When the device must process data whose maximum size is fundamentally unknowable or wildly variable at compile-time, such as parsing arbitrary JSON/XML from an external cloud server, or processing TLS/SSL cryptographic handshakes. Statically allocating for the theoretical maximum of a TLS handshake would consume more RAM than the entire microcontroller possesses.

## 2. Describe the "Allocate Once, Run Forever" pattern and explain why it is considered safe by many embedded standards.
**Answer:** The pattern dictates that all dynamic allocations (`malloc`/`new`) must happen exclusively during the initialization phase (bootup), before the main RTOS scheduler or main loop begins. Once the main loop starts, no further allocations are allowed, and `free`/`delete` is strictly forbidden forever. This is safe because it completely eliminates both fragmentation (since nothing is ever freed to create holes) and non-deterministic latency during the mission-critical loop, while still allowing the firmware to adapt to hardware configurations at boot time.

## 3. What is Heap Coalescing, and how does it help embedded systems?
**Answer:** Coalescing is an algorithm used by advanced RTOS memory managers (like FreeRTOS `heap_4.c`). When you call `free()`, the manager doesn't just mark the block as available. It actively checks the adjacent blocks in physical memory. If the block to the left or right is also free, it mathematically merges them into a single, larger free block. This actively fights fragmentation by ensuring that small adjacent holes are combined back into usable large contiguous blocks.
