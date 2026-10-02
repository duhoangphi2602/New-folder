# Solutions: Class & Object Basics

## Solution 1: Struct vs Class
**Answer:**
- For `DataPacket` (a `struct`), accessing `id` and `print_id()` will **succeed**. The default access specifier for a `struct` is `public`.
- For `DataHandler` (a `class`), accessing them will cause a **compile error**. The default access specifier for a `class` is `private`, so `main()` is not allowed to see them.

## Solution 2: The `const` Correctness Bug
**Answer:** `print_buffer_info` takes a `const Buffer&`. This means the compiler is strictly forbidden from allowing any modifications to `buf`. However, `get_size()` is not marked as a `const` member function, meaning it *might* modify the object. The compiler refuses to call a non-const function on a const object.
**The Fix:** Mark the member function as `const`.
```cpp
int get_size() const { return size_; }
```

## Solution 3: Memory Footprint
**Answer:** 
- Both `UartC` and `UartCpp` consume the **exact same amount of RAM** (usually 8 bytes due to 4-byte alignment padding).
- **No**, member functions and constructors do **not** increase the RAM size of an object. 
- Member functions are compiled into machine code that lives in Flash memory (`.text` section). They are just standard functions that secretly take a pointer to the object (`this`) as their first parameter. Therefore, C++ classes are zero-overhead abstractions for data structures.
