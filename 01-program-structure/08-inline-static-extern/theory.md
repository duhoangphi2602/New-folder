# inline, static, extern

## 1. Concept
These three keywords are storage class and linkage specifiers. They tell the compiler and linker how to treat a variable or function in the context of the entire project.

## 2. Why
By default, global variables and functions have **External Linkage** (they are visible to every file in the project). If two files accidentally use the same name, the linker will crash. We need keywords to hide things (`static`), share things explicitly (`extern`), and relax definition rules (`inline`).

## 3. Syntax & Meaning

### The 3 Meanings of `static`
1. **File-Scope `static` (Internal Linkage):** Hides a global variable or function from other `.cpp` files.
2. **Function-Scope `static` (Persistent Local):** A local variable that doesn't die when the function returns.
3. **Class `static`:** A class member shared by all instances of the class.

### `extern`
`extern` declares a variable with **external linkage** — it says "this variable exists somewhere else, just trust me and let it compile."
```cpp
// config.h
extern int system_clock_hz;  // Declaration

// config.cpp
int system_clock_hz = 48000000;  // Definition
```

### `extern "C"`
Disables C++ name mangling so C code can call C++ functions (and vice versa).

### `inline`
Historically used as a hint to the compiler to insert the function body at the call site (saving function call overhead). 
More importantly, it relaxes the One Definition Rule (ODR). An `inline` function can be defined in a header file and included everywhere.
**C++17 Feature:** You can now declare variables as `inline` in a header file!
```cpp
inline constexpr int kDefaultBaudRate = 115200;
```

## 4. Example
*(See `examples/` for runnable code demonstrating these scopes).*

## 5. Embedded usage
- `static` at file scope is the **primary encapsulation mechanism** in bare-metal C drivers. If you write a helper function inside `uart.c`, you MUST mark it `static` so it doesn't conflict with a helper function in `spi.c`.
- `static` local variables are stored in RAM (`.bss` or `.data`), NOT on the stack. They are useful for state machines.
- `extern` is required to access symbols defined in the linker script (like the start of the stack `_estack`).

## 6. Trade-offs

| Keyword | Benefit | Danger |
|---------|---------|--------|
| **`static` (File)** | Prevents linker collisions. | None. Highly recommended for C code. |
| **`static` (Local)** | Persists state cleanly without globals. | **Not Thread-Safe** in C (though C++11 guarantees thread-safe initialization). |
| **`inline`** | Allows header-only libraries. | Can bloat code size if heavily used. |

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
