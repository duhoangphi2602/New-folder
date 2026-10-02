# Solutions: The Stack

## Solution 1: The Stack Frame
**Answer:** A Stack Frame contains:
1. **Local Variables:** Any variable declared inside the function (e.g., `int x = 5;`).
2. **Function Arguments:** The parameters passed into the function.
3. **The Return Address (Program Counter):** The exact memory address of the instruction that called the function, so the CPU knows exactly where to resume execution when the function hits `return`.

## Solution 2: Recursion
**Answer:** Recursion is banned because it causes unquantifiable **Stack Overflow**. Every single time a function calls itself, it pushes a brand-new Stack Frame (with a new set of local variables and a new return address) onto the Stack. If `factorial(5000)` is called, it will push 5000 frames onto the stack. Since microcontrollers have tiny stacks (often < 2KB), recursion will rapidly blow through the bottom of the stack, overwriting global variables and causing a catastrophic hardware crash. Bare-metal systems require deterministic memory bounds, which means you must use `for` or `while` loops instead.
