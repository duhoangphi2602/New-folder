# Arrays

## 1. Concept
An array is a collection of variables of the **same type** stored in **contiguous** (adjacent) memory locations. The size of a C-style array must be known at compile time.

## 2. Why
Without arrays, storing 100 sensor readings would require declaring 100 individual variables (`sensor_1`, `sensor_2`, etc.). Arrays allow you to store and iterate over large datasets efficiently using a single variable name and an index.

## 3. Syntax (Declaration and Initialization)

```cpp
// 1. Uninitialized array (contains garbage data!)
uint32_t buffer[5]; 

// 2. Initialized array
uint32_t scores[3] = {10, 20, 30};

// 3. Zero-initialized array (all 100 elements are 0)
uint32_t zeros[100] = {0};

// 4. Auto-sized array (compiler infers size is 4)
uint32_t pins[] = {2, 4, 6, 8};
```

## 4. Example
*(See `examples/` for runnable code demonstrating array memory layout).*

### Memory Layout
If `uint32_t scores[3]` is stored at address `0x1000`, the layout is:
```text
scores[0] -> 0x1000 (4 bytes)
scores[1] -> 0x1004 (4 bytes)
scores[2] -> 0x1008 (4 bytes)
```

## 5. Embedded usage (Hardware Buffers)
In embedded programming, you frequently define global arrays in `.bss` to act as receive buffers for communication peripherals.

```cpp
// A 256-byte buffer to hold incoming UART data
uint8_t uart_rx_buffer[256] = {0}; 
```
When configuring the DMA (Direct Memory Access) controller, you tell the hardware exactly where this array starts in RAM, and the hardware writes incoming bytes directly into this contiguous block of memory without CPU intervention.

## 6. Trade-offs (C-style array vs `std::array`)

| Feature | C-style Array `int arr[5]` | `std::array<int, 5>` (C++11) |
|---------|----------------------------|------------------------------|
| **Memory Overhead** | 0 bytes | 0 bytes |
| **Knows its own size?** | No (decays to pointer) | Yes (`arr.size()`) |
| **Bounds checking?** | No | Optional (`arr.at()`) |
| **Assignment** | Cannot do `arr1 = arr2` | Can do `arr1 = arr2` |

*Note: In modern C++, always prefer `std::array`. However, you must understand C-style arrays because most vendor HALs (Hardware Abstraction Layers) are written in C and require them.*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
