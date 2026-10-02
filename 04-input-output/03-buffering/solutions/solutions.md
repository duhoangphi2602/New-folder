# Solutions: I/O Buffering

## Solution 1: The Infinite Loop Trap
**Answer:** `printf` is line-buffered by default. Because the developer did not include a newline character (`\n`), the `printf` function kept storing the strings in the RAM buffer. It did not send them to the UART hardware. After 30 seconds, the RAM buffer completely filled up (e.g., hit 1024 bytes). When a buffer is full, it is forced to flush to make room, which is why a massive block of text appeared all at once.
**The Fix:** Add a newline to trigger a flush on every iteration: `printf("Val: %d\n", val);`

## Solution 2: `stdout` vs `stderr`
**Answer:** The fatal flaw is that `stdout` is line-buffered (and lacks a `\n` in this example). The message `"CRITICAL FAULT DETECTED!"` goes into RAM, and then the CPU immediately halts (`halt_cpu()`). The buffer is never flushed, and the developer never sees the error reason.
**The Fix:** Use `stderr`, which is guaranteed to be Unbuffered. It bypasses RAM and writes directly to the hardware instantly.
```cpp
fprintf(stderr, "CRITICAL FAULT DETECTED!");
// Or use fflush(stdout)
```
