# Interview Questions: Heap Fragmentation

## 1. What is the difference between "Total Free Memory" and "Largest Free Block"?
**Answer:** Total Free Memory is the absolute sum of all unused bytes in the RAM. Largest Free Block is the size of the single largest contiguous chunk of unused bytes. Due to fragmentation, a system might have 1 MB of Total Free Memory, but if it is chopped up into thousands of tiny pieces, the Largest Free Block might only be 2 KB. If a task requests `malloc(3KB)`, it will fail, even though there is 1 MB total available.

## 2. In FreeRTOS, how do Memory Pools (like Queues) prevent fragmentation?
**Answer:** Fragmentation only occurs when blocks of *varying* sizes are allocated and freed, leaving uneven holes. Memory Pools pre-allocate a chunk of memory and divide it into blocks of the exact same size. When a block is freed, the hole it leaves behind is mathematically guaranteed to be the exact perfect size for the next allocation request. Therefore, a Memory Pool can never become fragmented.

## 3. If you must use dynamic allocation in an embedded system, what architectural rules should you follow to minimize fragmentation?
**Answer:** 
1. **Allocate early, never free:** Allocate all dynamic buffers during the boot sequence before the RTOS scheduler starts. Never call `free()`.
2. **LIFO (Stack) pattern:** If you must allocate/free, try to do it in a strict Last-In-First-Out order, mirroring how the Stack works, which prevents internal holes.
3. **Use custom allocators:** Instead of a global heap, assign specific tasks their own private heaps or Memory Pools tailored to their exact object sizes.
