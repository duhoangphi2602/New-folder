# Interview Questions: Alignment

## 1. What happens if you perform an unaligned memory access on an ARM Cortex-M0 vs an x86 processor?
**Answer:** On an ARM Cortex-M0 (and many other strict RISC architectures), an unaligned access triggers a hardware exception (Hard Fault) and crashes the system. On an x86 processor, the hardware automatically handles the unaligned access by performing multiple bus reads and stitching the data together, which prevents a crash but introduces a performance penalty.

## 2. Why is casting a `uint8_t*` to a `uint32_t*` dangerous in embedded systems?
**Answer:** A `uint8_t` array has an alignment requirement of 1, meaning it can start at any odd or even address. A `uint32_t` requires an alignment of 4. If you cast the pointer and the underlying byte array happens to start at an unaligned address (like `0x1001`), dereferencing that `uint32_t*` will cause an alignment fault on strict architectures.

## 3. How do you safely extract a 32-bit integer from an unaligned byte buffer?
**Answer:** You should use `std::memcpy`. 
```cpp
uint32_t value;
std::memcpy(&value, unaligned_ptr, sizeof(value));
```
Modern compilers recognize this pattern and will emit the most efficient, safe assembly code for the target architecture (e.g., combining multiple 1-byte load instructions into a register).
