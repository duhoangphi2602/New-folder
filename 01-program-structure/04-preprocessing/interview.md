# Interview Questions: Preprocessing

## 1. What is the difference between `#include <header>` and `#include "header"`?
**Answer:** 
- `<header>` (angle brackets) tells the preprocessor to search for the file in the standard system directories (used for standard libraries like `<iostream>` or `<stdint.h>`).
- `"header"` (quotes) tells the preprocessor to search in the local directory (the same folder as the source file) first, before falling back to the system directories.

## 2. Why should you prefer `constexpr` over `#define` in C++?
**Answer:** `#define` is a blind text replacement. It ignores C++ namespaces, offers zero type safety, and makes debugging difficult because the symbol name doesn't exist in the compiled code (only the raw value). `constexpr` defines a true, strongly-typed C++ variable whose value is evaluated at compile-time, respecting scope and type rules.

## 3. What is conditional compilation and when is it used in embedded systems?
**Answer:** Conditional compilation uses `#ifdef`, `#ifndef`, and `#if` directives to include or exclude blocks of code before the compiler sees them. In embedded systems, it is heavily used to support multiple hardware targets from the same codebase, or to toggle heavy features (like UART debug logging) on and off based on Release/Debug build flags.

## 4. What is the `do { ... } while(0)` macro trick?
**Answer:** It is a technique used in C to define multi-statement macros. It safely wraps the statements in a block that demands exactly one trailing semicolon, preventing syntax errors when the macro is used inside unbraced `if/else` statements.
