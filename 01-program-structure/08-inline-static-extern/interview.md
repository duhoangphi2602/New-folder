# Interview Questions: inline, static, extern

## 1. What are the three different meanings of `static` in C/C++?
**Answer:**
1. **File-scope:** Gives a global variable or function *internal linkage*, hiding it from other translation units (acts as encapsulation).
2. **Function-scope:** Changes the storage duration of a local variable from automatic (stack) to static (persists in memory across function calls).
3. **Class-scope (C++):** Declares a member variable or function that belongs to the class itself, shared among all instances, rather than belonging to individual objects.

## 2. Where in memory does a `static` local variable live?
**Answer:** It lives in the static memory region (`.data` if initialized to a non-zero value, or `.bss` if uninitialized/zeroed). It does **not** live on the stack.

## 3. What does `extern "C"` do and why is it needed?
**Answer:** C++ supports function overloading by "mangling" function names (adding type information to the symbol name during compilation). C does not support this. `extern "C"` tells the C++ compiler to skip name mangling for the enclosed functions, allowing C++ code to link correctly with C libraries or hardware drivers.

## 4. What is the practical difference between a macro `#define MAX 10` and an `inline constexpr int MAX = 10;`?
**Answer:** The macro is a blind text replacement performed by the preprocessor, meaning it ignores C++ scopes, namespaces, and provides no type safety. The `inline constexpr` is a true C++ variable evaluated at compile time, respecting scope and typing rules while guaranteeing no ODR violations if included in multiple files.
