# Exercises: new and delete

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Array Delete Bug
A developer allocates a 10KB string buffer and then frees it:
```cpp
char* buffer = new char[10000];
// ... do stuff ...
delete buffer; 
```
**Task:** Identify the critical syntax error on line 3. What exact mechanical failure occurs when you do this?

## Exercise 2: Out of Memory Handling
In C, if `malloc` fails, it returns `NULL`.
In C++, if `new` fails, it does *not* return `nullptr`.
**Task:** What exactly does `new` do when it fails to find memory? Why is this behavior a massive problem for bare-metal embedded systems compiled with `-fno-exceptions`?
