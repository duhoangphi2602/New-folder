# The Heap

## 1. Concept
The Heap is a large pool of free RAM. Unlike the Stack (which is fully automatic and rigid), the Heap allows you to request chunks of memory of any size at runtime. 
- You request a chunk using `malloc()` (C) or `new` (C++).
- You are strictly responsible for returning that chunk using `free()` (C) or `delete` (C++).

## 2. Why
If you don't know how much memory you need until the program is running (e.g., receiving a network packet of unknown size), you cannot use a Static Array or a Stack Array (since their sizes must be known at compile time). You must dynamically allocate it on the Heap.

## 3. Syntax (Allocation and Deallocation)

```cpp
// C-Style (malloc / free)
uint8_t* c_buffer = (uint8_t*)malloc(1024); // Request 1024 bytes
if (c_buffer != NULL) {
    // Use buffer...
    free(c_buffer); // RETURN IT!
}

// C++ Style (new / delete)
uint8_t* cpp_buffer = new uint8_t[1024]; 
// Use buffer...
delete[] cpp_buffer; // RETURN IT!
```

## 4. Example
*(See `examples/` for runnable code demonstrating memory leaks).*

## 5. Embedded usage (The Ban on Dynamic Allocation)
In systems where human lives or expensive hardware are at risk (Automotive ISO 26262, Aerospace DO-178C, Medical), **Dynamic Memory Allocation is completely banned after initialization.**

There are two fatal flaws with the Heap:
1. **Memory Leaks:** If a developer forgets to call `free()` or `delete`, or an exception bypasses the `delete` statement, the memory is permanently lost. Eventually, the Heap empties, `malloc` returns `NULL`, and the system crashes.
2. **Heap Fragmentation:** Even if you perfectly `free()` every chunk, the Heap can still crash! If you allocate and free small and large chunks in random orders, the Heap becomes "fragmented"—resembling Swiss cheese. You might have 10KB of free RAM total, but it is split into 1,000 tiny 10-byte holes. If you ask for a contiguous 100-byte buffer, `malloc` will fail, and the system crashes.

## 6. Trade-offs (Static vs Dynamic)
How do you survive without the Heap? You pre-allocate everything globally at compile time.
- **Dynamic Way:** Receive packet. `malloc(size)`. Process. `free()`.
- **Embedded Way:** Create a global `uint8_t rx_buffer[MAX_EXPECTED_SIZE];`. Always use this single buffer. If a packet arrives larger than `MAX_EXPECTED_SIZE`, reject it.

This guarantees your system uses a deterministic amount of RAM and can run for 10 years without ever crashing due to fragmentation.

*(Note: Advanced modern C++ features like `std::vector` and `std::string` heavily use the Heap under the hood. This is why you must be extremely careful when using the Standard Template Library (STL) in bare-metal embedded systems).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
