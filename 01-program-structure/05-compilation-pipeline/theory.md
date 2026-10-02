# Compilation Pipeline

## 1. Concept
The C/C++ build process is not a single action. It is a pipeline of sequential tools that transform human-readable source code into machine-executable binary.

```text
Source Code (.cpp)
       ↓
┌──────────────────┐
│  1. PREPROCESSOR │  → Expand #include, #define, #ifdef
└──────┬───────────┘
       ↓
  Translation Unit
       ↓
┌──────────────────┐
│  2. COMPILER     │  → Parse C++ syntax → Generate Assembly
└──────┬───────────┘
       ↓
  Assembly (.s)
       ↓
┌──────────────────┐
│  3. ASSEMBLER    │  → Convert Assembly → Machine code (Object file)
└──────┬───────────┘
       ↓
  Object File (.o)
       ↓
┌──────────────────┐
│  4. LINKER       │  → Resolve symbols, combine objects, assign addresses
└──────┬───────────┘
       ↓
  Executable (ELF)
       ↓
┌──────────────────┐  (Embedded only step)
│  5. OBJCOPY      │  → Extract raw binary instructions from ELF
└──────┬───────────┘
       ↓
  Firmware (.bin / .hex)
```

## 2. Why
Splitting the process into stages provides massive efficiency. 
- If you have 100 `.cpp` files and change 1, you only need to run stages 1-3 for that single file. The resulting `.o` file is then sent to Stage 4 (the Linker) along with the other 99 pre-compiled `.o` files. This is known as **incremental compilation**.

## 3. Syntax (Command Line)

You can invoke each stage independently using compiler flags (like `gcc` or `g++`).

- **Preprocess only (`-E`)**: `g++ -E main.cpp -o main.i`
- **Compile to Assembly (`-S`)**: `g++ -S main.cpp -o main.s`
- **Assemble to Object File (`-c`)**: `g++ -c main.cpp -o main.o`
- **Link**: `g++ main.o math.o -o program.elf`

## 4. Example
*(See `examples/` for a bash script demonstrating these exact steps).*

**Compiler Error vs Linker Error:**
- *Compiler Error*: You forgot a semicolon, or called `my_func()` without declaring it. The compiler fails at Stage 2 because the Translation Unit is invalid C++.
- *Linker Error*: You declared `int my_func();` in a header, and you called it, so Stage 2 passes perfectly! But you never actually wrote the function body. Stage 4 fails with: `Undefined reference to my_func`.

## 5. Embedded usage
Embedded pipelines differ from Desktop pipelines in two major ways:
1. **The Linker Script (`.ld`)**: Desktop programs rely on the OS to decide where memory lives. Embedded systems require a custom Linker Script that explicitly tells the linker where Flash memory and RAM start (e.g., Flash at `0x08000000`).
2. **Binary Extraction (`objcopy`)**: Stage 4 outputs an `ELF` file. This file contains debugging symbols, section headers, and metadata. A microcontroller cannot execute an ELF file! We must use a tool like `arm-none-eabi-objcopy` to strip out all the metadata and extract the pure, raw 1s and 0s into a `.bin` or `.hex` file, which is then flashed to the MCU.

## 6. Trade-offs

| Build System | Concept | Trade-offs |
|--------------|---------|------------|
| **Makefiles** | Manually maps file dependencies to compiler stages. | Fast, but extremely complex to write and maintain for large projects. |
| **CMake** | Generates Makefiles automatically. | The industry standard, but has a steep learning curve. |

## 7. Exercises
Please proceed to the `exercises/` folder to test your knowledge of the pipeline stages.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
