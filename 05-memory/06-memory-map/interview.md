# Interview Questions: The Memory Map

## 1. What does it mean for a microcontroller to have a "Flat Address Space"?
**Answer:** It means all memory technologies (SRAM, Flash, external SDRAM) and all hardware peripherals (UART, GPIO, Timers) are accessed using a single, unified 32-bit address system. The CPU does not use special "I/O Instructions" to talk to a UART; it simply writes to a specific memory address (e.g., `0x40011000`). The hardware bus matrix decodes the address and routes the data to the correct physical silicon block.

## 2. In the ARM Cortex-M architecture, what is located in the `0xE0000000` region, and why is it separated from the standard `0x40000000` peripheral region?
**Answer:** The `0xE0000000` region is reserved for the Private Peripheral Bus (PPB). It contains registers that are internal to the ARM Cortex-M CPU core itself (like the NVIC Interrupt Controller, the SysTick timer, and the SWD debugging interface). It is separated from standard peripherals (like UART or I2C) because standard peripherals are designed by the chip vendor (e.g., STMicroelectronics), while the CPU core and the PPB are designed exclusively by ARM. This guarantees that standard CPU functions exist at the exact same addresses on every single Cortex-M chip, regardless of the manufacturer.

## 3. If a 32-bit address space supports 4 Gigabytes of memory, but a microcontroller only has 64 Kilobytes of RAM, what happens if you try to read an address in the "empty" space between RAM and Peripherals?
**Answer:** The address is considered "unmapped" or "reserved". If the CPU attempts to place that address on the memory bus, the hardware bus matrix will realize that no physical memory chip or peripheral is listening at that address. The bus matrix will return an "error response" to the CPU, which instantly triggers a Bus Fault or Hard Fault hardware exception, crashing the program.
