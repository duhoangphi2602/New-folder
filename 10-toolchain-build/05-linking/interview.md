# Interview Questions: Linking

## 1. What is the fundamental difference between an "Undefined Reference" error and an "Undeclared Identifier" error?
**Answer:** 
- An **"Undeclared Identifier"** is a Compiler error (Stage 2). It means the Compiler hit a function call like `add()`, but there was no header file included to declare that the function exists. The compiler refuses to proceed.
- An **"Undefined Reference"** is a Linker error (Stage 4). The Compiler succeeded because the function *was* declared in a header file. The Compiler left a placeholder for it. However, when the Linker tried to find the physical implementation (`.cpp` / `.o` file) to fill in that placeholder, it couldn't find it anywhere in the project or libraries.

## 2. Briefly explain the "Symbol Resolution" and "Relocation" phases of the Linker.
**Answer:** 
- **Symbol Resolution** is the process where the Linker scans the Symbol Tables of all Object files (`.o`) and Static Libraries (`.a`). It matches every Undefined symbol ('U' - representing a requirement) with exactly one Defined symbol ('T' or 'D' - representing a provided implementation).
- **Relocation** happens after all symbols are resolved. The Linker uses the Linker Script (`.ld`) to map the sections (`.text`, `.data`) to absolute physical addresses (VMA/LMA) in Flash and RAM. Finally, it goes into the raw machine code and overwrites the relative zero-offsets and blank placeholders with the calculated absolute physical addresses.

## 3. What is a "Multiple Definition" error, and what are two common ways it is caused?
**Answer:** A Multiple Definition error occurs during Symbol Resolution when the Linker finds that two or more Object files claim to provide the exact same Defined symbol (e.g., both `a.o` and `b.o` have a function named `init()`). 
It is commonly caused by:
1. Forgetting to use the `static` keyword on a helper function that shares a common name with a function in another file (violating the One Definition Rule).
2. Accidentally implementing a function body directly inside a `.h` header file (without marking it `inline`). When multiple `.cpp` files include that header, the Preprocessor copy-pastes the implementation into multiple translation units, causing the Compiler to generate the machine code for that function multiple times.
