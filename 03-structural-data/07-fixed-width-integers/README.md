# Fixed-Width Integers (<cstdint>)

## What is this topic?
This topic covers `stdint.h` (C) and `<cstdint>` (C++), which provide strictly defined integer types like `uint8_t`, `int32_t`, and `uint64_t`.

## Why is it important?
In desktop programming, a standard `int` might be 32 bits or 64 bits depending on the CPU architecture. In embedded programming, you are frequently reading from hardware registers that are exactly 8, 16, or 32 bits wide. If your data types do not perfectly match the hardware register size, your code will corrupt memory. Using fixed-width integers is a mandatory, non-negotiable rule in Embedded C/C++.

## Prerequisites
- [06-typedef](../06-typedef/README.md)

## Learning Outcomes
1. Understand why `int`, `long`, and `short` are banned in modern embedded standards (like MISRA-C).
2. Learn the syntax and naming convention of `<cstdint>`.
3. Apply fixed-width integers to hardware register definitions.
