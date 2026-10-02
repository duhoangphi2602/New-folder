# Interview Questions: Debug vs Release

## 1. Why does code often work perfectly in Debug mode, but crash randomly when compiled in Release mode? Give two common reasons.
**Answer:** Debug mode (`-O0`) generally hides bad coding practices. 
1. **Missing `volatile` keywords:** In Debug mode, the compiler executes every single line exactly as written, so checking a hardware flag in a `while` loop works perfectly. In Release mode (`-O3`), the compiler assumes variables don't change on their own and optimizes the check into an infinite loop.
2. **Uninitialized Variables:** In Debug mode, variables are often predictably laid out in memory, and sometimes automatically zeroed by the debugger environment. In Release mode, an uninitialized local variable (`int x;`) will contain random electrical garbage left over in RAM, causing unpredictable logic failures.

## 2. What does the `-g` compiler flag do, and does it increase the amount of Flash memory used on the microcontroller?
**Answer:** The `-g` flag instructs the compiler to generate DWARF Debugging Metadata and inject it into the final `.elf` file. This metadata maps raw machine code memory addresses back to human-readable source code files and line numbers, allowing a debugger (like GDB) to function. 
It does **NOT** increase the amount of Flash memory used on the microcontroller. The DWARF metadata is strictly placed in non-loadable sections of the `.elf` file. When you flash the firmware, the flasher tool only extracts the executable `.text` and `.data` sections, completely ignoring the debug metadata.

## 3. What is the danger of putting function calls inside `assert()` statements?
**Answer:** The `assert()` macro is designed purely for development safety checks. In standard C/C++, when a project is compiled in Release mode, the build system automatically injects the `-DNDEBUG` flag. The preprocessor responds to this flag by completely deleting the `assert()` macro and everything inside its parentheses. If you put a critical function call (like `assert(turn_on_motor() == OK)`) inside it, the motor will simply never turn on in production because the function call itself was deleted by the preprocessor.
