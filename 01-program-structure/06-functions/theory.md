# Functions

## 1. Concept
A function encapsulates a block of code that performs a specific task. When a function is called, the CPU pauses the current execution, jumps to the function's memory address, executes the code, and then returns to where it left off.

## 2. Why
Without functions, code would be a single, massive, unreadable block. Functions allow for code reuse, testing, and logical separation of concerns (e.g., separating hardware initialization from the main application loop).

## 3. Syntax

```cpp
// 1. Declaration (Prototype)
// Tells the compiler: "A function named 'add' exists. It takes two ints and returns an int."
int add(int a, int b);

// 2. Definition
// The actual implementation.
int add(int a, int b) {
    return a + b;
}
```

## 4. Example (Parameter Passing)
*(See `examples/` for runnable code demonstrating these concepts).*

### Pass by Value (Copy)
The function receives a completely independent copy of the variable.
```cpp
void increment_value(int x) {
    x++;  // Modifies the LOCAL copy only
}
```

### Pass by Pointer (C-Style)
The function receives the memory address of the variable.
```cpp
void increment_ptr(int* x) {
    (*x)++;  // Modifies the original variable via dereferencing
}
```

### Pass by Reference (C++ Style)
The function receives a reference (an alias) to the original variable. This looks cleaner than pointers.
```cpp
void increment_ref(int& x) {
    x++;  // Modifies the original directly
}
```

## 5. Embedded usage (Stack & Performance)
In embedded firmware, functions are compiled into the `.text` section (Flash memory). 
When a function is called, the CPU uses the **Stack** (in RAM) to store:
1. The return address (where to jump back).
2. The arguments passed to the function.
3. Local variables inside the function.

**CRITICAL RULE:** Never pass large structs by value in embedded systems!
```cpp
struct SensorConfig { uint32_t data[64]; }; // 256 bytes

// BAD: Copies 256 bytes onto the stack! Wastes CPU time and RAM.
void init_sensor(SensorConfig config); 

// GOOD: Passes an 8-byte pointer/reference. Zero copy.
void init_sensor(const SensorConfig& config); 
```

## 6. Trade-offs

| Passing Method | Pros | Cons |
|----------------|------|------|
| **By Value** | Safe. Function cannot modify the original data. | Slow for large objects. Consumes stack memory. |
| **By Pointer** | Fast. C-compatible. Can pass `nullptr` if optional. | Requires `&` and `*` syntax. Risk of null-pointer dereference. |
| **By Reference** | Fast. Cleaner syntax than pointers. Cannot be null. | C++ only. Caller cannot easily see if variable will be modified. |
| **By Const Reference** | Fast. Safe (read-only). Clean syntax. | C++ only. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice parameter passing and memory analysis.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
