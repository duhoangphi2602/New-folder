# gcc vs g++

## 1. The GNU Compiler Collection
"GCC" historically stood for the GNU C Compiler. Today, it stands for the **GNU Compiler Collection**. It is a massive suite of tools that can compile C, C++, Fortran, Ada, and Go.
The two commands you will use most often are `gcc` and `g++`. Both are just "Driver" programs. They are like project managers that look at your files and decide which internal sub-compilers to execute.

## 2. Compiling (Stage 2)
How do the drivers decide which language rules to apply? They look at the file extension!
- If you pass `main.c` to **either** `gcc` or `g++`, they will both compile it using strict C rules.
- If you pass `main.cpp` to **either** `gcc` or `g++`, they will both compile it using strict C++ rules (Name mangling, Classes, Templates).

Wait, if they both compile a `.cpp` file exactly the same way, what is the difference? 
The difference is entirely in **Stage 4 (The Linker)**.

## 3. Linking (Stage 4)
When you write C++ code, you often rely on the C++ Standard Library (`libstdc++`). For example, if you use the `new` keyword to allocate memory, or `#include <string>`, you are relying on thousands of lines of pre-compiled C++ code provided by the toolchain.

- **The `gcc` command:** When it reaches the Linker stage, it assumes this is a pure C project. It automatically links the C Standard Library (`libc.a`). It does **NOT** link the C++ Standard Library.
- **The `g++` command:** When it reaches the Linker stage, it assumes this is a C++ project. It automatically links **both** the C Standard Library (`libc.a`) AND the C++ Standard Library (`libstdc++.a`).

## 4. The Classic Error
If you run: `gcc main.cpp -o app`
The file will compile perfectly (Stage 2 succeeds). But the Linker (Stage 4) will crash with massive errors like:
`undefined reference to operator new(unsigned int)`
`undefined reference to std::cout`
Because `gcc` refused to link `libstdc++.a`, the Linker cannot find the implementations for `new` or `cout`.

**Rule of Thumb:**
- If your project contains *only* `.c` files, build with `gcc`.
- If your project contains *even a single* `.cpp` file, you must build the entire project using `g++`.

## 5. Example
*(See `examples/` for a simulated command-line output demonstrating the difference).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
