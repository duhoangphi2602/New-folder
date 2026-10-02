# C Standard I/O (printf / scanf)

## What is this topic?
This topic covers the legacy C standard input/output functions provided by `<cstdio>` (`<stdio.h>`), specifically `printf` and `scanf`.

## Why is it important?
Even in modern C++ embedded systems, `printf` remains the undisputed king of logging and debugging. While C++ streams (`std::cout`) are preferred on desktop applications, they are often banned in embedded systems due to extreme memory bloat. Understanding how to use `printf` format specifiers correctly is a mandatory skill for any embedded engineer.

## Prerequisites
- [01-variables-and-addresses](../../02-pointers-arrays/01-variables-and-addresses/README.md)

## Learning Outcomes
1. Learn how to format and print variables using `printf`.
2. Understand common format specifiers (`%d`, `%x`, `%f`, `%p`).
3. Learn how to use `scanf` to read formatted input (and understand its dangers).
