# const and Pointers

## 1. Concept
When using pointers, `const` can restrict two different actions:
1. Changing the **data** the pointer points to.
2. Changing the **memory address** the pointer holds.

## 2. Why
`const` correctness prevents accidental memory corruption at compile-time. If an API says it takes a `const uint8_t*`, you are mathematically guaranteed that the API will not alter your buffer.

## 3. Syntax (Read Right-to-Left)
To understand complex pointer declarations, **read them backwards (right-to-left)**.

### Case 1: Pointer to `const` Data
The pointer can point to different things, but the data itself cannot be modified through this pointer.
```cpp
const int* ptr1; // "ptr1 is a pointer to an int that is const"
int const* ptr2; // Identical to ptr1

ptr1 = &some_var; // OK (can change address)
// *ptr1 = 5;     // ERROR (cannot change data)
```

### Case 2: `const` Pointer to Mutable Data
The pointer must always point to the same address, but you can modify the data at that address.
```cpp
int* const ptr3 = &some_var; // "ptr3 is a const pointer to an int"

// ptr3 = &other_var; // ERROR (cannot change address)
*ptr3 = 5;            // OK (can change data)
```

### Case 3: `const` Pointer to `const` Data
Neither the address nor the data can be changed.
```cpp
const int* const ptr4 = &some_var; // "ptr4 is a const pointer to an int that is const"
```

## 4. Example
*(See `examples/` for runnable code demonstrating const correctness in APIs).*

## 5. Embedded usage (Hardware Registers)
In embedded systems, you use a `const` pointer when defining the fixed memory address of a hardware register. You don't want the pointer to accidentally point to a different address.

```cpp
// A pointer that MUST always point to 0x40020014, 
// but allows you to modify the hardware register's contents.
volatile uint32_t* const GPIOA_ODR = reinterpret_cast<volatile uint32_t*>(0x40020014);

*GPIOA_ODR = 0xFF; // OK: We are changing the hardware register
// GPIOA_ODR = nullptr; // ERROR: Cannot reassign the pointer itself
```

## 6. Trade-offs (C++ `const` vs C `#define`)

| Paradigm | Usage | Pros | Cons |
|----------|-------|------|------|
| **C `#define`** | `#define UART_ADDR 0x4000` | No memory used. Easy. | No type safety. Cannot pass as a pointer easily. |
| **C++ `const` pointer** | `uint32_t* const uart = ...` | Type-safe. Respects scope. | Historically took up RAM (though modern compilers optimize it out completely via `constexpr`). |

## 7. Exercises
Please proceed to the `exercises/` folder to practice reading declarations.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
