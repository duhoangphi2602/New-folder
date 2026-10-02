# Professional Logging

## What is this topic?
This topic covers the transition from using basic `printf("here1")` statements to designing a professional, level-based Logging framework using C/C++ Preprocessor Macros.

## Why is it important?
Writing `printf` everywhere makes your code unreadable and severely impacts performance. In a professional system, you need the ability to print highly detailed logs during development (`DEBUG`), but completely disable them when compiling for production (`RELEASE`) to save CPU cycles and ROM space. You also need to automatically inject metadata (like the File name, Line number, and Timestamp) into every log message. This is achieved using Logging Macros.

## Prerequisites
- [01-c-standard-io](../01-c-standard-io/README.md)
- [06-printf-redirect-uart](../06-printf-redirect-uart/README.md)

## Learning Outcomes
1. Understand how to write variadic macros (`...`, `__VA_ARGS__`).
2. Use standard compiler macros (`__FILE__`, `__LINE__`) for traceability.
3. Learn how to toggle log levels at compile time to zero-out performance overhead.
