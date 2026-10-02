# Solutions: arm-none-eabi

## Solution 1: The Wrong Compiler
**Answer:** The program will instantly crash.
The `-linux-` part of the toolchain name means the compiler assumes a full Linux Operating System is running on the hardware. 
1. It will dynamically link your code against the Linux C Standard Library (`glibc`), which expects a Linux Kernel to be present.
2. It assumes Virtual Memory (MMU) is active, generating memory addresses that make no sense to a bare-metal microcontroller's physical memory map.
To compile for a Raspberry Pi Pico, you *must* use `arm-none-eabi-gcc` (Bare-metal).

## Solution 2: ABI Mismatch
**Answer:** The ABI (Application Binary Interface) dictates how arguments are passed between functions at the raw register level.
- The library was compiled with `eabi` (Soft Float). If you call `add_floats(1.5, 2.5)` inside the library, the library expects those decimal numbers to be passed inside standard integer registers (`R0`, `R1`).
- Your code is compiled with `eabihf` (Hard Float). When your code calls `add_floats()`, it puts the decimals into the special hardware FPU registers (`S0`, `S1`).
The Linker detects this catastrophic mismatch. If it allowed the link to succeed, your code would put data in `S0`, but the library would read garbage from `R0`, causing the math to be completely wrong.
