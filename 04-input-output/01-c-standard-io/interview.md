# Interview Questions: C Standard I/O

## 1. Why is `printf` heavily preferred over `std::cout` in bare-metal embedded systems?
**Answer:** `std::cout` is part of the massive C++ `<iostream>` library. Pulling in `<iostream>` brings in deep inheritance hierarchies, locale support, exception handling, and heavy static initialization code, often bloating the binary by 50KB to 150KB. On microcontrollers with 32KB to 128KB of total flash memory, this is catastrophic. `printf` (especially highly optimized, minimal implementations like `nano_printf`) requires only a few kilobytes of Flash.

## 2. In many embedded compiler configurations, why does printing a `float` using `printf("%f")` fail or print garbage?
**Answer:** Because compiling the float-to-string conversion logic is very heavy (consuming up to 20KB of ROM). Standard embedded library configurations (like Newlib-nano used in ARM GCC) explicitly disable float support in `printf` by default to save space. To use it, developers must manually pass a linker flag (e.g., `-u _printf_float`) during compilation, or use integer-math workarounds.

## 3. Why is `scanf` considered dangerous for parsing network or serial input?
**Answer:** `scanf` is rigid and extremely fragile. If the incoming data format slightly deviates from the format string, `scanf` can permanently stall or leave the input buffer in a corrupted state. Furthermore, using `%s` with `scanf` is a classic buffer overflow vulnerability because it does not limit the number of characters it writes to memory unless explicitly specified (like `%10s`). Professional parsing requires reading a stream character-by-character into a bounded buffer and evaluating it via a state machine.
