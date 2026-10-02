# Struct Memory Layout

## 1. Concept
In C and C++, the members of a `struct` are guaranteed to be allocated in memory in the **exact sequential order** that they are declared in the code. The first member is placed at the lowest memory address, the second member follows it, and so on.

## 2. Why
This strict ordering guarantee is what makes C/C++ suitable for systems programming. If you declare a struct representing a network packet header (e.g., Destination MAC, Source MAC, EtherType), you can overlay that struct directly onto a raw byte buffer received from an Ethernet controller. 

## 3. Syntax (Sequential Ordering)

```cpp
struct SensorData {
    uint32_t timestamp; // Address 0x1000
    uint16_t humidity;  // Address 0x1004
    uint16_t temp;      // Address 0x1006
}; 
```
The compiler guarantees that `&timestamp < &humidity < &temp`. 

## 4. Example
*(See `examples/` for runnable code demonstrating address printing of struct members).*

## 5. Embedded usage (Hardware Overlay)
Because the order is guaranteed, embedded developers map entire blocks of hardware registers using a single struct.

```cpp
// Mapping the STM32 UART Peripheral
struct USART_RegDef_t {
    volatile uint32_t SR;   // Status Register      (Offset 0x00)
    volatile uint32_t DR;   // Data Register        (Offset 0x04)
    volatile uint32_t BRR;  // Baud Rate Register   (Offset 0x08)
    volatile uint32_t CR1;  // Control Register 1   (Offset 0x0C)
};

// Map the struct to the base address of UART1
auto* const UART1 = reinterpret_cast<USART_RegDef_t*>(0x40011000);

// We can now access registers cleanly:
UART1->DR = 'A'; // Writes to 0x40011004
```

## 6. Trade-offs (The Hidden Padding)
While the *order* of members is strictly guaranteed, the *distance* between them is not!
Because of **Memory Alignment** rules (discussed in `02-pointers-arrays/13-alignment`), a CPU prefers to read 4-byte variables from addresses divisible by 4. If a 1-byte variable is followed by a 4-byte variable, the compiler will secretly inject 3 bytes of "padding" (dead space) in between them so the 4-byte variable aligns properly.

```cpp
struct BadLayout {
    uint8_t  a; // 1 byte
    // 3 bytes of INVISIBLE PADDING injected here!
    uint32_t b; // 4 bytes
};
// sizeof(BadLayout) is 8, not 5!
```
*(The strategies to fix this are discussed in the next topic: `03-padding-alignment`).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
