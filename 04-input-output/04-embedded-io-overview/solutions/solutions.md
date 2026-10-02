# Solutions: Embedded I/O Overview

## Solution 1: Finding the Standard
**Answer:** It goes **nowhere**. By default, on a bare-metal microcontroller without an OS, the standard library has no underlying driver for `stdout`. If you call `printf`, the C library might execute the formatting logic, but when it attempts to flush the buffer to the hardware, it hits a weak, empty function (often named `_write`). The data is simply discarded into the void. The developer is entirely responsible for implementing the `_write` function to route the data to a specific hardware peripheral (like UART).

## Solution 2: Communication Protocols
**Answer:**
1. **I2C**: It requires only 2 wires (SDA and SCL) and allows multiple slow sensors to share the exact same bus, making it perfect for minimizing wire count.
2. **UART**: It is the universal standard for asynchronous, human-readable console debugging. Every PC can read UART data via a USB-to-Serial converter.
3. **SPI**: It is a high-speed, synchronous protocol capable of megabit speeds, designed specifically for heavy data transfer like SD cards and LCD screens.
