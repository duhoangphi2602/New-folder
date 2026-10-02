# Solutions: Memory Alignment

## Solution 1: Finding the Fault
**Answer:**
1. The address is `0x20001002`. (Base address `...1000` + 2 bytes offset).
2. `*ptr_a` is a 16-bit (`uint16_t`) read. A 16-bit read requires 2-byte alignment (the address must be even). Since `0x...1002` is an even number (divisible by 2), it is perfectly aligned. **It will NOT crash.**
3. `*ptr_b` is a 32-bit (`uint32_t`) read. A 32-bit read requires 4-byte alignment (the address must be divisible by 4). `0x...1002` is NOT divisible by 4. Therefore, it is unaligned. **It WILL crash.**

## Solution 2: `alignof` Structs
**Answer:** A `struct` contains multiple members. If the entire struct is placed at an unaligned address in RAM, all of its internal members will also be shifted and unaligned. To guarantee that the largest member inside the struct (e.g., an 8-byte `double`) is placed on a legally aligned boundary (an address divisible by 8), the compiler must force the starting address of the *entire struct* to also be an address divisible by 8. Therefore, the struct inherits the strictness of its largest member.
