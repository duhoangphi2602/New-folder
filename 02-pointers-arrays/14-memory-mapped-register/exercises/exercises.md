# Exercises: Memory-Mapped Registers

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: C-Style Macro Definition
You are writing a bare-metal driver in C. The datasheet states that the SPI1 Control Register 1 (CR1) is a 32-bit register located at physical address `0x40013000`.

**Task:** Write a C-style `#define` macro named `SPI1_CR1` that allows you to directly read and write to this address. Ensure you use the correct keywords to prevent compiler optimization.

## Exercise 2: C++17 Type-Safe Pointer
You are writing a modern C++ driver. The UART2 Data Register (DR) is located at `0x40004404`. It is 32 bits wide, but only the lowest 8 bits are used for data transmission.

**Task:** Write a C++17 compliant pointer definition for this register. It should be a `const` pointer pointing to `volatile` data, utilizing `reinterpret_cast`.

## Exercise 3: Bug Hunt
The following code attempts to poll a hardware status register located at `0x50000018` to wait until a transmission is complete (indicated by bit 7 going HIGH).

```cpp
void wait_for_tx() {
    uint32_t* status_reg = (uint32_t*)0x50000018;
    
    // Wait until bit 7 is set (1 << 7 = 0x80)
    while ((*status_reg & 0x80) == 0) {
        // Do nothing, just wait
    }
}
```

**Task:** There is a fatal flaw in this code that will cause the system to freeze in Release mode (but it might accidentally work in Debug mode). Identify the bug and write the corrected code.
