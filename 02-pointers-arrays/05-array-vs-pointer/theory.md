# Array vs Pointer (Decay)

## 1. Concept
An array is a fixed-size block of memory that knows its total length at compile time. A pointer is a variable that simply holds a memory address. 
However, in most expressions (like assigning an array to a pointer or passing an array to a function), the array name **decays** into a pointer to its first element.

## 2. Why
In C (which C++ inherits from), it is extremely inefficient to copy an entire array by value when passing it to a function. To optimize performance, the compiler silently converts the array into a lightweight pointer to the first element.

## 3. Syntax (The Decay)

```cpp
int arr[5] = {1, 2, 3, 4, 5};

// Decay: 'arr' silently becomes &arr[0]
int* ptr = arr; 

// Passing to a function triggers decay
void process(int my_array[5]); // 'my_array' is actually just int* my_array
```

## 4. Example
*(See `examples/` for runnable code demonstrating the `sizeof` trap).*

**The `sizeof` Trap:**
```cpp
void print_size(int my_array[5]) {
    // BUG! my_array has already decayed to a pointer.
    // sizeof(my_array) will return 4 or 8 (pointer size), NOT 20.
    std::cout << sizeof(my_array) << '\n'; 
}

int main() {
    int arr[5];
    std::cout << sizeof(arr) << '\n'; // 20 (Array size is known here)
    print_size(arr);
}
```

## 5. Embedded usage (Buffer Passing)
Because of array decay, if you write a hardware driver in C (e.g., a UART transmit function), you can **never** trust the array to know its own size. You must always pass the length explicitly as a second argument.

```c
// Standard C-style Embedded API
void uart_transmit(const uint8_t* buffer, size_t length) {
    for (size_t i = 0; i < length; i++) {
        uart_write_register(buffer[i]);
    }
}
```
In modern C++17, we avoid C-arrays and pointers when passing buffers. We use modern abstractions that carry their size with them and do not decay.

```cpp
// C++17 (using std::array)
void uart_transmit(const std::array<uint8_t, 64>& buffer) {
    // buffer knows its size: buffer.size()
}
```
*(Note: C++20 introduces `std::span`, which is the ultimate solution for this).*

## 6. Trade-offs

| Structure | Pros | Cons |
|-----------|------|------|
| **C-style Array** | Native, zero-overhead. Compatible with all C libraries and vendor HALs. | Suffers from array decay. Loses size information when passed. Prone to bugs. |
| **`std::array`** | Does not decay. `sizeof` and `.size()` work everywhere. Type-safe. | Fixed size at compile time. Harder to interface directly with legacy C HAL APIs (requires `.data()`). |

## 7. Exercises
Please proceed to the `exercises/` folder to debug an array decay issue.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
