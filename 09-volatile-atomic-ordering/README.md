# 09 — Volatile, Atomic & Memory Ordering

This chapter addresses one of the most misunderstood topics in embedded C/C++. `volatile` and `std::atomic` solve **different problems**, and confusing them leads to bugs that are extremely difficult to debug.

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [volatile](./01-volatile/) | What it solves, what it does NOT solve |
| 02 | [volatile vs atomic](./02-volatile-vs-atomic/) | Side-by-side comparison |
| 03 | [std::atomic](./03-std-atomic/) | Atomic operations, lock-free flags |
| 04 | [Memory Ordering](./04-memory-ordering/) | relaxed → acquire → release → seq_cst |

## Key Rule

```text
volatile:
    Prevents compiler from optimizing away memory accesses.
    Used for: hardware registers (MMIO), memory modified by hardware/DMA.
    Does NOT provide: atomicity, thread synchronization, memory ordering.

std::atomic:
    Provides: atomic read-modify-write operations + memory ordering.
    Used for: shared state between tasks/threads, ISR-to-main communication.
    Does NOT prevent: compiler from caching non-atomic variables.
```
