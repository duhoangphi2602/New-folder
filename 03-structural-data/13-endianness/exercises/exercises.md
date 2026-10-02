# Exercises: Endianness

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Memory Layout
You have the 16-bit unsigned integer `0xABCD`. You save it to a memory address starting at `0x2000`.
1. If the CPU is **Little Endian**, what is the exact byte value stored at `0x2000`, and what is stored at `0x2001`?
2. If the CPU is **Big Endian**, what is the exact byte value stored at `0x2000`, and what is stored at `0x2001`?

## Exercise 2: `htons`
In socket programming, developers use the function `htons()` (Host To Network Short) to prepare a 16-bit integer (short) for transmission over the internet.
**Task:** Write the manual bit-shifting logic for `htons()`. It takes a `uint16_t` and swaps its two bytes.
*(Hint: Use bitwise AND `&` with bit-shifts `<<` and `>>`).*
