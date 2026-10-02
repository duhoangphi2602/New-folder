# Solutions: typedef and using

## Solution 1: Translate to `using`
**Answer:**
```cpp
using uint16_t = unsigned short int;

struct Point { float x; float y; }; // 'using' is not needed for struct definitions in C++!

using IntPtr = int*;
```

## Solution 2: The `typedef struct` Hack
**Answer:** 
- **In C:** When you define `struct Device { int id; };`, the compiler puts `Device` in a special namespace just for structs. To declare a variable, you are forced to type `struct Device my_dev;` every single time. By wrapping it in `typedef struct { ... } Device;`, you alias the anonymous struct to the global type name `Device`, allowing you to just type `Device my_dev;`.
- **In C++:** The language architects realized typing `struct` repeatedly was annoying. In C++, defining `struct Device { int id; };` automatically makes `Device` a fully recognized global type. You can immediately type `Device my_dev;`. Therefore, writing `typedef struct { ... } Device;` in C++ is redundant legacy code.
