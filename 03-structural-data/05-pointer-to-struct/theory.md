# Pointer to Struct

## 1. Concept
A pointer to a struct holds the memory address of the very first byte of that struct. Using this pointer, you can access or modify the internal members of the struct remotely, without having to copy the entire struct.

## 2. Why
If you have a 1024-byte struct representing an LCD frame buffer, and you pass it to a function `void draw_screen(LcdBuffer buf)`, the CPU must copy all 1024 bytes onto the stack. If you pass it via a pointer `void draw_screen(LcdBuffer* buf_ptr)`, the CPU only copies 4 bytes (the address). This is millions of times faster.

## 3. Syntax (The Arrow Operator `->`)

When you have a regular struct variable, you use the dot (`.`) to access members.
When you have a *pointer* to a struct, you must dereference the pointer *before* you can use the dot.

```cpp
struct Sensor { int id; float temp; };
Sensor s1 = {1, 25.5f};
Sensor* p = &s1; // Pointer to the struct

// 1. The Clunky Way (Dereference, then dot)
// Parentheses are REQUIRED because '.' has higher precedence than '*'
(*p).id = 2; 

// 2. The Arrow Operator (The Standard Way)
// '->' is syntactic sugar that does the exact same thing as '(*).'
p->id = 2; 
p->temp = 30.0f;
```

## 4. Example
*(See `examples/` for runnable code demonstrating performance optimization via pointers).*

## 5. Embedded usage (Hardware Register Pointers)
This is the most critical use of `->` in all of embedded systems programming. Hardware vendors provide structs that describe the layout of a peripheral. They then define a pointer to that struct, hardcoded to the peripheral's base memory address.

```c
// Struct defining the registers of a GPIO port
typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
} GPIO_TypeDef;

// The vendor casts the physical memory address (e.g. 0x48000000 for GPIOA) 
// into a pointer to the struct.
#define GPIOA ((GPIO_TypeDef *) 0x48000000)

// You use the arrow operator to write directly to hardware!
void turn_on_led() {
    GPIOA->ODR |= (1 << 5); // Sets bit 5 of the Output Data Register
}
```

## 6. Trade-offs (Pointer vs Reference)

In C, passing a pointer is the *only* way to avoid copying a struct.
In C++, you should prefer passing a **Reference** (`const Sensor&`). References allow you to use the cleaner dot (`.`) operator instead of the arrow (`->`), and they are inherently null-safe.

| Paradigm | Function Signature | Member Access | Safety |
|----------|--------------------|---------------|--------|
| **C-Style Pointer** | `void process(Sensor* s)` | `s->temp` | Must check for `nullptr`. |
| **C++ Reference** | `void process(Sensor& s)` | `s.temp` | Cannot be null. Safer. |

*Note: For hardware mapping like `GPIOA`, you must use pointers, because you are mapping to a hardcoded physical address.*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
