# std::array (C++11)

## 1. Concept
`std::array` is a fixed-size container that encapsulates a raw C-style array. Because it is implemented as a `struct` containing an array, it behaves like a standard object rather than a raw pointer.

## 2. Why
Raw C arrays are dangerous:
- They don't know their own size (you must pass size separately).
- They silently decay into pointers, losing size information.
- They have no built-in bounds checking.
- They cannot be easily copied using the `=` operator.

`std::array` solves all of these issues while maintaining **zero runtime overhead**.

## 3. Syntax (Declaration and Access)

```cpp
#include <array>

// std::array<Type, Size>
std::array<int, 5> data = {1, 2, 3, 4, 5};

// 1. Knows its own size
size_t len = data.size(); // 5

// 2. Unchecked access (Fast, C-style, unsafe if out of bounds)
int val = data[0]; 

// 3. Checked access (Safe, throws exception if out of bounds)
int val2 = data.at(4); 
```

## 4. Example
*(See `examples/` for runnable code demonstrating safe buffer passing).*

## 5. Embedded usage (Hardware Buffers)
In embedded systems, you use `std::array` to define global or class-level receive/transmit buffers.

```cpp
#include <array>
#include <cstdint>

class UartReceiver {
public:
    void receive_byte(uint8_t byte) {
        if (rx_index_ < rx_buffer_.size()) {
            rx_buffer_[rx_index_++] = byte;
        }
    }
    
    // Pass to legacy C API
    void send_to_dma() {
        // .data() gets the underlying raw pointer
        start_dma(rx_buffer_.data(), rx_buffer_.size());
    }

private:
    std::array<uint8_t, 64> rx_buffer_{}; // Zero-initialized!
    size_t rx_index_ = 0;
};
```

## 6. Trade-offs (C Array vs std::array)

| Feature | C-style `int arr[5]` | C++11 `std::array<int, 5>` |
|---------|----------------------|----------------------------|
| **Memory/CPU Overhead** | Zero | **Zero** |
| **Decays to pointer?** | Yes | No |
| **Can be copied? (`a = b`)** | No | Yes |
| **Bounds checking?** | None | Optional (`.at()`) |

**Rule of Thumb in Modern C++:** Always use `std::array`. There is literally no technical reason to use a C-style array in modern C++ unless you are forced by an external C macro.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
