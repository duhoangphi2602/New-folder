# Solutions: Pointer Basics

## Solution 1: Follow the Pointers
**Answer:** `a = 20`, `b = 40`.
**Trace:**
1. `p1` points to `a`, `p2` points to `b`.
2. `*p1 = *p2;` → Dereference `p2` (reads 20), write it to what `p1` points to (`a`). `a` is now 20.
3. `*p2 = 30;` → Write 30 to what `p2` points to (`b`). `b` is now 30.
4. `p1 = p2;` → Reassign `p1` so it now points to `b`. (Both point to `b`).
5. `*p1 = 40;` → Write 40 to what `p1` points to (`b`). `b` is now 40.

## Solution 2: Type Sizes
**Answer:**
1. `sizeof(val_a)` = **1** (uint8_t is 1 byte).
2. `sizeof(val_b)` = **4** (uint32_t is 4 bytes).
3. `sizeof(ptr_a)` = **4** (On a 32-bit MCU, ALL pointers are 32 bits / 4 bytes).
4. `sizeof(ptr_b)` = **4** (Pointers are always the same size as the architecture's memory address width, regardless of what they point to).

## Solution 3: The Danger of Uninitialized Pointers
**Answer:** When executed, the program will likely crash with a segmentation fault (PC) or a Hard Fault (MCU). 
**Why:** `status_ptr` is an uninitialized local variable, meaning it takes on whatever garbage data happened to be on the stack memory at that moment. The code then dereferences it, forcing the CPU to attempt a write operation to that random memory address.
If you forget to initialize a normal `int`, you just do math with garbage data. If you forget to initialize a pointer, you write data to random parts of memory, which can corrupt other variables, overwrite code, or trigger hardware faults. ALWAYS initialize pointers to `nullptr`!
