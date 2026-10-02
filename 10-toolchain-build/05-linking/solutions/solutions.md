# Solutions: Linking

## Solution 1: The Library Paradox
**Answer:** The Linker processes files strictly from left to right. 
When it sees a static library (`.a`), it doesn't automatically link the entire library into your executable (that would waste massive amounts of Flash memory). Instead, it only extracts the specific `.o` files from the library that resolve *currently known* Undefined ('U') symbols.
- **Command A (Fails):** The Linker sees `libmath.a` first. At this point, the list of 'U' symbols is empty. It extracts nothing from the library. Then it processes `main.cpp`, which adds a 'U' symbol for `add()`. The Linker finishes, sees an unresolved 'U' symbol, and crashes.
- **Command B (Succeeds):** The Linker sees `main.cpp` first. It adds a 'U' symbol for `add()` to its list. Then it sees `libmath.a`. It searches the library, finds `add()`, extracts the object file, and perfectly resolves the symbol.

## Solution 2: Extern Variable
**Answer:**
1. **Stage 2 (Compiler):** The `extern` keyword acts as a promise. It tells the Compiler, "Do not allocate any memory for `sensor_id`, and do not throw an error when I use it. I promise you, this variable exists in another file." The Compiler creates a 'U' (Undefined) symbol in `main.o`'s Symbol Table and leaves a blank placeholder in the machine code.
2. **Stage 4 (Linker):** The Linker sees the 'U' symbol for `sensor_id` in `main.o`. It searches the other files and finds a 'T' (or 'D') Defined symbol for `sensor_id` in `sensor.o`. It resolves the link, calculates the absolute RAM address of `sensor_id`, and overwrites the blank placeholder in `main.o`'s machine code with that address.
