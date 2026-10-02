# Your First Program

This folder contains two simple programs: one in C, one in C++.

## Compiling manually

You can compile these directly from the terminal if your compiler is installed:

**For C:**
```bash
gcc hello_c.c -o hello_c
./hello_c
```

**For C++:**
```bash
g++ -std=c++17 hello.cpp -o hello_cpp
./hello_cpp
```

## Compiling with CMake

Alternatively, use CMake (which we will use for the rest of the repository):

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This will generate `hello_c` and `hello_cpp` executables in the build folder. Run them!
