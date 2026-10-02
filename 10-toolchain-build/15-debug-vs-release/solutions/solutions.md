# Solutions: Debug vs Release

## Solution 1: The Disappearing Function Call
**Answer:** The crash was caused by the **`-DNDEBUG`** compiler flag, which is automatically injected in Release mode. 
This flag tells the C/C++ standard library to completely disable the `assert()` macro. It turns the macro into empty whitespace.
Because the developer put the *actual execution* of `init_i2c()` inside the `assert()` parenthesis, the compiler completely deleted the function call from the Release build! The `init_i2c()` function was never executed. When the `while(1)` loop tried to `read_sensor()`, the hardware was uninitialized, causing an immediate Hard Fault.
**The Fix:** Never put operational logic inside an assert. 
```cpp
bool success = init_i2c();
assert(success == true); // Safe. If deleted, init_i2c() still ran.
```

## Solution 2: Stepping Through Chaos
**Answer:** The erratic behavior is caused by the `-Os` (or `-O2`/`-O3`) optimization flag. 
In Release mode, the Compiler aggressively restructures the Abstract Syntax Tree. It deletes dead variables, inlines functions, and reorders instructions to maximize CPU pipeline efficiency (the "As-If" rule). The linear top-to-bottom flow of your C++ code no longer matches the physical flow of the Machine Code. The debugger gets deeply confused trying to map the optimized machine code back to the original source lines.
**The Fix:** You must recompile the firmware using the Debug profile (specifically using the `-O0` or `-Og` optimization flags). This forces the compiler to generate linear assembly that perfectly matches your source code.
