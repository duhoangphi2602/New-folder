# 02 — Pointers & Arrays

Pointers are arguably the most important concept in C/C++ for embedded systems. A pointer is an address — and on a microcontroller, **everything is an address**: RAM, Flash, hardware registers, peripheral buffers. Understanding pointers is the gateway to understanding how firmware interacts with hardware.

## Prerequisites
- Chapter 01 (Program Structure)

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [Variables and Addresses](./01-variables-and-addresses/) | How variables map to memory |
| 02 | [Pointer Basics](./02-pointer-basics/) | Declaration, `*`, `&`, dereferencing |
| 03 | [Pointer Arithmetic](./03-pointer-arithmetic/) | Incrementing, array traversal |
| 04 | [Arrays](./04-arrays/) | Declaration, initialization, multi-dimensional |
| 05 | [Array vs Pointer](./05-array-vs-pointer/) | Decay, `sizeof` trap, common bugs |
| 06 | [Pointer to Pointer](./06-pointer-to-pointer/) | Double pointers, dynamic 2D arrays |
| 07 | [void Pointer](./07-void-pointer/) | Generic pointer, type erasure in C |
| 08 | [nullptr](./08-nullptr/) | C++11 null pointer, replacing NULL |
| 09 | [const and Pointer](./09-const-and-pointer/) | `const int*` vs `int* const` |
| 10 | [Pointer vs Reference](./10-pointer-vs-reference/) | When to use which |
| 11 | [Dangling Pointer](./11-dangling-pointer/) | Use-after-free, stack return bugs |
| 12 | [Memory Safety](./12-memory-safety/) | Bounds checking, defensive programming |
| 13 | [Alignment](./13-alignment/) | Natural alignment, unaligned access |
| 14 | [Memory-Mapped Register](./14-memory-mapped-register/) | MMIO, volatile pointer, register access |
| 15 | [std::array](./15-std-array/) | Fixed-size container, replacing raw arrays |
| 16 | [std::string_view](./16-std-string-view/) | C++17 non-owning string reference |

## Learning Outcomes
After completing this chapter, you should be able to:
- Explain what a pointer is at the hardware level (an address in memory)
- Use pointer arithmetic to traverse arrays and buffers
- Distinguish between `const int*`, `int* const`, and `const int* const`
- Identify and prevent dangling pointer bugs
- Access memory-mapped hardware registers using volatile pointers
- Prefer `std::array` over C arrays and `std::string_view` over `const char*`
