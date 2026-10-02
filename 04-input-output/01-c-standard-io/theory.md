# C Standard I/O (printf / scanf)

## 1. Concept
The `<cstdio>` library defines functions that allow a program to send formatted text to the "standard output" (usually the screen) and read formatted text from the "standard input" (usually the keyboard).

## 2. Why
In embedded systems, you don't have a screen. However, you can redirect the "standard output" to a UART Serial port. This allows you to plug a USB cable into your microcontroller and watch `printf` output appear in a terminal window on your laptop. It is the primary way embedded developers debug their code.

## 3. Syntax (printf Format Specifiers)

`printf` takes a format string containing placeholders, followed by the variables to insert into those placeholders.

| Specifier | Type | Example Output |
|-----------|------|----------------|
| `%d` / `%i`| Decimal Integer | `42`, `-15` |
| `%u` | Unsigned Integer | `42` (No negatives allowed) |
| `%x` / `%X`| Hexadecimal (Lowercase / Uppercase) | `2a`, `2A` |
| `%f` | Float / Double | `3.141590` |
| `%c` | Single Character | `'A'` |
| `%s` | String (Null-terminated `char*`) | `"Hello"` |
| `%p` | Pointer (Memory Address) | `0x20001400` |

### Modifiers
You can control padding and precision:
- `%04d`: Pad with zeroes to 4 digits (`0042`).
- `%.2f`: Print exactly 2 decimal places (`3.14`).
- `0x%08X`: Standard way to print 32-bit hardware registers (`0x40021004`).

## 4. Example
*(See `examples/` for runnable code demonstrating `printf` formatting and `scanf` usage).*

## 5. Embedded usage (The %f Danger)
In many embedded toolchains (like GCC for ARM), `printf` support for `%f` (floating-point numbers) is disabled by default!
**Why?** Because the code to convert a binary float into a human-readable ASCII decimal string is massive. Including `%f` support can instantly bloat your compiled firmware by 10 to 20 Kilobytes. On a chip with only 32KB of flash memory, printing a single float will consume your entire ROM.
*(If you need to print a float in embedded, it is often better to multiply it by 100, cast to an integer, and print it with a fake decimal point: `printf("%d.%02d", (int)val, (int)(val*100)%100);`)*

## 6. Trade-offs (scanf vs Parsing)
`scanf` is used to read input:
```cpp
int age;
scanf("%d", &age); // WARNING: Must pass the memory address!
```
While `printf` is universally loved, `scanf` is universally hated. It is notoriously fragile, easy to crash (if you forget the `&`), and vulnerable to buffer overflows if reading strings (`%s`). In professional embedded systems, developers almost never use `scanf`; instead, they read raw characters from a UART buffer and parse them manually using strict state machines.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
