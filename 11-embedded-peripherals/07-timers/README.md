# Hardware Timers

## What is this topic?
This topic explores **Hardware Timers**, the precision chronometers built into the silicon. They track time completely independently of the CPU.

## Why is it important?
Beginners often create delays using `for` loops (e.g., `for(int i=0; i<1000; i++);`). As we learned in Chapter 10, compiler optimizations will delete this loop. Even if it isn't deleted, any interrupts that fire during the loop will artificially lengthen the delay, making it highly inaccurate. Hardware Timers provide absolute, microsecond-perfect precision regardless of what the CPU is doing.

## Prerequisites
- [14-optimization](../../10-toolchain-build/14-optimization/README.md)
- [01-interrupt-vector-table](../../08-interrupt-isr/01-interrupt-vector-table/README.md)

## Learning Outcomes
1. Define the Prescaler (PSC) and Auto-Reload Register (ARR).
2. Calculate the exact frequency of a Timer Update Interrupt.
3. Understand how hardware timers solve the "blocking delay" problem.
