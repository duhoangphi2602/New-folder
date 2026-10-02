# Interview Questions: Pool Allocation

## 1. How does a Fixed-Size Memory Pool achieve O(1) allocation time, and why is this critical for RTOS environments?
**Answer:** A proper memory pool links all free blocks together using a Singly Linked List (often storing the `next` pointer directly inside the unused memory block itself to save space). To allocate, the manager simply pops the Head of the linked list. To free, it pushes the block back onto the Head. Both operations take exactly 2 or 3 assembly instructions, meaning it takes exactly the same number of CPU cycles every time (O(1)). This determinism is critical for RTOS environments, where tasks must meet hard deadlines. Standard `malloc` must search an unpredictable heap, which is O(N) and non-deterministic.

## 2. In modern C++, how can you transparently swap standard Heap allocation for Memory Pool allocation for a specific object type?
**Answer:** You can overload the `operator new` and `operator delete` methods specifically inside the class definition. When the rest of the code calls `std::make_unique<MyClass>()`, the C++ runtime will automatically bypass the global system heap and call your class's overloaded `new` operator, which draws memory from your custom Pool. This allows you to use Modern C++ Smart Pointers while maintaining strict bare-metal RTOS memory constraints.

## 3. What happens to a Memory Pool if you have a Memory Leak (someone forgets to call `free`/`delete`)?
**Answer:** A Memory Pool does not magically solve Memory Leaks; it only solves Fragmentation and Latency. If you continuously allocate blocks from the pool and fail to free them, the pool will eventually empty out. Future allocation requests will fail. This is why Memory Pools in modern embedded systems should always be paired with C++ RAII (Smart Pointers) to mathematically guarantee that blocks are returned to the pool.
