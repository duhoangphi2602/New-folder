# Symbols

## 1. The Final Symbol Table
In previous topics, we saw that `.o` Object files have Symbol Tables with "Undefined" ('U') symbols. 
When the Linker finishes its job, it generates the final `.elf` file. 
If the build succeeded, **the final ELF file should have ZERO 'U' (Undefined) symbols** (unless dynamically linked, which is rare in bare-metal embedded). Every symbol now has a fixed, absolute physical address.

## 2. Using `nm` on the ELF file
Running `arm-none-eabi-nm firmware.elf` outputs the entire memory map of your variables and functions.
The output format is: `[Memory Address] [Type] [Symbol Name]`
Example:
`08000100 T main`
`20000004 D system_state`
`20000008 B rx_buffer`

### Common Symbol Types:
- **T (Text):** Function code (Lives in Flash: `0x08000000+`).
- **R (Read-Only):** `const` variables (Lives in Flash).
- **D (Data):** Initialized global variables (Lives in RAM: `0x20000000+`).
- **B (BSS):** Zero-initialized global variables (Lives in RAM).

## 3. Debugging Hard Faults
If your microcontroller crashes and the registers show the Program Counter (PC) was at `0x0800014C`:
You run `nm firmware.elf | sort`. 
You look at the output:
`08000100 T main`
`08000140 T process_sensor_data`
`08000180 T turn_on_led`
Because `0x0800014C` falls between `140` and `180`, you know with 100% certainty that the crash happened inside the `process_sensor_data` function!

## 4. Name Mangling (C++)
In C, a function `int add(int a, int b)` appears in the Symbol Table exactly as `add`.
In C++, you can overload functions. You can have `int add(int, int)` and `float add(float, float)`. 
How does the Linker tell them apart? The C++ compiler **Mangles** the name.
It secretly renames them to something like `_Z3addii` (add, int, int) and `_Z3addff` (add, float, float).
If you want to read C++ symbols clearly, use the `-C` (demangle) flag: `nm -C firmware.elf`.

## 5. Example
*(See `examples/` for a simulated C++ name mangling output).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
