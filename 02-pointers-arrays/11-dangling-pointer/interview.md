# Interview Questions: Dangling Pointer

## 1. What is a dangling pointer?
**Answer:** A dangling pointer is a pointer that holds a memory address belonging to a variable or object that has already been destroyed, freed, or has gone out of scope.

## 2. Why is dereferencing a dangling pointer often considered worse than dereferencing a null pointer?
**Answer:** Dereferencing a null pointer causes an immediate, deterministic crash (like a Hard Fault or Segmentation Fault) at exactly the line of code where the error occurred, making it easy to fix. Dereferencing a dangling pointer causes silent memory corruption or reading garbage data; the program might keep running and crash hours later in a completely unrelated module, making it incredibly difficult to debug.

## 3. How do you prevent "Use-After-Free" dangling pointer bugs in C?
**Answer:** Immediately after calling `free(ptr);`, you must assign `ptr = NULL;`. This ensures that if the pointer is accidentally used again, it will trigger an immediate null-pointer exception rather than corrupting memory.

## 4. What happens if you return a pointer to a local variable?
**Answer:** The local variable is allocated on the stack. When the function returns, its stack frame is popped/destroyed. The returned pointer now points to memory that will be immediately overwritten by the very next function call the program makes.
