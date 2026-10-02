# Solutions: Pool Allocation

## Solution 1: The Fragmentation Defense
**Answer:** The entire reason Memory Pools are immune to fragmentation is that every block is identically sized. If a block is freed, the "hole" left behind will perfectly accommodate the next allocation request. If you allow variable sizes, freeing a 10-byte block leaves a tiny hole that cannot fit a 500-byte request. You have just reinvented the standard Heap, and introduced fragmentation back into your safety-critical system.

## Solution 2: Out of Memory Recovery
**Answer:** In an RTOS, if a pool is empty, the RTOS API (e.g., `xQueueReceive` or `xMessageBufferReceive`) allows the calling Task to **Block (Sleep)** for a specified timeout. The Task is removed from the CPU execution queue. As soon as another Task finishes its work and frees a block back into the pool, the RTOS scheduler instantly wakes up the sleeping Task and hands it the newly freed block. This provides a clean, deterministic way to handle temporary overload conditions without crashing.
