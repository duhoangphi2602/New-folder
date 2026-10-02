# Interview Questions: gcc vs g++

## 1. If you compile `main.cpp` using the `gcc` command instead of `g++`, at which specific stage of the toolchain will the build fail, and why?
**Answer:** It will fail at Stage 4 (The Linker). The `gcc` command is perfectly capable of compiling a `.cpp` file because it analyzes the file extension and correctly invokes the internal C++ compiler (cc1plus), so Stage 2 succeeds. However, `gcc` is a C-centric driver. During the Linking stage, it automatically links the C standard library but explicitly omits the C++ standard library (`libstdc++`). Therefore, if the `.cpp` file uses any standard C++ features (like `std::string`, `cout`, or the `new` operator), the Linker will crash with massive "Undefined Reference" errors.

## 2. Why is it a bad idea to use `g++` to compile a pure C codebase?
**Answer:** While `g++` will successfully compile `.c` files using C rules, using the `g++` driver alters the Linking phase. It will automatically inject C++ runtime libraries and initialization code (such as global constructor loops and exception handling setup) into the final executable. In an embedded system with strictly limited Flash memory and RAM, pulling in unused C++ runtime overhead is a critical waste of resources.

## 3. What is the fundamental difference between `gcc` (the command) and GCC (the acronym)?
**Answer:** GCC (the acronym) stands for the GNU Compiler Collection, which is the entire suite of compilation tools, assemblers, linkers, and libraries supporting multiple languages like C, C++, Fortran, and Ada. `gcc` (the lowercase command) is merely a specific "Driver" program within that collection. Its only job is to parse command-line arguments, look at file extensions, and act as a project manager, orchestrating the execution of the actual internal compilers (like `cc1` for C or `cc1plus` for C++) and the Linker (`ld`).
