# Exercises: Pointer Arithmetic

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Address Math
You have a pointer:
```cpp
uint64_t* ptr = reinterpret_cast<uint64_t*>(0x1000);
```
**Task:** What is the physical memory address held by `ptr` after executing `ptr = ptr + 3;`? Show your math.

## Exercise 2: Array Indexing Equivalence
In C/C++, `arr[i]` is actually just syntactic sugar for pointer arithmetic.
**Task:** Rewrite the expression `arr[4] = 99;` using only pointer arithmetic (the `*` and `+` operators) without using square brackets `[]`.

## Exercise 3: The Void Pointer Trap
A junior developer wants to advance a pointer by exactly 5 bytes, regardless of what type it points to. They write this code:
```cpp
void advance_5_bytes(void* ptr) {
    ptr = ptr + 5;
}
```
**Task:** This code will fail to compile on standard strict C++ compilers. Why? How must you modify the code to successfully advance the pointer by exactly 5 physical bytes?
