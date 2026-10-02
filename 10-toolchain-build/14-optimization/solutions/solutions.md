# Solutions: Optimization

## Solution 1: Flash Memory Limit
**Answer:** You should use **`-Os`** (Optimize for Size). 
`-O3` is designed to maximize CPU execution *speed*. To make code run faster, `-O3` heavily utilizes "Loop Unrolling" and "Function Inlining". Instead of having one function called 10 times, `-O3` might copy-paste the function's machine code 10 times into the binary to avoid the overhead of jumping back and forth. This makes the code lightning fast, but significantly bloats the `.bin` file size. `-Os` intelligently balances optimization by enabling all speed optimizations that do *not* increase code size, often resulting in the smallest possible binary.

## Solution 2: The Useless Struct
**Answer:** 
The compiler will **KEEP** the three calls to `read_adc()`. Because `read_adc` accesses `volatile` registers, calling it constitutes "observable behavior". The compiler must execute them.
The compiler will **DELETE** the `magnitude` calculation and the `data.z` assignment. 
Why? Because `magnitude` is calculated but never returned, printed, or passed to a hardware register. It is "Dead Code". Furthermore, even though `data.z` is assigned the result of `read_adc(3)`, the value in `data.z` is never used. The compiler will still execute `read_adc(3)` to trigger the hardware read, but it will immediately discard the return value, completely optimizing the struct out of existence in RAM.
