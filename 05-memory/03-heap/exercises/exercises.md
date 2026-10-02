# Exercises: The Heap

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: `malloc` vs `new`
In C, you use `malloc()` and `free()`. In C++, you use `new` and `delete`.
**Task:** Beyond just being cleaner syntax, what is the critical object-oriented difference between calling `malloc` and calling `new` when creating a C++ `class` object?

## Exercise 2: Fragmentation Visualization
Imagine you have a tiny Heap with exactly 10 bytes of free RAM. 
1. You allocate Pointer A (3 bytes).
2. You allocate Pointer B (4 bytes).
3. You allocate Pointer C (3 bytes).
4. You call `free(B)`.
**Task:** How many total bytes of free RAM do you have right now? If you immediately call `malloc(5)` to request a 5-byte buffer, what happens and why?
