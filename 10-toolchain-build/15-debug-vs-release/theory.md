# Debug vs Release

## 1. What are Build Profiles?
A Build Profile is simply a predefined set of Compiler Flags. You configure your IDE (or CMake) to switch between them with a single click.

## 2. Debug Mode
Debug mode prioritizes developer visibility over execution speed and file size.
- **`-O0` or `-Og` (No Optimization):** The compiler generates code that exactly matches your C++ logic. Variables are preserved, loops are intact. When you step through the code in GDB, it moves linearly line-by-line.
- **`-g` (Generate Debug Symbols):** The compiler injects massive amounts of DWARF metadata into the `.elf` file. This is the reverse-dictionary that maps physical machine code addresses (e.g., `0x0800104A`) back to human-readable file paths and line numbers (`main.cpp:42`).
- **`-DDEBUG`:** A preprocessor macro injected so you can write `#ifdef DEBUG` blocks to enable heavy UART logging.

## 3. Release Mode
Release mode prioritizes absolute maximum speed and minimum footprint for the final deployed product.
- **`-O3` or `-Os` (Maximum Optimization):** The compiler aggressively deletes dead code, inlines functions, and restructures logic. Variables might be optimized out completely.
- **No `-g` flag:** The massive DWARF metadata is omitted. If the code crashes in the field, you only get raw hex addresses.
- **`-DNDEBUG` (No Debug):** This is a critical C++ standard macro. It completely disables all `assert()` statements in your code.

## 4. The `assert()` Trap
```cpp
void move_motor(int speed) {
    assert(speed <= 100); // Crash if speed > 100
    hardware_set_pwm(speed);
}
```
In Debug mode, if `speed` is 200, `assert()` halts the system and prints an error. You fix the bug.
In Release mode, the compiler defines `-DNDEBUG`. This automatically turns `assert()` into empty whitespace. The compiler completely deletes the safety check. If `speed` is 200 in the field, the motor spins out of control. 
**Never put critical business logic inside an `assert()`.**

## 5. The "It Works in Debug but Crashes in Release" Phenomenon
This is almost always caused by:
1. Missing `volatile` keywords. (Debug mode doesn't optimize, so the missing `volatile` wasn't noticed. Release mode deleted the hardware check).
2. Uninitialized variables (`int x;`). (Debug mode often sets them to 0. Release mode leaves them as random garbage).
3. Logic inside `assert()`. (e.g., `assert(turn_on_sensor() == true);` The sensor is never turned on in Release mode!).

## 6. Example
*(See `examples/` for simulated command lines for both profiles).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
