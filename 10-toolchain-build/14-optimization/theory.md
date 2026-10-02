# Optimization Flags

## 1. The Flags
When you invoke the compiler, you provide an Optimization level flag.
- **`-O0` (Zero Optimization):** The default. The compiler generates Assembly exactly as you wrote the C++ code. Fast to compile, great for step-by-step debugging, but produces massive, incredibly slow machine code.
- **`-O1` / `-O2`:** The compiler begins modifying your AST. It analyzes the code and restructures it to run faster without significantly increasing compile time.
- **`-O3` (Maximum Speed):** The compiler will do *anything* to make the code faster. It will aggressively unroll `for` loops, inline functions, and vectorize arrays. This often actually *increases* the final `.bin` file size because loop unrolling creates duplicate machine code instructions to save branching time.
- **`-Os` (Optimize for Size):** The Holy Grail for embedded systems. It enables all `-O2` optimizations that *do not* increase code size. It aims to generate the absolute smallest possible `.bin` file to fit into a tiny 32KB Flash chip.
- **`-Og` (Optimize for Debugging):** The modern standard for development. It optimizes the code reasonably well but strictly prevents the compiler from deleting variables or reordering code in a way that breaks your IDE debugger.

## 2. What the Compiler Can Delete
The C++ standard dictates the "As-If" rule: The compiler can radically alter your code, *as long as the observable behavior of the program remains identical*.
Observable behavior means:
- Reading/Writing to `volatile` variables.
- Calling external library functions.
- Performing I/O.

If you calculate the 10,000th digit of Pi, but you never `printf` it, and never assign it to a `volatile` variable, the compiler will completely delete the entire calculation algorithm at `-O2`, because the result is never observed.

## 3. The `volatile` Protection
As discussed in Chapter 09, `-O3` assumes that hardware registers and memory do not change on their own. If you write a `while` loop waiting for a hardware flag, `-O3` will delete the read operation and turn it into an infinite loop. `volatile` is the legal keyword to stop the optimizer from deleting those specific reads/writes.

## 4. Delay Loops
```cpp
void delay() {
    for (int i = 0; i < 1000000; i++) { }
}
```
At `-O0`, this creates a real delay. 
At `-O2`, the compiler realizes `i` has no observable side effects. It deletes the entire loop. 
Fix 1: Make `i` volatile: `for(volatile int i = 0; ...)`
Fix 2 (Better): Use a hardware timer.

## 5. Example
*(See `examples/` for a simulated demonstration of loop unrolling).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
