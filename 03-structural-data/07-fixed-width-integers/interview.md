# Interview Questions: Fixed-Width Integers

## 1. Why are native types like `int` and `long` forbidden in safety-critical embedded systems (e.g., MISRA-C guidelines)?
**Answer:** Because their sizes are architecture-dependent. An `int` can be 16, 32, or 64 bits depending on the compiler and the target CPU. This lack of determinism means code that passes all tests on a Desktop simulator might silently suffer from integer overflows when compiled for the actual microcontroller, causing fatal hardware crashes.

## 2. On a 32-bit ARM processor, what is the trade-off between using a `uint8_t` versus a `uint32_t` for a simple loop counter?
**Answer:** `uint8_t` consumes less RAM. However, the native ALU (Arithmetic Logic Unit) of the ARM processor is 32 bits wide. When you perform math on a `uint8_t`, the compiler often has to insert extra `UXTB` (Unsigned Extend Byte) assembly instructions to zero out the top 24 bits of the register before saving the result, which consumes extra CPU cycles. For variables that live purely in registers (like a loop counter), `uint32_t` is actually the fastest and most efficient data type.

## 3. What does `uintptr_t` do?
**Answer:** `uintptr_t` is an unsigned integer type that is guaranteed to be exactly the same size as a memory pointer on the target architecture (32 bits on ARM Cortex-M, 64 bits on a Desktop PC). It is used when you need to perform bitwise arithmetic on memory addresses (like checking memory alignment) without relying on undefined C pointer arithmetic.
