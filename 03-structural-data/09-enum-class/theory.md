# Enum Class (C++11)

## 1. Concept
An `enum class` (also known as a scoped enumeration) is a strictly typed, strictly scoped enumeration. It behaves exactly like an object-oriented class in terms of scoping: its internal values do not leak to the outside world.

## 2. Why
Legacy C-style enums allow code like this:
```cpp
enum Color { RED, GREEN };
enum Alert { RED, ORANGE }; // COMPILER ERROR: RED is already defined!
```
An `enum class` completely prevents this.

## 3. Syntax (Declaration and Scope Resolution)

```cpp
// Declare with 'enum class'
enum class Color {
    RED,
    GREEN
};

enum class Alert {
    RED, // Perfectly fine! No collision.
    ORANGE
};

// Usage requires the Scope Resolution Operator (::)
Color my_color = Color::RED;
Alert my_alert = Alert::RED;
```

## 4. Example
*(See `examples/` for runnable code demonstrating type safety and size optimizations).*

## 5. Embedded usage (RAM Optimization)
By default, the compiler usually makes an enum an `int` (4 bytes). In embedded systems, if your enum only has 3 states, 4 bytes is a massive waste of RAM. C++11 allows you to define the underlying type of an `enum class`.

```cpp
#include <cstdint>

// Forces the enum to take up exactly 1 byte of RAM
enum class StateMachine : uint8_t {
    IDLE = 0,
    RUNNING = 1,
    FAULT = 2
};

// Now you can safely use it in hardware structs!
struct Packet {
    StateMachine state; // Exactly 1 byte
    uint8_t data[3];    // 3 bytes
}; // Total size: 4 bytes (No padding needed!)
```

## 6. Trade-offs (Strict Type Safety)
Because `enum class` is strictly typed, it **does not** implicitly convert to an integer.

```cpp
enum class Status { OK, ERROR };

Status s = Status::OK;

// int val = s;          // COMPILER ERROR! Cannot convert implicitly.
// if (s == 0)           // COMPILER ERROR! Cannot compare to int.

// If you MUST get the integer value (e.g., for array indexing),
// you must explicitly cast it:
int val = static_cast<int>(s);
```
While this strictness requires slightly more typing (`static_cast`), it prevents catastrophic bugs where developers accidentally add two enums together or pass the wrong enum to a function.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
