# Object Files (.o)

## 1. What is an Object File?
An object file is a binary file (usually in the ELF format on Linux/ARM) that contains the compiled machine code for *exactly one* Translation Unit (`.cpp` file). 
If your project has `main.cpp`, `uart.cpp`, and `sensor.cpp`, the Assembler will generate `main.o`, `uart.o`, and `sensor.o`.

## 2. Why isn't it executable?
You cannot run `main.o` because it is incomplete. 
If `main.cpp` calls `uart_init()`, the Compiler translates that into a Branch Instruction (Jump). But the Compiler has no idea where `uart_init()` will eventually live in physical memory, because `uart.cpp` is compiled completely separately!
Therefore, inside `main.o`, the Branch Instruction is left blank (or filled with zeros). It is just a placeholder.

## 3. The Anatomy of an Object File
An Object file contains two main parts:
1. **The Sections (The Meat):** 
   - `.text`: The raw binary machine code.
   - `.data`: Initialized global variables.
   - `.bss`: Memory reservations for zero-initialized globals.
2. **The Symbol Table (The Index):**
   This is a dictionary attached to the file, used strictly by the Linker. It lists:
   - **Defined Symbols:** "I have a function called `main`. Its code starts at offset 0x00 within my `.text` section."
   - **Undefined Symbols:** "I am trying to jump to a function called `uart_init`. I don't have it. Someone else needs to provide it."

## 4. Inspecting Object Files (The `nm` tool)
You can use a command-line tool called `nm` (or `arm-none-eabi-nm`) to physically read the Symbol Table of an object file.
Output of `nm main.o`:
```text
00000000 T main
         U uart_init
```
- `T` means "Text" (Defined in this file).
- `U` means "Undefined" (Missing from this file).

## 5. Build Speed (The Hidden Superpower)
Why split the compilation into `.o` files instead of just compiling the whole project at once? **Speed.**
If you have 1,000 files and you edit a typo in `sensor.cpp`:
- The toolchain does NOT recompile all 1,000 files.
- It sees the timestamp on `sensor.cpp` is newer than `sensor.o`. 
- It recompiles *only* `sensor.cpp` into a new `sensor.o` (takes 0.1 seconds).
- It then tells the Linker to quickly stitch the 1 new `.o` file with the 999 old, cached `.o` files.

## 6. Example
*(See `examples/` for a simulated `nm` output).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
