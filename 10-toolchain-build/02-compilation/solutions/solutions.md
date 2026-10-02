# Solutions: Compilation

## Solution 1: Finding the Culprit
**Answer:** The junior developer is completely incorrect. The C++ Compiler (Stage 2) succeeded perfectly. We know this because the terminal printed `Compiling main.cpp... OK`, meaning `main.cpp` was successfully converted into `main.o`. 
The build failed at Stage 4 (The Linker). The compiler doesn't care if `init_hardware()` actually exists; it just assumes it exists somewhere else based on the header file declaration. The Linker is the one who couldn't find the physical implementation of the function when it tried to merge all the `.o` files together.

## Solution 2: Syntax vs Semantics
**Answer:** 
- **Line B** causes a **Syntax Error**. The compiler is scanning for structural rules (Tokens). C++ grammar mandates a semicolon at the end of a statement. The compiler doesn't even care what `x` or `5` is yet; the basic grammar is broken.
- **Line A** causes a **Semantic Error**. The syntax is structurally perfect. However, when the compiler reaches the Type Checking phase, it realizes the *meaning* (semantics) is illogical. You cannot assign a `const char*` (string) to an `int` type.
