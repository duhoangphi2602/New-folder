# Solutions: Race Conditions

## Solution 1: Finding the Danger
**Answer:**
1. **Safe (Usually):** Writing an 8-bit or 32-bit aligned value is a single `STR` assembly instruction on a 32-bit ARM processor. It is inherently atomic.
2. **Race Condition:** Requires a read, modify, and write (3 instructions).
3. **Race Condition:** Requires loading the base address of `arr`, loading the value of `i`, adding them together to find the address, and then storing `5`. If an ISR modifies `i` halfway through, memory corruption occurs.
4. **Race Condition (Read-time):** If `x` is 5, the `if` check passes. But right before `do_something()` executes, a Context Switch happens and another task changes `x` to 10. `do_something()` will execute assuming `x` is 5, which is now false.

## Solution 2: The Silent Symptom
**Answer:** Race Conditions only cause corruption if a Context Switch happens at the *exact microscopic nanosecond* between the `LDR` and `STR` assembly instructions. If the Context Switch happens 1 nanosecond earlier or later, the code works perfectly. Therefore, you can run a test 100,000 times in the lab and it will pass every time. But when deployed in the real world, under specific temperature or network load conditions that slightly alter the timing, the crash will happen. This unpredictability makes them incredibly hard to capture with standard debugging tools.
