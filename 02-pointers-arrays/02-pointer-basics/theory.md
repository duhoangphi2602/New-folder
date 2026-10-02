# Pointer Basics

## 1. Concept
A **pointer** is a variable that stores the **memory address** of another variable. On a 32-bit microcontroller (like an STM32), a pointer is a 32-bit value. On a 64-bit desktop CPU, a pointer is a 64-bit value.

## 2. Why
Pointers allow you to:
1. Pass massive amounts of data to functions efficiently (by passing an 8-byte address instead of a 10,000-byte copy of a struct).
2. Modify variables outside of your local scope.
3. Access hardware registers at hardcoded memory locations.

## 3. Syntax (Reference and Dereference)

```cpp
int  value = 42;

// 1. Declaration & Reference
// The type is 'int*'. We assign it the address of 'value' using '&'.
int* ptr = &value;

// 2. Dereference
// We use '*' to "follow" the pointer to the address it holds, and read the data.
int copy = *ptr;      // copy is now 42

// 3. Write through pointer
// We "follow" the pointer and overwrite the memory at that address.
*ptr = 100;           // value is now 100
```

### Visual Model
```text
ptr ──────────→ [ 42 ]
(0x20001004)     (0x20001000)
                 ↑ value lives here
```

## 4. Example
*(See `examples/` for runnable code demonstrating basic pointer operations and `nullptr`).*

## 5. Embedded usage (Pointer Types & Hardware Access)
The *type* of a pointer is incredibly important. An address is just a number, but the pointer type tells the compiler **how many bytes to read/write** when you dereference it.

```cpp
std::uint8_t*  p8;    // Dereferencing reads/writes 1 byte
std::uint32_t* p32;   // Dereferencing reads/writes 4 bytes
```
This is critical because hardware registers are often specifically 32 bits wide. If you try to write to a 32-bit register using a `uint8_t*`, you will only write to 1/4th of the register, potentially corrupting the hardware state!

**Hardware Access Pattern:**
```cpp
// Accessing a hardware register at a known address
volatile std::uint32_t* gpio_output = reinterpret_cast<volatile std::uint32_t*>(0x40020014);

*gpio_output |= (1u << 5);  // Set bit 5
```

## 6. Trade-offs (Pointers vs References)

| Feature | Pointer (`*`) | Reference (`&`) |
|---------|---------------|-----------------|
| **Can be Reassigned?** | Yes, can point to a new variable later. | No, bound to the original variable forever. |
| **Can be Null?** | Yes (`nullptr`). | No (must always refer to a valid object). |
| **Syntax** | Requires `*` and `&` to use. | Clean syntax (looks like a normal variable). |

## 7. Exercises
Please proceed to the `exercises/` folder to practice reading and writing with pointers.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
