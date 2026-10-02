# Interview Questions: Memory Segments

## 1. What is the difference between the `.data` and `.bss` segments?
**Answer:** The `.data` segment contains global and static variables that are explicitly initialized to a non-zero value (e.g., `int x = 5;`). The `.bss` segment contains global and static variables that are uninitialized, or explicitly initialized to zero (e.g., `int y;`).

## 2. Why is the `.bss` section highly space-efficient in the final binary firmware file?
**Answer:** Because it only holds uninitialized or zero-initialized data, the compiler does not need to store the actual zeros in the `.bin` or `.hex` file (Flash memory). It only stores the start and end memory addresses of the `.bss` block. When the microcontroller boots, a startup script manually iterates through that memory range in RAM and writes zeros to it. Therefore, a 1-Megabyte `.bss` array takes up exactly 0 bytes in the Flash firmware file.

## 3. How does the `.data` section get its initial values after the microcontroller loses power?
**Answer:** Since RAM is volatile and loses power, the `.data` segment cannot permanently hold its values. The compiler stores a read-only copy of the `.data` initial values inside the Flash memory (usually right after the `.text` segment). During the microcontroller's boot sequence (inside `Reset_Handler`), before `main()` is ever called, a small assembly script physically copies these initial values from the Flash memory into the correct `.data` addresses in RAM.
