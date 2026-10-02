# Dangling Pointer

## 1. Concept
A **dangling pointer** is a pointer that points to a memory location that has been freed, deallocated, or has gone out of scope. The pointer still holds the raw address, but the system has reclaimed that memory for other uses.

## 2. Why
If you try to read from a dangling pointer, you will read garbage data (whatever happened to overwrite that memory). If you try to write to a dangling pointer, you will silently corrupt memory that now belongs to another part of your program.

## 3. Syntax (Common Causes)

### Cause 1: Returning Local Variable Addresses
Local variables live on the Stack. When a function returns, its stack frame is destroyed and the memory is reused by the next function call.
```cpp
int* get_sensor_value() {
    int local_val = 42;
    return &local_val; // BUG! Returns address of temporary stack memory
}
```

### Cause 2: Use-After-Free (Heap)
When memory is freed, the pointer variable itself is not automatically deleted. It still points to the freed address.
```cpp
int* ptr = new int(10);
delete ptr; // Memory is returned to the OS/Heap
// ptr is now dangling

*ptr = 20;  // BUG! Memory corruption (Use-After-Free)
```

### Cause 3: Out of Scope
```cpp
int* ptr = nullptr;
{
    int temp = 100;
    ptr = &temp;
} // temp goes out of scope and is destroyed

// ptr is now dangling
```

## 4. Example
*(See `examples/` for runnable code demonstrating the devastating effects of stack-based dangling pointers).*

## 5. Embedded usage (Mitigations)
In bare-metal firmware, you usually avoid `malloc`/`free` or `new`/`delete` entirely, which eliminates "Use-After-Free" bugs. However, Stack-based dangling pointers are still a massive threat, especially in RTOS environments.

**Mitigation Strategies:**
1. **Never return local addresses**: If a function needs to populate a buffer, the caller should pass a pointer *in*, rather than the function returning a pointer *out*.
2. **Nullify after free**: If you must use dynamic memory, set the pointer to `nullptr` immediately after freeing it.
    ```cpp
    delete ptr;
    ptr = nullptr;
    ```
3. **Static Allocation**: Use global variables or `static` local variables for buffers that need to persist across function calls. `static` variables live in `.bss` or `.data`, not on the stack.

## 6. Trade-offs (Modern C++ vs Legacy C)

| Language | Dangling Pointer Protection |
|----------|-----------------------------|
| **C** | None. Completely relies on developer discipline. |
| **C++11/14** | High. Introduces `std::unique_ptr` and `std::shared_ptr` to manage lifetimes automatically. |
| **C++ (References)** | Still vulnerable! A reference can dangle if it binds to a destroyed local variable. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice identifying dangling pointers.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
