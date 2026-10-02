# Lambda

## 1. Concept
A **lambda** is an anonymous function object. It allows you to write a function inline, without having to name it or place it at file scope. 

## 2. Why
Before C++11, if you wanted to pass a simple callback to an algorithm (e.g., sorting an array with a custom comparison), you had to define a full separate function or functor struct elsewhere in the file. Lambdas allow you to define the logic exactly where it's used, improving readability and locality.

## 3. Syntax

The anatomy of a lambda is: `[captures](parameters) -> return_type { body }`

```cpp
// Basic lambda
auto greet = []() {
    std::cout << "Hello!\n";
};
greet();

// Lambda with parameters
auto add = [](int a, int b) -> int {
    return a + b;
};
```

### Captures
The square brackets `[]` allow the lambda to access local variables from the scope it was created in.
```text
[]        — Capture nothing (Stateless)
[x]       — Capture x by value (creates a local copy)
[&x]      — Capture x by reference (can modify original)
[=]       — Capture all used local variables by value
[&]       — Capture all used local variables by reference
```

```cpp
int count = 0;
// Capture 'count' by reference
auto increment = [&count]() {
    count++;  // Modifies the original
};
increment();
// count is now 1
```

## 4. Example
*(See `examples/` for runnable code demonstrating lambdas as callbacks).*

## 5. Embedded usage (The Function Pointer Rule)
In embedded programming, most hardware drivers (like `uart.c` or `timer.c`) are written in C and require a standard C function pointer for callbacks:
`typedef void (*callback_t)(void);`

**The Golden Rule:**
A C++ lambda can only decay (convert) into a C function pointer if it has an **empty capture list `[]`** (stateless).

```cpp
// WORKS: Captures nothing. Decays to a raw pointer.
uart_set_callback([]() { do_something(); });

int id = 5;
// FAILS TO COMPILE: Captures state. Cannot be converted to a raw C pointer.
uart_set_callback([id]() { do_something(id); });
```
Why? Because a capturing lambda is implemented by the compiler as an anonymous `class` with member variables (the captured state). A C function pointer is just a memory address, it has no mechanism to hold an object instance.

## 6. Trade-offs

| Feature | Pros | Cons |
|---------|------|------|
| **Stateless Lambda `[]`** | Extremely readable. Zero overhead. Decays to C pointer. | Cannot access local variables. |
| **Stateful Lambda `[&]`** | Can easily close over local state. | Cannot be passed to C drivers. Prone to dangling reference bugs. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice lambda captures.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
