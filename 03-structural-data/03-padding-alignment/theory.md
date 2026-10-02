# Struct Padding and Alignment

## 1. Concept
To satisfy the CPU's memory alignment requirements, compilers secretly insert **Padding Bytes** (dead, unused memory) between struct members. The total size of the struct is also padded at the very end so that if you create an array of these structs, every single struct in the array is perfectly aligned.

## 2. Why
A 32-bit CPU (like ARM Cortex-M4) reads memory fastest when reading 4 bytes at an address divisible by 4. If a struct starts with a 1-byte `char`, and is followed by a 4-byte `int`, placing the `int` immediately after the `char` (at offset 1) would cause an unaligned memory access. The compiler avoids this by injecting 3 bytes of padding.

## 3. Syntax (The Hidden Padding)

```cpp
struct Sensor {
    uint8_t  id;    // 1 byte. (Alignment requirement: 1)
                    // [3 BYTES PADDING INJECTED HERE]
    uint32_t value; // 4 bytes. (Alignment requirement: 4)
};
```
Even though the data only takes `1 + 4 = 5` bytes, `sizeof(Sensor)` will return **8**.

## 4. Example
*(See `examples/` for runnable code demonstrating manual packing vs compiler packing).*

## 5. Embedded usage (Packing and Optimization)

### 1. Manual Reordering (RAM Optimization)
You can usually eliminate internal padding simply by sorting your struct members from largest to smallest.

```cpp
// BAD: 12 Bytes Total (4 bytes wasted)
struct BadLayout {
    uint8_t a;  // 1 byte + 3 bytes padding
    uint32_t b; // 4 bytes
    uint8_t c;  // 1 byte + 3 bytes end-padding
};

// GOOD: 8 Bytes Total (2 bytes wasted at end, but optimal)
struct GoodLayout {
    uint32_t b; // 4 bytes
    uint8_t a;  // 1 byte
    uint8_t c;  // 1 byte + 2 bytes end-padding
};
```

### 2. `__attribute__((packed))` (Network/Protocol Buffers)
When sending a struct over UART, SPI, or Ethernet, you *cannot* have padding. The receiver expects the exact sequence of bytes. You must force the compiler to remove all padding using the `packed` attribute.

```cpp
// GCC/Clang syntax for ARM and desktop
struct __attribute__((packed)) Packet {
    uint8_t  id;    // 1 byte
    uint32_t value; // 4 bytes. Forced to offset 1!
};
```
Now, `sizeof(Packet)` is exactly **5**.

## 6. Trade-offs (Packed Structs)

| Feature | Unpacked (Default) | Packed (`__attribute__((packed))`) |
|---------|--------------------|------------------------------------|
| **RAM Usage** | Higher (Wastes memory on padding) | Minimal (Exactly the size of data) |
| **CPU Performance** | Fastest (Natural hardware alignment) | Slower (Compiler must generate extra assembly instructions to read unaligned data safely) |
| **Hardware Faults** | Safe | Safe (Compiler handles it) OR **Crash** (If you cast a pointer into the packed struct directly without letting the compiler know it's unaligned). |

**Rule of Thumb:** Never pack a struct unless it is strictly required for serialization (saving to Flash, sending over Network/UART).

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
