# Solutions: C Standard I/O

## Solution 1: The Hexadecimal Bug
**Answer:** They must use `%02X`.
- The `2` tells `printf` to enforce a minimum width of 2 characters.
- The `0` tells `printf` to pad the empty space with zeroes instead of spaces.
Fixed code: `printf("Packet ID: 0x%02X\n", can_id);`

## Solution 2: The Crash
**Answer:** The missing character is the ampersand (`&`): `scanf("%d", &target_temp);`.
**Why:** `scanf` is a C function, which means it cannot pass variables "by reference" using C++ syntax (`int&`). It must pass them "by pointer". `scanf` needs to know the exact memory address of `target_temp` so it can write the user's input directly into that RAM location. If you pass `target_temp` without the `&`, you pass the *value* of the uninitialized variable (random garbage data) to `scanf`. `scanf` assumes this garbage number is a memory address and attempts to write to it, causing an immediate memory access violation (crash).
