# Static Allocation

## 1. Concept
Static Allocation means that the size of all memory buffers is known exactly at **Compile-Time**. 
The memory is placed in the `.data` or `.bss` section (for global/static variables) or on the Stack (for local variables). Because the linker calculates the exact byte layout, there is no need for a memory manager like `malloc` or `new` at runtime.

## 2. Why
- **Zero Latency:** Acquiring the memory takes 0 CPU cycles at runtime. It's already there.
- **Determinism:** You never suffer from "Out of Memory" errors at runtime. If your array is too big, the compiler will refuse to build the binary, failing loudly and safely on your PC.
- **No Fragmentation:** Because memory is never freed and reallocated, the memory layout never degrades over time.

## 3. Syntax (C++ Compile-Time Sizing)
In C++, we use `std::array` combined with templates to build robust, statically allocated systems.

```cpp
#include <array>
#include <cstdint>

// A statically allocated buffer holding exactly 1024 bytes.
// Lives in the .bss section.
std::array<uint8_t, 1024> global_rx_buffer; 

// A class that statically allocates its own storage via Templates
template <size_t MaxItems>
class SensorQueue {
    std::array<int, MaxItems> data;
    size_t count = 0;
public:
    bool push(int val) {
        if (count >= MaxItems) return false; // Buffer Full!
        data[count++] = val;
        return true;
    }
};

// Create a queue for exactly 50 items.
SensorQueue<50> my_queue;
```

## 4. Example
*(See `examples/` for a demonstration of compile-time buffer management).*

## 5. Embedded usage (The "Max Capacity" Design)
The main drawback of Static Allocation is that you must design for the **Worst-Case Scenario**.
If your device usually processes 100-byte packets, but occasionally receives a 2,000-byte packet, you *must* allocate a 2,000-byte `std::array`. For the 99% of the time you are processing 100-byte packets, 1,900 bytes of precious SRAM are sitting empty and wasted. 

## 6. Trade-offs
- **Pros:** 100% deterministic, zero runtime overhead, mathematically provable memory safety.
- **Cons:** Wastes RAM. You cannot easily adapt to unpredictable workloads (like accepting 10 simultaneous network connections when you only statically allocated space for 5).

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
