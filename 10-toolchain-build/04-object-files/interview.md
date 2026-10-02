# Interview Questions: Object Files

## 1. What is an Object File, and why can't it be executed directly by the CPU?
**Answer:** An Object File (`.o`) is the binary output of the Assembler containing the compiled machine code for a single `.cpp` file. It cannot be executed directly because it is incomplete. Any function calls or global variable accesses that reference external files are left as blank placeholders (Undefined Symbols) in the machine code. The file also does not have absolute memory addresses assigned to it yet; all code is positioned at relative offset `0x00`. It requires the Linker to resolve these missing symbols and assign physical memory addresses before it can be run.

## 2. What is a Symbol Table?
**Answer:** The Symbol Table is an internal index or dictionary embedded within an Object file or an ELF executable. It maps human-readable names (like `main` or `my_global_var`) to their corresponding relative memory offsets or marks them as `Undefined` if they are external dependencies. The Linker uses this table to connect the Undefined symbols in one Object file to the Defined symbols in another.

## 3. How does the concept of Object files enable "Incremental Builds" to drastically speed up compilation times?
**Answer:** In a large project, the toolchain compiles each `.cpp` source file independently into its own `.o` object file. If a developer edits only one `.cpp` file, the build system (like Make/CMake) compares the file modification timestamps. It realizes that 99% of the source files have not changed, so their corresponding `.o` files on the hard drive are still perfectly valid. The compiler only spends time recompiling the single modified `.cpp` file. The Linker then quickly stitches the 1 new object file together with the cached object files, reducing a 5-minute full build to a 2-second incremental build.
