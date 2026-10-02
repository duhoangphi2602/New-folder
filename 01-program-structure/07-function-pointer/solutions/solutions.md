# Solutions: Function Pointers

## Solution 1: Typedef Translation
**Answer:**
```cpp
using math_op_t = float (*)(float, float);
```
**Benefit:** The modern syntax clearly separates the name being defined (`math_op_t`) from the type definition itself, making it much easier to read than the C-style `typedef` where the name is buried in the middle of the parentheses.

## Solution 2: The Null Pointer Crash
**Answer:** The system will crash (often throwing a Hard Fault on ARM Cortex-M). The CPU will attempt to jump to memory address `0x00000000` and execute whatever data happens to be there as an instruction.
**The Fix:** The driver author MUST check if the function pointer is `NULL` before executing it.
```c
void EXTI_IRQHandler(void) {
    if (user_callback != NULL) {
        user_callback();
    }
}
```

## Solution 3: Lambdas vs Function Pointers
**Answer:** It fails to compile because the lambda **captures state** (the variable `pin_number`).
In C++, a lambda can only decay (convert) into a raw C function pointer if it is **stateless** (it captures absolutely nothing: `[]`). 
A capturing lambda is essentially an anonymous class with member variables (the captured state). You cannot convert a class object with state into a single raw memory address of a function.
