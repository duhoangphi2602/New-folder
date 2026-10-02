# Enum Class (C++11)

## What is this topic?
This topic covers the `enum class` (Scoped Enumeration), which was introduced in C++11 to completely fix the flaws of legacy C-style enums.

## Why is it important?
In large embedded codebases, naming collisions are a constant nightmare. A C++11 `enum class` prevents namespace pollution, guarantees absolute type safety (preventing accidental integer math), and allows you to strictly define the memory size of the enum (e.g., forcing it to be exactly 1 byte to save RAM). **You should use `enum class` for 100% of new enumerations in modern C++.**

## Prerequisites
- [07-enum](../07-enum/README.md)

## Learning Outcomes
1. Learn how to declare and use an `enum class`.
2. Understand how it solves namespace pollution via scope resolution (`::`).
3. Learn how to explicitly set the underlying data type to save memory.
