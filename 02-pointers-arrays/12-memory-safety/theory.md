# Memory Safety

## 1. Concept
Memory safety is the prevention of software bugs related to memory access. Because C and C++ do not have a "Garbage Collector" or automatic bounds-checking like Java or Python, they are inherently **memory-unsafe** languages. 

## 2. Why
On a desktop PC, if your program accesses invalid memory, the OS Memory Management Unit (MMU) detects it, kills your program (Segmentation Fault), and cleans up the mess. 
On a bare-metal microcontroller, there is often no MMU. If you write past the end of an array, you might overwrite the RTOS Task Control Block, causing the scheduler to crash the entire system.

## 3. Syntax (The Four Horsemen of C++ Bugs)

1. **Buffer Overflow**: Writing past the end of an array.
2. **Dangling Pointer**: Using a pointer to memory that has been popped off the stack or freed.
3. **Null Pointer Dereference**: Using a pointer before assigning it a valid address.
4. **Uninitialized Memory**: Reading a variable before writing to it (reading garbage).

## 4. Example
*(See `examples/` for runnable code demonstrating defensive C++17 alternatives).*

## 5. Embedded usage (Defensive Programming in C++17)

To survive in embedded C++, you must adopt strict, defensive habits:

### 1. Avoid Raw Arrays
```cpp
// BAD: Silently corrupts memory
uint8_t buf[10];
buf[10] = 5; 

// GOOD: C++17 std::array
std::array<uint8_t, 10> buf;
buf.at(10) = 5; // Throws an exception or calls std::terminate, failing safely.
```

### 2. Universal Initialization
Never leave a variable uninitialized.
```cpp
// BAD
int* ptr;
uint32_t count;

// GOOD: Brace initialization ensures 0 / nullptr
int* ptr{}; 
uint32_t count{};
```

### 3. Span instead of Pointer+Length
In C++20 (and often polyfilled in C++17 embedded codebases), `std::span` replaces passing `(uint8_t* buf, size_t len)` to functions, ensuring the pointer and length are never mismatched.

### 4. Banish `new`/`malloc`
In high-reliability embedded systems (like automotive ISO 26262), dynamic memory allocation is outright banned after the startup sequence. Pre-allocate everything statically (`.bss` / `.data`).

## 6. Trade-offs

| Safety Feature | Pros | Cons |
|----------------|------|------|
| **`std::array::at()`** | Prevents buffer overflows completely. | Small performance overhead for the bounds check. |
| **Static Allocation** | No memory leaks. No fragmentation. Highly deterministic. | High peak RAM usage. Inflexible compared to `malloc`. |
| **Smart Pointers** | Automatically calls `delete` to prevent leaks. | Unnecessary if you ban dynamic allocation entirely. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice hunting memory bugs.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
