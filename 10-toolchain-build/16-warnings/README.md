# Compiler Warnings

## What is this topic?
This topic covers the Warning flags (`-Wall`, `-Wextra`, `-Werror`) used to enforce strict coding standards during the compilation phase.

## Why is it important?
By default, the C++ compiler is extremely lenient. It will silently accept highly dangerous code (like implicit type conversions or unused variables) without throwing an Error. In safety-critical embedded systems, a single ignored warning can cause a catastrophic failure in production. Professional codebases mandate that all warnings be treated as fatal errors.

## Prerequisites
- [13-compiler-flags](../13-compiler-flags/README.md)

## Learning Outcomes
1. Enable comprehensive warning checks (`-Wall`, `-Wextra`).
2. Enforce absolute compliance by converting warnings to errors (`-Werror`).
3. Selectively disable specific, harmless warnings.
