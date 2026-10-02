# The Volatile Keyword

## 1. Concept: The Over-Smart Compiler
Modern compilers (like GCC `-O3`) are incredibly aggressive at optimizing your code to make it faster. 
Suppose you write:
```c
bool button_pressed = false;

void main() {
    while(button_pressed == false) {
        // Wait for button...
    }
    turn_on_led();
}
```
The compiler analyzes `main()`. It sees a `while` loop that checks `button_pressed`. It looks *inside* the loop and notices that `button_pressed` is never changed. 
The compiler thinks: *"This programmer is stupid. The variable is false, and nothing inside the loop changes it to true. This is an infinite loop. I will optimize this by deleting the memory read entirely!"*
The compiler translates your code into assembly that effectively looks like: `while(true) {}`.

## 2. The ISR Reality
What the compiler *didn't* know is that you had a Hardware Interrupt!
```c
void Button_ISR() {
    button_pressed = true; // Changes the variable outside of main!
}
```
Because the compiler cannot predict when hardware interrupts fire, it assumes they don't exist. When the user presses the button, the ISR runs perfectly, and RAM is updated to `true`. But `main()` never checks RAM again! It is stuck in the compiler-optimized infinite loop.

## 3. The Solution: `volatile`
By adding the `volatile` keyword, you are giving a strict command to the compiler:
*"Do not optimize this variable. I guarantee that hardware (or an ISR) might change its value at any microsecond. You MUST physically read this variable from RAM every single time you check it."*

```c
// Correct!
volatile bool button_pressed = false; 

void main() {
    while(button_pressed == false) {
        // Will correctly read from RAM every loop iteration
    }
}
```

## 4. Hardware Registers
The `volatile` keyword isn't just for variables modified by ISRs. It is also required when reading raw memory-mapped hardware registers.
```c
// A hardware memory address that changes when a pin voltage changes
#define GPIO_PORT_A_IN (*(volatile uint32_t*)0x40020010)

void wait_for_pin() {
    while (GPIO_PORT_A_IN == 0); // Must be volatile!
}
```

## 5. Example
*(See `examples/` for a C++ simulation demonstrating compiler caching).*

## 6. Volatile vs Atomic
This is the most common interview failure.
- `volatile` tells the **Compiler** not to cache the variable. It does NOT prevent race conditions!
- `std::atomic` tells the **CPU Hardware** to lock the memory bus to prevent race conditions. (In C++, `std::atomic` implicitly includes the effects of `volatile`).
If an ISR and a Task both *write* to a counter, `volatile` is not enough. You must use `std::atomic`. If an ISR writes and a Task only *reads* a boolean, `volatile` is sufficient.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
