# Compilation

## 1. The Input
The Compiler receives the **Translation Unit** (the `.i` file). This file has no `#include` statements and no macros. It is pure, raw C++ code. The compiler processes this file completely in isolation. It does not know that other `.cpp` files exist in your project.

## 2. Lexical and Syntax Analysis (Parsing)
The compiler breaks down the text into "Tokens". 
`int x = 5;` becomes `[TYPE: int] [IDENTIFIER: x] [OPERATOR: =] [LITERAL: 5] [PUNCTUATION: ;]`.
If you write `int x = 5`, it throws a **Syntax Error** because the `[PUNCTUATION: ;]` token is missing.

It then builds an **Abstract Syntax Tree (AST)**, a logical map of what the code is trying to do.

## 3. Semantic Analysis (Type Checking)
The compiler checks if the AST makes logical C++ sense.
```cpp
void turn_on_led();
int main() {
    int x = turn_on_led(); // Semantic Error!
}
```
The syntax is perfect (semicolons are there). But the Semantics are broken. You are trying to assign a `void` return type to an `int` variable. The compiler throws a **Semantic Error**.

## 4. Optimization (The Optimizer)
If the code is semantically correct, the compiler attempts to optimize it (if you passed the `-O1`, `-O2`, or `-O3` flags).
- **Dead Code Elimination:** If you have an `if (false) { ... }` block, the compiler deletes it entirely.
- **Function Inlining:** If you call a tiny 1-line function, the compiler might delete the function call overhead and paste the math directly into `main()`.
- **Loop Unrolling:** The compiler might rewrite a `for` loop that runs 3 times into three sequential sets of instructions to avoid branching logic.

## 5. The Output: Assembly (`.s`)
Finally, the compiler translates the optimized AST into human-readable CPU Assembly instructions specific to your target architecture (e.g., ARM Cortex-M4 or x86_64).
The output is a `.s` file.

*Crucial Note:* The compiler does NOT generate machine code (1s and 0s). It only generates Assembly text.

## 6. Example
*(See `examples/` for a simulated translation from C++ to ARM Assembly).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
