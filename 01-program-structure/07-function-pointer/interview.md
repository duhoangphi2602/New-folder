# Interview Questions: Function Pointers

## 1. What is a callback function?
**Answer:** A callback function is a function whose address is passed as an argument to another function (or module). The receiving module will store this address (as a function pointer) and "call back" the function at a later time, such as when an asynchronous hardware event occurs.

## 2. How would you implement a dispatch table (jump table) in C?
**Answer:** You create an array of `struct`s. Each `struct` contains a command ID (integer) and a function pointer to the handler for that command. When a command arrives, you loop through the array (or index directly if IDs are sequential) and execute the matching function pointer. This replaces massive, unreadable `switch-case` blocks.

## 3. Can a C++ lambda function be used as a C function pointer?
**Answer:** Yes, but **only if the lambda is stateless** (its capture list `[]` is entirely empty). If the lambda captures any variables from its surrounding scope, it becomes a stateful object (a functor) and cannot be converted to a raw C function pointer.

## 4. Why should you prefer raw function pointers over `std::function` in bare-metal embedded C++?
**Answer:** `std::function` is a heavy, type-erased wrapper that can allocate memory on the heap (dynamic allocation) if the callable object it stores is too large. Heap allocation is generally banned in safety-critical bare-metal systems due to fragmentation risks and non-deterministic execution times. Raw function pointers have zero overhead.
