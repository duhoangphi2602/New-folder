# Interview Preparation Guide

This repository contains a dedicated section for interview preparation at `14-interview/`.

## Quick Links to Interview Sections
- [Beginner Questions](./14-interview/beginner.md)
- [Intermediate Questions](./14-interview/intermediate.md)
- [Advanced Questions](./14-interview/advanced.md)
- [Common Mistakes in Interviews](./14-interview/common-mistakes.md)

## Topic-Specific Interviews
Most topics in this repository include their own `interview.md` file. Review those files when studying a specific chapter.

- `01-program-structure/*/interview.md`
- `02-pointers-arrays/*/interview.md`
- `05-memory/*/interview.md`
- `07-rtos-concurrency/*/interview.md`
- `09-volatile-atomic-ordering/*/interview.md`
- `11-embedded-peripherals/*/interview.md`

## The Interview Mindset
When answering embedded software questions, always follow this pattern:
1. **Define it:** What is it?
2. **Standard C/C++ usage:** How is it used on a PC?
3. **Embedded usage:** How does this behave regarding RAM, Flash, CPU cycles, and predictability?
4. **Trade-offs:** What are the pros and cons?

*Example: "What is `std::vector`?"*
**Poor answer:** It's a dynamic array in C++.
**Excellent answer:** It's a dynamically sized contiguous container in C++. In desktop apps, it's the default container. However, in embedded systems, it allocates memory on the heap, which can lead to fragmentation and non-deterministic timing if it reallocates. Therefore, in embedded C++, I prefer `std::array` for fixed bounds, or a statically-allocated custom vector class to avoid heap fragmentation.
