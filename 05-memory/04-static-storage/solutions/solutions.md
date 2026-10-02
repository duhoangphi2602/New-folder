# Solutions: Static Storage Duration

## Solution 1: The Initialization Trap
**Answer:** The initialization `static int state = 0;` only happens exactly once during the entire execution of the program (specifically, during the C runtime startup before `main()` is even called). When the software reset occurs and `run_state_machine()` is called again, `state` will still be `1`. It does not reset to `0`, bypassing the initialization logic.
*(To fix this, the developer must provide an explicit `reset_state_machine()` function that manually sets `state = 0`)*.

## Solution 2: `static` vs `extern`
**Answer:** In C/C++, global variables have "External Linkage" by default, meaning they are merged into a single global namespace by the Linker. To prevent this, you change the declaration in `uart.cpp` to:
`static int uart_baud_rate = 9600;`
This gives the variable "Internal Linkage". The Linker will hide this variable so only functions inside `uart.cpp` can see it, allowing `main.cpp` to have its own independent variable without causing a naming collision.
