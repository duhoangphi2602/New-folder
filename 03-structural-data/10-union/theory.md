# Union

## 1. Concept
In a `struct`, every member has its own distinct, non-overlapping memory location. The size of the struct is the sum of all members (plus padding).
In a `union`, all members overlap and start at the exact same memory address. The size of the union is exactly equal to its **largest single member**. 

## 2. Why
Because all members share the same memory, writing to one member permanently overwrites whatever data was stored by another member. 
This is useful for:
1. **Saving RAM**: Representing a mutually exclusive state (e.g., "I am either holding an integer OR a float, never both at once").
2. **Type Punning**: Reinterpreting the exact same binary bits as a different data type.

## 3. Syntax (Declaration)

```cpp
union Payload {
    uint32_t raw_data; // 4 bytes
    float    temp;     // 4 bytes
    uint8_t  bytes[4]; // 4 bytes
};
// sizeof(Payload) is 4 bytes, not 12 bytes!
```

## 4. Example
*(See `examples/` for runnable code demonstrating type punning and memory sharing).*

## 5. Embedded usage (Hardware Abstraction & Punning)

### 1. Hardware Registers (Bit / Word access)
Vendors often use unions to let you access a hardware register either as a single 32-bit word, or as individual 16-bit halves.
```c
union TimerRegister {
    uint32_t WORD;      // Access the whole 32-bit register
    struct {
        uint16_t LOW;   // Access lower 16 bits
        uint16_t HIGH;  // Access upper 16 bits
    } HALVES;
};
```

### 2. Type Punning (Network / UART)
When you receive 4 raw bytes over UART, how do you turn them into a `float`? You can write them into the `byte` array of a union, and then read out the `float` member!
```cpp
union FloatConverter {
    float f;
    uint8_t bytes[4];
};

FloatConverter conv;
// Receive 4 bytes from UART
conv.bytes[0] = 0x41; 
conv.bytes[1] = 0xC8; 
conv.bytes[2] = 0x00; 
conv.bytes[3] = 0x00; 

// Read the EXACT SAME memory bits as a float
float result = conv.f; // 25.0f
```

## 6. Trade-offs (Undefined Behavior in C++)
While Type Punning via unions is perfectly legal and standard in C, it is technically **Undefined Behavior (UB)** in C++! In C++, you are only allowed to read from the union member that was most recently written to.
Modern C++ compilers *usually* allow union punning as a compiler extension, but the strictly standard way to convert bytes to a float in C++ is to use `std::memcpy` or C++20's `std::bit_cast`.

```cpp
// The Modern C++ Safe Way (Zero overhead, compiler optimizes it perfectly)
uint8_t bytes[4] = {0x41, 0xC8, 0x00, 0x00};
float result;
std::memcpy(&result, bytes, 4); 
```

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
