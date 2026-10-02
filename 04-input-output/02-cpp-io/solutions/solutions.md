# Solutions: C++ Standard I/O

## Solution 1: The Hex Trap
**Answer:** The last two lines will print `f` and `14`!
**Why:** In C++, manipulators like `std::hex` are **sticky**. Once you push `std::hex` into the stream, the stream remains in Hexadecimal mode forever, until you explicitly push `std::dec` to change it back. This is highly confusing to beginners because `printf` formatting (`%x`) only affects the single variable it is attached to.

## Solution 2: Newline vs Flush
**Answer:**
- `\n` simply inserts a newline character (`0x0A`) into the output buffer. The text might sit in RAM for a while until the buffer naturally fills up and flushes to the screen. This is very fast.
- `std::endl` inserts a newline character, AND it forcefully triggers a hardware `flush()`. Flushing tells the OS to immediately halt, take the buffer, and draw it to the console. 
**When to use `std::endl`:** Almost never in general logging loops, as it destroys performance. Only use it when you are about to crash (e.g., inside an `assert` or Hard Fault handler) and you absolutely must guarantee the final message escapes RAM and hits the serial terminal before the CPU dies.
