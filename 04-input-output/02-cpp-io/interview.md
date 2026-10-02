# Interview Questions: C++ Standard I/O

## 1. Why do almost all bare-metal embedded C++ projects ban the use of `<iostream>` and `std::cout`?
**Answer:** The primary reason is ROM Bloat. The `<iostream>` library is massively complex; it pulls in locale parsing, dynamic memory allocation, and exception handling. A simple "Hello World" using `std::cout` can result in a binary size of over 100KB, which instantly overflows the flash memory of smaller Cortex-M microcontrollers. `printf` (via lightweight libraries like Newlib-nano) achieves the same goal using only ~5KB of memory.

## 2. What is the fundamental advantage of `std::cout` over `printf`?
**Answer:** Perfect Type Safety. With `printf`, if you accidentally format a `float` using `%d`, the compiler cannot always protect you, leading to runtime garbage or crashes. `std::cout` relies on C++ function overloading (specifically `operator<<`). The compiler perfectly matches the variable type to the correct overload at compile time, making format mismatch bugs impossible.

## 3. Why is it dangerous to use `std::endl` inside a fast loop?
**Answer:** `std::endl` is not just a newline character; it explicitly calls `.flush()` on the underlying stream. Flushing forces the OS (or the embedded UART driver) to halt execution, clear the transmit buffer, and physically write the data to the hardware. Doing this thousands of times a second inside a fast loop creates severe I/O bottlenecks and will dramatically slow down the entire system. You should use `\n` to allow the underlying driver to buffer and transmit data efficiently in large chunks.
