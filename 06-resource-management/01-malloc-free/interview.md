# Interview Questions: malloc() and free()

## 1. What happens if you call `malloc` and the Heap is full (Out Of Memory)?
**Answer:** `malloc` will return a Null Pointer (`NULL` in C, `nullptr` in C++). If the developer fails to check the return value and blindly attempts to dereference it (e.g., `ptr[0] = 5`), the CPU will attempt to write to memory address `0x00000000`, causing an immediate hardware Hard Fault.

## 2. Why is `malloc` considered non-deterministic, and why is this a problem for Real-Time Operating Systems (RTOS)?
**Answer:** `malloc` searches for a contiguous block of free memory. If the heap is highly fragmented (swiss cheese), `malloc` must traverse a linked list of free blocks, checking the size of each one until it finds a block large enough. This search could take 1 microsecond or 1,000 microseconds depending on the current state of fragmentation. Hard real-time systems require strict, guaranteed execution deadlines, which `malloc` mathematically cannot provide.

## 3. What is a "Dangling Pointer" and how do you prevent it?
**Answer:** A dangling pointer is a variable that holds the memory address of a block that has already been `free()`'d. The memory is no longer owned by the application, but the pointer still points to it. Accessing it causes undefined behavior. The standard defense is to explicitly set the pointer to `NULL` immediately after freeing it (`free(ptr); ptr = NULL;`).
