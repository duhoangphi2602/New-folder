# Atomic Operations (<atomic>)

## What is this topic?
This topic introduces C++11 `<atomic>`, a powerful feature that allows you to safely read and modify shared variables across multiple Tasks/ISRs *without* using Mutexes or Critical Sections.

## Why is it important?
Mutexes are slow and cannot be used in ISRs. Critical Sections are safe in ISRs but destroy system latency. Atomic operations solve both problems: they are infinitely faster than Mutexes, 100% safe to use inside Hardware Interrupts, and do not cause system latency. They are the ultimate weapon for Lock-Free embedded programming.

## Prerequisites
- [06-race-condition](../06-race-condition/README.md)
- [07-critical-section](../07-critical-section/README.md)

## Learning Outcomes
1. Define what makes an operation "Atomic" at the CPU architecture level.
2. Use `std::atomic` to build lock-free counters and flags.
3. Understand the hardware requirements (LDREX/STREX on ARM) for atomic operations.
