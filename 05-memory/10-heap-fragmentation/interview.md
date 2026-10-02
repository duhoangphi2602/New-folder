# Interview Questions: Heap Fragmentation

## 1. What is the difference between External Fragmentation and Internal Fragmentation?
**Answer:** External Fragmentation occurs when free memory is split into small, non-contiguous holes scattered across the Heap, making it impossible to satisfy a large allocation request despite having enough total free RAM. Internal Fragmentation occurs when the allocator gives you a block of memory that is larger than what you actually requested (e.g., giving you a 64-byte Memory Pool block for a 10-byte request); the unused space inside that block is wasted but does not disrupt the allocator's mechanics.

## 2. Why can't an RTOS or microcontroller just "defragment" the Heap like a desktop Operating System does?
**Answer:** Defragmentation requires moving allocated chunks of memory to consolidate the free holes. In a C/C++ bare-metal environment, memory is accessed via direct physical hardware pointers. If the OS moves a chunk of memory, every single pointer in the application pointing to that chunk instantly becomes invalid, pointing to garbage data. (Languages like Java can defragment because their Garbage Collectors use an abstraction layer of "References" rather than raw physical pointers). Furthermore, pausing a real-time system to defragment memory would destroy hard real-time deadlines.

## 3. How does a Fixed-Size Block Allocator (Memory Pool) mathematically eliminate External Fragmentation?
**Answer:** External fragmentation is caused by allocating and freeing blocks of *different* sizes. If a 10-byte block is freed between two active allocations, it creates a 10-byte hole. If the next request is 12 bytes, it can't fit. 
In a Memory Pool, every single block is the exact same size (e.g., 64 bytes). Therefore, every single "hole" created by freeing a block is exactly 64 bytes. Any new request is always assigned a 64-byte block. Because all holes and all requests are identical in size, every request perfectly fits into every hole.
