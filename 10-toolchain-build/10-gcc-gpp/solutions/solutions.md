# Solutions: gcc vs g++

## Solution 1: The C-Only Project
**Answer:** Yes, the project will successfully compile and link. `g++` will see the `.c` extensions, compile them strictly as C code, and link them flawlessly. 
However, the final executable will likely be **larger** (and the build process slightly slower). Because you used `g++`, the driver will automatically instruct the Linker to include the C++ Standard Library (`libstdc++.a`) and C++ runtime support code (like Exception Handling mechanisms) into your final binary. Even though your C code never uses these features, the Linker might still pull in some mandatory C++ initialization overhead, wasting valuable Flash memory on your microcontroller.

## Solution 2: Forcing the Compiler
**Answer:** You can use the `-x` language flag to override the default extension-based language detection.
Command: `g++ -x c++ driver.c -o app`
This command tells the `g++` driver: *"Ignore the `.c` extension. Force the internal compiler to treat this file strictly as C++ code."* The compiler will now successfully parse the `class` keyword. (Note: This is considered terrible practice. You should always rename C++ files to `.cpp`, `.cc`, or `.cxx`).
