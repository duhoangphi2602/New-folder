# Contributing Guidelines and Standards

This repository is designed as a consistent, production-oriented learning resource. When adding or modifying content, strict adherence to these standards is required to maintain depth and quality.

## 1. Topic Folder Structure

Every topic folder must contain:

```text
topic-name/
├── README.md         # Brief intro and links
├── theory.md         # Full theoretical explanation
├── examples/         # Runnable code examples
├── exercises/        # Practice problems (if applicable)
├── solutions/        # Solutions to exercises (if applicable)
└── interview.md      # Related interview questions
```

## 2. Theory Document Standard (`theory.md`)

Do not just write "what it is". Explain the "why" and "how". Every `theory.md` must follow the **20-Criteria Framework** (where applicable):

1. Definition
2. Purpose (Why does it exist?)
3. Core Syntax
4. How it works (Under the hood)
5. Memory behavior
6. CPU/runtime behavior
7. Compiler behavior
8. Embedded relevance
9. Hardware relevance
10. Simple C/C++ example
11. Embedded example
12. Practical use case
13. Advantages
14. Limitations
15. Common pitfalls
16. Safety concerns
17. Performance considerations
18. Alternatives
19. Interview questions reference
20. Exercises reference

## 3. Code Standards

- **Language Standard**: C++17 (unless explicitly contrasting with C or older C++).
- **Naming**: `snake_case` for files and variables, `PascalCase` for classes/structs.
- **Determinism**: Avoid dynamic allocation (`malloc`/`new`) unless specifically teaching it. Use `std::array` over `std::vector`.
- **Comments**: Keep comments instructional. Explain *why* code is written a certain way, especially if memory or hardware is involved.
- **Simulations**: If hardware is required (e.g., UART, GPIO), provide a PC-runnable simulation using mock registers (e.g., `uint32_t simulated_reg`).

## 4. Example Requirements

Every example file must have a header block:

```cpp
/*
 * Language: C++17
 * Target: PC/Simulation (or specific MCU)
 * Build: g++ -std=c++17 example.cpp -o example
 * Run: ./example
 * Expected output: ...
 * What to learn: ...
 */
```

## 5. Broken/Fixed Examples

When teaching safety or concurrency (e.g., pointers, race conditions, `volatile`), use the Broken/Fixed pattern:

1. `broken_example.cpp` (Shows the bug)
2. Explanation in `theory.md`
3. `fixed_example.cpp` (Shows the resolution)

## 6. Cross-Referencing

Use relative Markdown links to connect related topics. Avoid duplicating large explanations.

Example: `[See Linker Script](../../05-memory/13-linker-script/theory.md)`
