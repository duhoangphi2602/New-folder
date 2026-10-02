# The Volatile Keyword

## 1. The Compiler's Assumption
Compilers (like GCC or Clang) are designed to make your code run as fast as possible.
Consider this code:
```c
int status = 0;
while (status == 0) {
    // Wait for status to change
}
```
If you compile this with `-O3` (maximum optimization), the compiler analyzes the loop. It thinks: *"Inside the loop, `status` is never modified. Therefore, it is impossible for `status` to ever change. Why should I waste CPU cycles reading RAM?"*
The compiler rewrites your code into this Assembly:
```assembly
LDR R0, [RAM_Address]  // Read status ONCE
CMP R0, #0
BNE exit_loop
Infinite_Loop:
    B Infinite_Loop    // Trap forever! Never check RAM again!
```

## 2. The Embedded Reality
In embedded systems, variables *can* change invisibly to the main thread:
1. **Hardware Registers:** A GPIO input pin's voltage changes based on a physical button press.
2. **ISRs:** A hardware interrupt fires, pausing the `while` loop, changing the `status` variable in RAM, and returning.

Because the compiler deleted the RAM check, your code enters an infinite loop and crashes, even though your C code looks perfectly logical.

## 3. The `volatile` Solution
Adding the `volatile` keyword tells the compiler: *"Do not trust this variable. It can change at any moment due to hardware or interrupts. Do NOT cache it in a CPU register. You MUST read it from physical RAM every single time it is referenced in the code."*

```c
volatile int status = 0;
while (status == 0) {
    // Now the compiler will physically read RAM on every loop iteration
}
```

## 4. When to use `volatile`
You only use `volatile` in two situations:
1. **Memory-Mapped I/O (MMIO):** Pointers to hardware registers (e.g., `uint32_t volatile * const GPIOA_IDR = 0x40020010;`).
2. **ISR Shared Variables:** Global variables modified inside an Interrupt Service Routine and read by the main `while(1)` loop.

## 5. When NOT to use `volatile`
**`volatile` DOES NOT MAKE CODE THREAD-SAFE!**
If you have two RTOS tasks sharing a variable, `volatile` will not prevent Race Conditions or Deadlocks. It only solves Compiler caching, it does not solve CPU read-modify-write atomicity. (See the next topic).

## 6. Example
*(See `examples/` for simulated Assembly output demonstrating compiler optimization).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
