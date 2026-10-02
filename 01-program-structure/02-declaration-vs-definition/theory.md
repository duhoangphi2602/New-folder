# Declaration vs Definition

## 1. Concept
In C/C++, a **declaration** introduces a name and its type to the compiler. A **definition** provides the actual implementation or storage.

```text
Declaration:  "This thing exists and has this type."
Definition:   "This thing exists, has this type, and HERE is its implementation/storage."
```
Every definition is also a declaration, but not every declaration is a definition.

## 2. Why
The compiler processes files top-to-bottom. If you want to use a function or variable, the compiler needs to know its name and type *before* you use it (Declaration). However, the linker needs exactly one implementation to construct the final executable (Definition).

This is formalized as the **One Definition Rule (ODR)**:
- A translation unit may have **multiple declarations** of the same entity.
- There must be **exactly one definition** across the entire program.

## 3. Syntax

### Variables
```cpp
// Declaration (no storage allocated). Placed in .h file.
extern int counter;

// Definition (storage allocated). Placed in exactly ONE .cpp file.
int counter = 0;
```

### Functions
```cpp
// Declaration (prototype). Placed in .h file.
int add(int a, int b);

// Definition. Placed in exactly ONE .cpp file.
int add(int a, int b) {
    return a + b;
}
```

### Classes / Structs
```cpp
// Forward declaration (incomplete type).
class Sensor;

// Definition (complete type). Placed in .h file.
class Sensor {
public:
    void init(); // Declaration of member function
};
```

## 4. Example
*(See `examples/` for runnable code demonstrating forward declarations).*

Forward declarations let you use a type by pointer or reference without including its full header.
```cpp
// Instead of #include "sensor.h"
class Sensor;  // forward declaration

class Controller {
    Sensor* sensor_;  // OK: compiler knows pointers are 4/8 bytes.
    // Sensor sensor_obj_; // ERROR: compiler doesn't know the size of a Sensor yet.
};
```

## 5. Embedded usage
In embedded firmware with many modules (drivers, HAL, application), minimizing `#include` statements reduces compile times and breaks circular dependencies. For example, a `uart.h` header can forward-declare a `DmaChannel` struct instead of including the entire massive DMA subsystem header.

## 6. Trade-offs

| Feature | Pros | Cons |
|---------|------|------|
| **Forward Declarations** | Drastically speeds up compile times. Decouples modules. | Can only be used for pointers/references. Extra typing. |
| **`#include` everything** | Easy. Allows using objects by value. | Slow compilation. Creates tangled dependencies. |

## 7. Exercises
Please proceed to the `exercises/` folder to test your understanding of the One Definition Rule.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
