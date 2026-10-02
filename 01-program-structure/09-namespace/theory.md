# Namespace

## 1. Concept
A **namespace** is a C++ feature that groups identifiers (functions, classes, constants) into a named scope. It acts as a container to prevent naming conflicts in large codebases.

## 2. Why
Imagine writing a firmware project using a vendor HAL library and a third-party RTOS. Both might have a function named `Delay()`. If written in C, the linker will crash with a "multiple definition" error. 
C solves this via manual prefixes (`HAL_Delay` vs `RTOS_Delay`). C++ solves this elegantly with namespaces.

## 3. Syntax

### Defining and Using
```cpp
namespace hal {
    void uart_init(unsigned int baud);
}

// Usage requires the scope resolution operator (::)
hal::uart_init(115200);
```

### Nested Namespaces (C++17)
C++17 introduced a compact syntax for deeply nested namespaces.
```cpp
// Pre-C++17
namespace project {
    namespace hal {
        namespace uart {
            void init();
        }
    }
}

// C++17 (Much cleaner)
namespace project::hal::uart {
    void init();
}
```

### Anonymous Namespace (Internal Linkage)
If you omit the name, you create an anonymous namespace. Anything inside it is completely hidden from other `.cpp` files. This is the C++ equivalent of using `static` at file scope.
```cpp
namespace {
    int helper_counter = 0;  // Invisible to other files
}
```

## 4. Example
*(See `examples/` for runnable code demonstrating namespace collision resolution).*

## 5. Embedded usage
In modern embedded C++ projects, namespaces completely replace the C-style prefix convention:
```text
C style:        uart_init(), uart_send(), gpio_set(), gpio_clear()
C++ namespace:  hal::uart::init(), hal::gpio::set()
```
Namespaces are purely a compile-time construct. They have **zero runtime overhead**, consuming no extra CPU cycles or RAM compared to C prefixes.

## 6. Trade-offs (The `using` directive)
The `using` keyword allows you to omit the namespace prefix.

| Usage | Example | Verdict |
|-------|---------|---------|
| **Inside a `.cpp` function** | `using namespace std;` inside `main()` | **Acceptable**. Scope is limited to the function. |
| **At the top of a `.cpp` file** | `using namespace hal;` | **Acceptable**, but can cause local ambiguity. |
| **At the top of a `.h` file** | `using namespace std;` in `config.h` | **FATAL ERROR**. Pollutes the global namespace for every file that includes it, destroying the entire purpose of namespaces. |

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
