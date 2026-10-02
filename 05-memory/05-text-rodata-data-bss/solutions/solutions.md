# Solutions: Memory Segments

## Solution 1: Categorization
**Answer:**
1. `max_retries`: **`.rodata`** (It is a global constant).
2. `current_retries`: **`.data`** (It is a global variable initialized to a non-zero value, `3`).
3. `network_buffer`: **`.bss`** (It is a global uninitialized array).
4. `error_code`: **`Stack`** (It is a local variable inside a function. It does NOT go into `.bss` despite being initialized to 0, because it only exists while `reset_network()` is running).

## Solution 2: Firmware Size Optimization
**Answer:**
1. **Flash Check:** Will it flash? **NO**.
   Total Flash required = `.text` (30,000) + `.data` (3,000) = **33,000 bytes**.
   Your microcontroller only has 32KB (32,768 bytes) of Flash. The linker will throw a "Flash Overflow" error.
2. **RAM Check:** Will it run? **NO**.
   Total RAM required = `.data` (3,000) + `.bss` (6,000) = **9,000 bytes**.
   Your microcontroller only has 8KB (8,192 bytes) of RAM. The linker will throw a "RAM Overflow" error.
