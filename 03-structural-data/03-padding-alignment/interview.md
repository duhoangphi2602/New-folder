# Interview Questions: Struct Padding and Alignment

## 1. Why do compilers insert padding bytes into structs?
**Answer:** Compilers insert padding to ensure that every member of the struct starts at an address that satisfies the CPU's natural hardware alignment requirements (e.g., 4-byte integers must be on 4-byte boundaries). This prevents severe performance penalties on x86 processors and fatal Hard Faults on strict RISC processors like the ARM Cortex-M0.

## 2. How can you optimize a struct to consume the absolute minimum amount of RAM without using the `packed` attribute?
**Answer:** You manually reorder the members in the struct declaration, sorting them from largest data type to smallest data type (e.g., pointers/64-bit ints first, 32-bit ints next, 16-bit, then 8-bit). This naturally satisfies all alignment requirements sequentially, leaving only a potential small block of padding at the very end of the struct.

## 3. What are the dangers of using `__attribute__((packed))`?
**Answer:** Packing a struct forces the compiler to remove all padding, resulting in unaligned data members. If you pass a pointer to one of those unaligned members to another function that doesn't know the struct is packed, that function might attempt a standard 32-bit read and trigger a Hard Fault. Additionally, even if the compiler handles the unaligned reads safely, it does so by generating vastly more assembly code (multiple byte-reads and bit-shifts), significantly degrading performance.
