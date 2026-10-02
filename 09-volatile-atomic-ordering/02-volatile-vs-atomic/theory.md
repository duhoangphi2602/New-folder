# Volatile vs Atomic

## 1. The Core Misconception
- **`volatile`** solves a **Compiler** problem. It forces the Compiler to issue Read/Write Assembly instructions to physical RAM instead of caching data in registers.
- **`atomic`** solves a **CPU Hardware** problem. It prevents the CPU (or RTOS Scheduler, or Interrupts) from pausing a Read-Modify-Write operation halfway through.

## 2. Why `volatile` Fails at Thread-Safety
Consider a system tracking the number of times a sensor fires. You share a counter between an ISR and the Main Task.
```c
volatile int sensor_count = 0;

// Inside ISR
sensor_count++; 
```

Because it is `volatile`, the compiler correctly generates code that goes to RAM. But look at the Assembly for `sensor_count++`:
```assembly
LDR R0, [sensor_count]   // 1. Read value from RAM into R0
ADD R0, #1               // 2. Add 1 to R0
STR R0, [sensor_count]   // 3. Write R0 back to RAM
```

**The Race Condition:**
If `sensor_count` is 5.
1. The Main Task executes `LDR R0`, reading `5`.
2. Before the Main Task can execute `ADD`, an Interrupt fires!
3. The ISR executes `LDR` (reads 5), `ADD` (makes it 6), and `STR` (writes 6 to RAM). The ISR finishes.
4. The Main Task resumes. Its `R0` register still holds `5`. It executes `ADD` (makes it 6), and `STR` (writes 6 to RAM).
**Result:** Two increments happened, but the counter only went from 5 to 6. A count was lost. `volatile` did absolutely nothing to prevent this.

## 3. The `atomic` Solution
To fix this, the operation must be **Atomic** (indivisible). 
In C++11, you use `std::atomic<int> sensor_count;`. 
The compiler generates a special hardware instruction (like `LDREX`/`STREX` on ARM) that locks the memory bus, guaranteeing that the Read-Modify-Write cycle completes without any other thread or ISR being able to interfere.

## 4. The 4 Combinations
1. **Normal (`int x;`)**: Used for 99% of local variables.
2. **Volatile (`volatile int x;`)**: Used for Hardware MMIO Registers (e.g., reading a GPIO pin), or a simple 1-byte boolean flag written by an ISR and read by Main (where tearing is impossible).
3. **Atomic (`std::atomic<int> x;`)**: Used for data shared between multiple RTOS Tasks (no hardware/ISR involvement).
4. **Volatile Atomic (`volatile std::atomic<int> x;`)**: Very rare. Used for complex Read-Modify-Write data shared between an ISR and Main (e.g., the `sensor_count++` example).

## 5. Example
*(See `examples/` for a simulated demonstration of volatile failing to prevent a race condition).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
