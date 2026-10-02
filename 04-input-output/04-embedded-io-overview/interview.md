# Interview Questions: Embedded I/O Overview

## 1. What is "Bit-Banging"?
**Answer:** Bit-banging is the process of manually toggling a general-purpose I/O (GPIO) pin high and low in software to simulate a serial communication protocol (like UART or I2C) rather than using the dedicated silicon hardware peripheral. While it is highly flexible, it is heavily frowned upon because it burns massive amounts of CPU cycles and is highly vulnerable to timing inaccuracies caused by interrupts.

## 2. On a bare-metal microcontroller, what happens under the hood when you call `printf("Hello\n");`?
**Answer:** The standard C library (like Newlib) parses the format string and places the ASCII characters 'H','e','l','l','o','\n' into a RAM buffer. When the flush is triggered (by the `\n`), the library calls a low-level system hook, typically named `_write()` (or `fputc()`). If the developer has not implemented `_write()`, the data is discarded. If implemented, `_write()` iterates through the characters and writes them sequentially into the hardware Memory-Mapped Data Register of a peripheral like UART, which then physically pulses the TX pin to transmit the bits.

## 3. Why does UART not require a clock line, whereas SPI and I2C do?
**Answer:** UART is *Asynchronous*, meaning the transmitter and receiver do not share a common clock signal to synchronize the reading of bits. Instead, both devices must be manually configured in software to operate at the exact same speed (Baud Rate, e.g., 115200 bits per second). SPI and I2C are *Synchronous*; the master device generates a physical clock wave on a dedicated wire (SCL/SCK), and bits are read exactly on the rising or falling edge of that physical clock wave, guaranteeing perfect synchronization regardless of speed.
