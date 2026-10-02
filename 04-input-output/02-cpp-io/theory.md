# C++ Standard I/O (std::cout / std::cin)

## 1. Concept
The C++ `<iostream>` library models input and output as a "stream" of characters. You insert data into the stream using the `<<` operator (`std::cout << x;`) and extract data from the stream using the `>>` operator (`std::cin >> x;`).

## 2. Why
`printf` is notoriously unsafe. If you write `printf("%d", 3.14);`, the compiler might warn you, but the code will still run and print absolute garbage (or crash). `std::cout` automatically detects the data type of the variable and formats it correctly. It is impossible to have a format-specifier mismatch because there are no format specifiers!

## 3. Syntax (Stream Operators)

```cpp
#include <iostream>

int main() {
    int id = 42;
    float temp = 25.5f;

    // Type-safe printing! No %d or %f needed.
    std::cout << "Sensor ID: " << id << " Temp: " << temp << " C\n";
}
```
*Note: We use `\n` instead of `std::endl`. `std::endl` does two things: it prints a newline, AND it flushes the buffer (forces the hardware to transmit immediately). Flushing on every single line is brutally slow in both PC and embedded systems. Stick to `\n`!*

## 4. Example
*(See `examples/` for runnable code demonstrating basic C++ I/O).*

## 5. Embedded usage (The Bloat Problem)

In Embedded Linux (Raspberry Pi, BeagleBone), you use `std::cout` exactly like a PC.
In Bare-Metal Microcontrollers (STM32, ESP32, AVR), **`<iostream>` is practically banned.**

**Why?**
1. **ROM Bloat:** Including `<iostream>` pulls in massive templated formatting engines, locale processors (for different languages), and exception handling. It can add 150KB+ to your binary. Many microcontrollers only have 64KB of total storage!
2. **RAM Bloat:** `std::cout` allocates significant dynamic memory (heap) during startup for its internal buffers.
3. **Execution Time:** The static initialization of the stream objects happens *before* `main()` starts, dramatically slowing down boot time.

*The Solution:* Bare-metal C++ firmware heavily relies on lightweight C-style `printf` wrappers, or third-party libraries like `fmtlib` (which inspired C++20's `std::format`) that offer C++ type safety with the small footprint of C.

## 6. Trade-offs (Type Safety vs Resources)

| Feature | `printf` | `std::cout` |
|---------|----------|-------------|
| **Type Safety** | None (Relies on developer matching `%` flags) | **Perfect** (Compiler auto-deduces types) |
| **Custom Types**| Cannot print `struct` natively | Can easily overload `operator<<` for any `struct` |
| **ROM Footprint**| Tiny (~5KB with nano_printf) | **Massive** (~100KB to 150KB) |
| **Boot Speed**  | Instant | Slower (Static init overhead) |

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
