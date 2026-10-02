# The Memory Map

## 1. Concept
A 32-bit CPU has a 32-bit Address Bus. This means it can generate memory addresses from `0x00000000` to `0xFFFFFFFF` (4 Gigabytes total). 
The **Memory Map** is a table in the microcontroller's datasheet that tells you exactly what hardware is wired to which addresses.

## 2. Why
The CPU doesn't know what "RAM" or "UART" is. It only knows how to read and write to 32-bit numbers (addresses). The Memory Map bridges the software (addresses) to the hardware (physical silicon blocks).

## 3. The Standard ARM Cortex-M Memory Map
ARM designed a standardized memory map that almost all vendors (ST, NXP, Texas Instruments) follow.

| Address Range | Size | Name | Purpose |
|---------------|------|------|---------|
| `0x00000000` - `0x1FFFFFFF` | 0.5 GB | **Code / Flash** | Contains your `.text` and `.rodata`. Executed via the fast I-Code bus. |
| `0x20000000` - `0x3FFFFFFF` | 0.5 GB | **SRAM (RAM)** | Contains your `.data`, `.bss`, Stack, and Heap. |
| `0x40000000` - `0x5FFFFFFF` | 0.5 GB | **Peripherals** | Memory-Mapped Registers (GPIO, UART, SPI, Timers). |
| `0x60000000` - `0x9FFFFFFF` | 1.0 GB | **External RAM** | For connecting external SDRAM chips. |
| `0xE0000000` - `0xFFFFFFFF` | 0.5 GB | **Cortex Internal** | Special registers inside the CPU core itself (NVIC, SysTick, Debug). |

## 4. Example
*(See `examples/` for a simulated inspection of memory mapped boundaries).*

## 5. Embedded usage (Datasheet Navigation)
When writing a bare-metal UART driver, you must consult the vendor's datasheet.
1. Look at the Memory Map: You find "UART1" is located in the Peripheral region at `0x40011000`.
2. You create a pointer to that exact address in C++.
3. When you write `*uart_ptr = 'A';`, the CPU places `0x40011000` on the Address Bus and `'A'` on the Data Bus. 
4. The silicon's internal bus matrix recognizes `0x40` as a Peripheral, routes the data to the UART silicon block, and the UART transmits the character.

## 6. Trade-offs (Bus Matrix Bottlenecks)
Why separate Flash and RAM into different regions? **Performance.**
The ARM Cortex-M architecture uses a "Bus Matrix". The CPU has an `I-Bus` (Instruction Bus) wired to the `0x00` region, and a `D-Bus` (Data Bus) wired to the `0x20` region. 
This means the CPU can fetch the next machine-code instruction from Flash *at the exact same time* it is reading a variable from RAM. If everything was stuffed into the same region on the same bus, the CPU would have to wait, halving its processing speed.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
