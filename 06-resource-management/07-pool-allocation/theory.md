# Pool Allocation

## 1. Concept
A Memory Pool is a large, statically allocated array (e.g., inside the `.bss` section) that is chopped up into many **equal-sized blocks**. 
When a task needs memory, it doesn't ask the OS to search a messy Heap for a random-sized hole. Instead, it simply asks the Pool Manager: *"Give me one of your predefined blocks."*

## 2. Why
- **Zero Fragmentation:** Because every block is exactly the same size, you can never get "swiss cheese" holes in your memory. A returned block perfectly fits the next request.
- **O(1) Deterministic Speed:** Allocating a block usually just involves taking the first item off a linked list or queue. It takes exactly the same number of CPU cycles every single time.
- **Flexibility:** Unlike strict static allocation (where each task permanently owns a buffer), a Pool allows Task A to use 10 blocks right now, and later Task B can use those same 10 blocks.

## 3. Architecture Overview

```text
STATIC BSS MEMORY: [------------------ 1024 Bytes ------------------]
POOL MANAGER cuts it up into 8 blocks of 128 Bytes each:
[ Block 0 ] [ Block 1 ] [ Block 2 ] ... [ Block 7 ]

FREE LIST (Pointers to available blocks):
-> Block 0 -> Block 1 -> Block 2 -> ... -> Block 7

ALLOCATE(): Pop first item off Free List. (O(1) time)
FREE(): Push item back onto Free List. (O(1) time)
```

## 4. Syntax / Implementation (Conceptual)
```cpp
template<typename T, size_t PoolSize>
class MemoryPool {
    // 1. Statically allocate memory for all blocks
    std::array<T, PoolSize> memory_blocks;
    
    // 2. A simple array or linked list to track which blocks are free
    std::array<bool, PoolSize> is_free;
    
public:
    MemoryPool() { is_free.fill(true); }

    // Allocate: Find first free block
    T* allocate() {
        for (size_t i = 0; i < PoolSize; ++i) {
            if (is_free[i]) {
                is_free[i] = false;
                return &memory_blocks[i];
            }
        }
        return nullptr; // Pool empty!
    }

    // Free: Mark block as available
    void deallocate(T* ptr) {
        // (Pointer math to find index, then is_free[index] = true)
    }
};
```
*(Note: A real RTOS pool uses lock-free Linked Lists instead of a slow `bool` array search, but the concept is identical).*

## 5. Example
*(See `examples/` for a runnable demonstration of a simple fixed-size memory pool).*

## 6. Embedded usage (RTOS and C++)
In FreeRTOS, `xQueueCreate` and `xMessageBufferCreate` are built on similar concepts.
In Modern C++, you can override the `new` operator for a specific class to automatically pull memory from a Custom Memory Pool instead of the standard Heap!
```cpp
class SensorPacket {
public:
    // When you type 'new SensorPacket()', it pulls from the Pool!
    void* operator new(size_t size) { return my_pool.allocate(); }
    void operator delete(void* ptr) { my_pool.deallocate((SensorPacket*)ptr); }
};
```

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
