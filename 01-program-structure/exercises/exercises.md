# Chapter 01 — Exercises

## Exercise 1: Header/Source Separation

Create a module with:
- A header file `calculator.h` declaring `int add(int, int)` and `int multiply(int, int)`.
- A source file `calculator.cpp` implementing both functions.
- A `main.cpp` that uses both functions and prints the results.

Compile manually:
```bash
g++ -std=c++17 main.cpp calculator.cpp -o calculator
```

**Goal**: Understand the header/source/link workflow.

---

## Exercise 2: `static` vs `extern`

Create two files:
- `counter.cpp` with a function `increment()` that uses a `static` local variable to count calls.
- `main.cpp` that calls `increment()` three times.

Then answer:
1. Where in memory does the `static` variable live?
2. What happens if you replace `static` with a regular local variable?

---

## Exercise 3: Function Pointers

Write a program with:
1. Three functions: `void op_add(int, int)`, `void op_sub(int, int)`, `void op_mul(int, int)`, each printing the result.
2. An array of function pointers (dispatch table).
3. A loop that calls each function with `(10, 3)`.

**Goal**: Understand function pointer arrays / dispatch tables.

---

## Exercise 4: Preprocessor Analysis

Given this code:
```cpp
#define SQUARE(x) x * x
int result = SQUARE(2 + 3);
```

1. What does the preprocessor expand `SQUARE(2 + 3)` to?
2. What is the actual value of `result`? (Hint: it's NOT 25)
3. Fix the macro.
4. Write a `constexpr` replacement.

---

## Exercise 5: Startup Sequence

Without looking at the theory, write down (from memory) the steps that happen between power-on and `main()` on an ARM Cortex-M MCU. Compare your answer with `13-embedded-startup/theory.md`.

---

## Exercise 6: Lambda

Write a program that:
1. Creates a `std::array<int, 10>` with values 1–10.
2. Uses `std::count_if` with a lambda to count how many values are greater than a threshold variable.
3. First use a capture-by-value lambda, then a capture-by-reference lambda. Explain the difference.
