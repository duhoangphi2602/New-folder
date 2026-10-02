# ISR Best Practices

## What is this topic?
This topic lays out the unbreakable rules for writing C/C++ code inside an Interrupt Service Routine (ISR). 

## Why is it important?
Writing an ISR is not like writing a normal function. Because an ISR halts the main program (and potentially the entire RTOS Scheduler), any mistake inside an ISR will cause catastrophic system failure. Following these best practices separates amateur code from professional, aerospace-grade firmware.

## Prerequisites
- [01-interrupt-concept](../01-interrupt-concept/README.md)
- [09-semaphore](../../07-rtos-concurrency/09-semaphore/README.md)

## Learning Outcomes
1. Memorize the 3 Golden Rules of ISRs.
2. Understand why blocking functions (delay, printf) must never be used in an ISR.
3. Understand how to safely offload heavy processing to RTOS Tasks.
