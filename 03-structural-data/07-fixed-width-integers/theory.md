# Fixed-Width Integers (<cstdint>)

## 1. Concept
The C/C++ standard does not define the exact size of an `int`. It only guarantees that `short <= int <= long`. 
- On an 8-bit AVR (Arduino), an `int` is 16 bits.
- On a 32-bit ARM Cortex-M, an `int` is 32 bits.
- On a 64-bit Desktop, an `int` is typically 32 bits (but `long` changes).

To solve this portability nightmare, C99 introduced `<stdint.h>` (and C++11 introduced `<cstdint>`). This library defines types that guarantee exact bit widths across all compilers and architectures.

## 2. The Types

| Type | Bit Width | Signed/Unsigned | Typical Usage in Embedded |
| :--- | :--- | :--- | :--- |
| `uint8_t` | 8 bits (1 byte) | Unsigned | Raw byte buffers, UART data, SPI payloads, 8-bit registers. |
| `int8_t` | 8 bits | Signed | Small negative values (e.g., temperature sensors). |
| `uint16_t`| 16 bits (2 bytes) | Unsigned | 12-bit ADC readings, 16-bit timers. |
| `int16_t` | 16 bits | Signed | Gyroscope/Accelerometer raw readings. |
| `uint32_t`| 32 bits (4 bytes) | Unsigned | ARM Cortex-M hardware registers, memory addresses, timestamps. |
| `int32_t` | 32 bits | Signed | High-precision sensor calculations. |
| `uint64_t`| 64 bits (8 bytes) | Unsigned | Unix epoch timestamps, high-precision uptime counters. |

## 3. Why `int` is Banned (MISRA-C Standard)
The MISRA-C standard (used in Automotive and Aerospace) explicitly forbids the use of native types like `char`, `int`, `short`, and `long`. 
If you write `int counter = 0;`, the code might work perfectly on your 32-bit ARM chip. But if someone ports your code to a 16-bit MSP430, the `int` will overflow at 32,767 instead of 2.1 billion, causing catastrophic silent failures.

## 4. Syntax
```cpp
#include <cstdint> // C++ style
#include <stdint.h> // C style

void configure_hardware() {
    uint32_t baud_rate = 115200;
    uint8_t  tx_buffer[256];
    uint16_t adc_reading = 4095;
}
```

## 5. Example
*(See `examples/` for a demonstration of sizes across architectures).*

## 6. Trade-offs (Performance)
On a 32-bit ARM CPU, the native bus width is 32 bits. Reading a `uint8_t` from memory sometimes requires the CPU to load a full 32-bit word and then execute an extra instruction to mask out the top 24 bits. Therefore, `uint32_t` is actually the fastest and most efficient data type for math loops on a 32-bit CPU. `uint8_t` saves RAM, but costs slightly more CPU time.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
