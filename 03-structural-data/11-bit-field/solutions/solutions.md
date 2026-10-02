# Solutions: Bit-Fields

## Solution 1: Size Prediction
**Answer:** `sizeof(SensorFlags)` will return **8 bytes**.
**Explanation:** 
- The first three fields (`is_active` [1], `error_code` [4], `padding` [27]) add up to exactly 32 bits. The compiler packs these into the first 4-byte `uint32_t` block.
- The next field (`version` [8]) forces the compiler to allocate a *new* 32-bit block to hold it, because the first block is full.
- Therefore, the struct takes two 32-bit blocks (4 bytes + 4 bytes = 8 bytes).

## Solution 2: Truncation Bug
**Answer:** The value stored will be **0**.
**Explanation:** A 3-bit field can only store values from `0` to `7` (binary `000` to `111`). 
The number 8 in binary is `1000` (requires 4 bits). When assigning `8` to a 3-bit field, the compiler silently truncates the top bits. It only keeps the lowest 3 bits, which are `000`. Therefore, `cal->day_of_week` becomes `0`.

## Solution 3: MISRA C Violation
**Answer:** This violates MISRA C and best practices because the memory layout of bit-fields is **implementation-defined** (compiler-dependent). 
The C/C++ standard does not guarantee whether `clock_phase` (the first declared field) will be placed at the Least Significant Bit (Bit 0) or the Most Significant Bit (Bit 31) of the 32-bit register. 
If the code is compiled with a different compiler (or even moved from an ARM chip to an x86 simulation), the bits might map to the hardware backwards, causing a catastrophic failure. Hardware registers must be accessed using deterministic bitwise operations (masks and shifts), not bit-fields.
