# Interview Questions: Compilation

## 1. What does the Compiler do when it encounters an `#include` directive?
**Answer:** Absolutely nothing. The Compiler never sees `#include` directives. Stage 1 of the toolchain (The Preprocessor) resolves all `#include` directives by physically copy-pasting the text from the header files into a temporary Translation Unit. By the time Stage 2 (The Compiler) receives the file, all `#include` lines have already been deleted and replaced with raw C++ declarations.

## 2. Explain the concept of "Dead Code Elimination" during the Optimization phase.
**Answer:** During semantic analysis, the compiler builds an Abstract Syntax Tree (AST). If you compile with optimizations enabled (like `-O2`), the compiler analyzes the logical flow of the AST. If it finds code that mathematically can never be executed (e.g., `if (1 == 2) { ... }`), or variables that are calculated but never used to affect the outside world (no observable side effects), the compiler will completely delete that code from the final Assembly output. This saves Flash memory and speeds up execution, but can cause bugs if you forget to use `volatile` on hardware registers.

## 3. If you have 10 `.cpp` files in your project, how many times does the Compiler run?
**Answer:** The Compiler runs exactly 10 separate times. The compiler operates on a single Translation Unit at a time, completely in isolation. It has no idea that the other 9 files exist. This is why header files (Declarations) are necessary—to promise the compiler that functions exist in other files. It is the job of the Linker (Stage 4) to run once at the very end to merge the 10 separate outputs together.
