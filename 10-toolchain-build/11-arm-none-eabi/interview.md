# Interview Questions: arm-none-eabi

## 1. What does the "none" stand for in `arm-none-eabi-gcc`?
**Answer:** The `none` field in the GCC toolchain tuple represents the Operating System (or occasionally the Vendor). In this specific tuple, `none` means "Bare-Metal". It tells the compiler that the target hardware does not have an operating system like Linux or Windows. Consequently, the compiler will use a bare-metal C standard library (like `newlib` or `nano`) instead of `glibc`, and it will not attempt to link POSIX OS system calls (like thread creation or file I/O).

## 2. What is an ABI (Application Binary Interface)? How is it different from an API?
**Answer:** An API (Application Programming Interface) is a source-code level contract. It tells the human developer the name of the function and what types it takes (e.g., `int add(int a, int b);`). 
An ABI (Application Binary Interface) is a machine-code level contract. It tells the Compiler exactly how to implement that API in physical hardware. For example, the ARM EABI dictates that the first integer argument must go into register `R0`, the second into `R1`, and the return value must be placed in `R0`. All `.o` files in a project must be compiled using the exact same ABI, otherwise they cannot communicate with each other.

## 3. If you have an STM32 with a physical Hardware FPU (Floating Point Unit), but you compile your firmware using `arm-none-eabi-gcc` (without the `hf` hard-float ABI), what will happen?
**Answer:** The code will compile and run perfectly fine, but it will be extremely slow. Because you used the soft-float ABI, the compiler will ignore the physical hardware FPU entirely. It will translate every decimal math operation into hundreds of software instructions using standard integer registers to simulate floating-point math. To actually utilize the silicon FPU, you must configure the compiler to use the hard-float ABI (using flags like `-mfloat-abi=hard` or by using the `arm-none-eabihf-gcc` toolchain).
