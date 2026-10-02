# Interview Questions: Memory Alignment

## 1. What does it mean for a 32-bit integer to be "Naturally Aligned" in memory?
**Answer:** Natural alignment means the variable's memory address is an integer multiple of its size in bytes. For a 32-bit (4-byte) integer, its memory address must be perfectly divisible by 4 (e.g., ending in `0x0`, `0x4`, `0x8`, or `0xC`). This guarantees the CPU can read the entire integer from memory in a single, efficient hardware transaction.

## 2. On a strict architecture like an ARM Cortex-M0, what happens if you attempt an unaligned memory read (e.g., reading a `uint32_t` from address `0x20000001`)?
**Answer:** The hardware's bus matrix cannot process the request because it spans across two separate 32-bit physical memory chunks. The CPU detects this illegal operation and immediately throws a "Hard Fault" or "Usage Fault" hardware exception, which permanently halts the execution of the program.

## 3. How do you safely parse a 32-bit integer from an unaligned byte array (like a network packet) without triggering a Hard Fault?
**Answer:** You must never cast an unaligned byte pointer to a 32-bit pointer. Instead, you should use the standard C library function `std::memcpy(&dest, &unaligned_src, 4);`, or manually reconstruct the integer using bit-shifts (`(buf[0] << 24) | (buf[1] << 16)...`). Modern compilers recognize both of these patterns and will optimize them into safe, efficient assembly instructions that don't violate the hardware's alignment rules.
