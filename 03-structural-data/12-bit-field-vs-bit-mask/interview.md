# Interview Questions: Bit-Field vs Bit-Mask

## 1. Why are Bit-Masks preferred over Bit-Fields for cross-platform network code?
**Answer:** Bit-Fields are non-portable because the C/C++ standard leaves the bit-packing order (MSB vs LSB first) up to the compiler implementation. If two different processors with different compilers communicate using a Bit-Field struct, the data will likely be scrambled. Bit-Masks use pure mathematics (`shift` and `bitwise AND/OR`) which are guaranteed to produce the exact same logical result regardless of how the underlying architecture stores the bytes.

## 2. Explain the difference between logical AND (`&&`) and bitwise AND (`&`).
**Answer:** 
- Logical AND (`&&`) evaluates the overall "truthiness" of two expressions. E.g., `(5 && 2)` is `true && true`, which equals `1` (true).
- Bitwise AND (`&`) performs an independent AND operation on *each individual bit* of the two numbers. E.g., `(5 & 2)` is `0101 & 0010`, which equals `0000` (`0`).

## 3. How do you clear a specific bit using bitwise operators?
**Answer:** You use a bitwise AND combined with a bitwise NOT. To clear bit N: `Register &= ~(1 << N);`. The `(1 << N)` creates a mask with only bit N set to 1. The NOT (`~`) flips the mask so *only* bit N is 0, and all other bits are 1. The AND (`&`) operation then preserves all bits that are 1 in the mask, and clears bit N because it evaluates `X & 0`, which is always 0.
