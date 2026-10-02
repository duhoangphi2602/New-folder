# malloc() and free()

## 1. Concept
`malloc` (Memory Allocation) is a C Standard Library function that searches the Heap for a contiguous block of free memory of the requested size. If found, it marks that block as "used" and returns a pointer to its starting address. `free()` takes that pointer and marks the block as "free" again.

## 2. Why (The Dangers)
`malloc` is entirely manual. The compiler does not help you.
- **Memory Leak:** If you call `malloc` but forget to call `free`, the memory is lost forever.
- **Double Free:** If you call `free(ptr)` twice, you corrupt the heap management structures, usually causing an instant crash.
- **Dangling Pointer:** If you call `free(ptr)`, the memory is gone, but the variable `ptr` still holds the address. If you try to read `*ptr` later, you read garbage or crash.

## 3. Syntax

```c
#include <stdlib.h>
#include <stdio.h>

void process_data() {
    // 1. Allocate 100 bytes. 
    // malloc returns void*, so in C++ we MUST cast it.
    uint8_t* buffer = (uint8_t*)malloc(100);
    
    if (buffer == NULL) {
        // Out of memory!
        return; 
    }
    
    // 2. Use the memory
    buffer[0] = 0xFF;
    
    // 3. Manually free it
    free(buffer);
    
    // 4. Best practice: Nullify the dangling pointer
    buffer = NULL;
}
```

## 4. Example
*(See `examples/` for demonstrations of memory leaks and safe usage).*

## 5. Embedded usage (RTOS Wrappers)
In bare-metal embedded systems, the standard `malloc` is often physically disabled by the linker script because it is not thread-safe. If two RTOS tasks call `malloc` at the exact same microsecond, they might corrupt the heap.
Instead, RTOSs provide thread-safe wrappers (e.g., `pvPortMalloc` in FreeRTOS), which temporarily disable interrupts, safely allocate the memory, and then re-enable interrupts.

## 6. Trade-offs (Performance vs Flexibility)
`malloc` is non-deterministic. Sometimes it finds memory instantly. Sometimes the heap is fragmented, and it has to scan through thousands of addresses before it finds a big enough hole, taking 100x longer. In hard real-time systems (like ABS brakes), this unpredictable execution time is unacceptable.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
