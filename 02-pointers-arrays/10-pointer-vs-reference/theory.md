# Pointer vs Reference

## 1. Concept
- A **Pointer** is a distinct variable that stores a memory address. 
- A **Reference** is an alias (an alternative name) for an existing variable. 

Under the hood, C++ compilers usually implement references exactly like pointers (using memory addresses), but the C++ language enforces strict safety rules on references that it does not enforce on pointers.

## 2. Why
Pointers are incredibly powerful, but very dangerous (can be uninitialized, can be null, can be advanced out of bounds). References were introduced in C++ to provide the performance benefits of "pass-by-address" without the syntax clutter of `*` and `&` and without the risk of null-dereferencing.

## 3. Syntax and Key Differences

| Feature | Pointer (`int* p`) | Reference (`int& r`) |
|---------|--------------------|----------------------|
| **Initialization** | Can be uninitialized (garbage). | MUST be initialized when created. |
| **Nullability** | Can be `nullptr`. | Cannot be null (unless forced via UB). |
| **Reassignment** | Can point to different objects later. | Cannot be re-seated (bound for life). |
| **Syntax** | Requires `*` to dereference. | Used exactly like a normal variable. |
| **Memory Address** | Has its own address (`&p`). | Shares address with original (`&r == &var`). |

```cpp
int x = 10;
int y = 20;

// Pointer
int* p = &x;
p = &y;       // OK: Reassigned to point to y
*p = 30;      // y is now 30

// Reference
int& r = x;   // MUST be initialized
// &r = y;    // COMPILE ERROR: Cannot rebind a reference
r = y;        // This assigns the VALUE of y to x. x is now 30.
```

## 4. Example
*(See `examples/` for runnable code demonstrating parameter passing strategies).*

## 5. Embedded usage (When to use which)

**When to use References (`Type&` or `const Type&`):**
Use references for function parameters when:
1. The argument is mandatory (cannot be missing/null).
2. You want to avoid the overhead of copying a large struct (e.g., `ConfigStruct`).
```cpp
// Fast, zero-copy, guarantees the struct exists
void process_config(const ConfigStruct& config); 
```

**When to use Pointers (`Type*`):**
1. The argument is **optional** (you can pass `nullptr` if you don't need it).
2. You are interfacing with legacy C HAL APIs (which don't support references).
3. You need to iterate through a buffer (you can't do `reference++`).
4. You are accessing memory-mapped hardware registers.
```cpp
void uart_send(const uint8_t* buffer, size_t len) {
    if (buffer == nullptr) return; // Optional argument handling
    // ...
}
```

## 6. Trade-offs

| Structure | Pros | Cons |
|-----------|------|------|
| **References** | Inherently null-safe. Clean syntax (no `->` or `*`). | Cannot be re-assigned. Cannot represent "no object". |
| **Pointers** | Ultimate flexibility. Can iterate (pointer arithmetic). Can be `nullptr`. | Highly dangerous. Requires manual null checks. Clunky syntax. |

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
