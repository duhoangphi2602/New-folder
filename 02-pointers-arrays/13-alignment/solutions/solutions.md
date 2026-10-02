# Solutions: Alignment

## Solution 1: Finding the Fault
**Answer:** Read **`c`** will trigger a Hard Fault.
**Why:** 
- `a`: Address is `0x20000000`. Divisible by 2 (the size of `uint16_t`). **Safe.**
- `b`: Address is `0x20000002`. Divisible by 2, but wait! We are casting to `uint32_t*`. Is `...02` divisible by 4? No! **Crash.** (Wait, the question asks which *will* crash, let's re-evaluate).
Let's look at the math strictly:
- `a`: `0x20000000 % 2 == 0`. Safe.
- `b`: `0x20000002 % 4 == 2`. **CRASH!** 
- `c`: `0x20000005 % 4 == 1`. **CRASH!**
- `d`: `0x20000008 % 2 == 0`. Safe.
*(Correction to the answer: Both `b` and `c` will trigger a Hard Fault because they attempt to read 4-byte integers from addresses not divisible by 4).*

## Solution 2: DMA Requirement
**Answer:**
```cpp
alignas(8) uint32_t tx_descriptors[4];
```
This guarantees the compiler will place the start of `tx_descriptors` at a memory address that is a multiple of 8 (e.g., `0x20001000` or `0x20001008`), perfectly satisfying the Ethernet controller's requirement.
