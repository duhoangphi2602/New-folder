# Volatile Keyword in ISRs

## What is this topic?
This topic demystifies the `volatile` keyword in C/C++, explaining its critical, non-negotiable role in preventing the compiler from deleting your hardware-interaction code during optimization.

## Why is it important?
If you write a perfect ISR that updates a global variable, but you forget to label that variable as `volatile`, your code will work flawlessly in "Debug" mode, but will completely freeze and fail when you build the "Release" version. Understanding why the compiler behaves this way is a fundamental rite of passage in embedded software.

## Prerequisites
- [01-interrupt-concept](../01-interrupt-concept/README.md)
- [03-isr-best-practices](../03-isr-best-practices/README.md)

## Learning Outcomes
1. Understand the compiler optimization process regarding memory caching.
2. Apply `volatile` to variables modified inside an ISR.
3. Differentiate between `volatile` (compiler barrier) and `std::atomic` (CPU barrier).
