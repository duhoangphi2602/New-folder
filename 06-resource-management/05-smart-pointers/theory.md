# Smart Pointers

## 1. Concept
A Smart Pointer is an RAII wrapper around a raw pointer. 
Instead of writing `int* ptr = new int(5);`, you create a `std::unique_ptr` object on the Stack. Its constructor calls `new`. When the function ends, its destructor automatically calls `delete`. You never write the word `delete` yourself.

## 2. Why
If you allocate memory and then your code throws an exception or hits an early `return` statement, any raw pointers will leak. A smart pointer's destructor is guaranteed to execute no matter how the function exits, making memory leaks mechanically impossible.

## 3. Syntax (`std::unique_ptr`)

```cpp
#include <memory>
#include <iostream>

void parse_packet() {
    // 1. Create a smart pointer using std::make_unique (C++14/17)
    // This safely allocates an array of 1024 bytes on the Heap.
    std::unique_ptr<uint8_t[]> buffer = std::make_unique<uint8_t[]>(1024);
    
    // 2. Use it exactly like a normal array pointer
    buffer[0] = 0xFF;
    
    if (buffer[0] != 0xFF) {
        return; // SAFE! The destructor of 'buffer' runs and calls delete[]!
    }
    
} // SAFE! The function ends, the destructor runs, memory is freed!
```

## 4. Example
*(See `examples/` for a runnable demonstration comparing raw pointers vs smart pointers).*

## 5. Embedded usage (Exclusive Ownership)
`std::unique_ptr` enforces **Exclusive Ownership**. This means exactly one object owns the memory. You cannot copy a `unique_ptr` (because if you copied it, both destructors would try to `delete` the same memory, causing a fatal "Double Free" crash). 

If you want to pass the memory to another function, you must either:
1. Pass a raw reference (`&`) or raw pointer (`*`) so the function can look at the data without owning it.
2. Use `std::move()` to permanently transfer ownership (we will cover Move Semantics in a later chapter, but it is the mechanism that powers `unique_ptr` transfers).

This strict ownership model forces developers to design clean, deterministic architectures where it is always obvious who is responsible for freeing the memory.

## 6. Trade-offs (`std::unique_ptr` vs `std::shared_ptr`)
C++ also offers `std::shared_ptr`, which allows multiple pointers to own the same memory. It keeps a "reference count", and only deletes the memory when the count reaches zero.
**In bare-metal embedded, `std::shared_ptr` is generally banned.**
- **Overhead:** It requires allocating a separate "control block" on the heap just to hold the reference count.
- **Thread Safety:** Updating the reference count requires atomic operations, which consume massive amounts of CPU cycles.
- **Determinism:** You lose control over *when* the memory is freed.
`std::unique_ptr` has **zero overhead**. It compiles down to the exact same raw pointer assembly instructions you would write by hand.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
