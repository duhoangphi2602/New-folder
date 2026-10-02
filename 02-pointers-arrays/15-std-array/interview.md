# Interview Questions: std::array

## 1. What is the performance overhead of using `std::array` instead of a C-style array?
**Answer:** Zero. `std::array` is a zero-cost abstraction. It occupies exactly the same amount of memory (RAM) as a C-array, and its methods (like `operator[]` and `.size()`) are resolved at compile time or inlined by the compiler, meaning it executes the exact same CPU instructions as a raw C-array.

## 2. How does `std::array` solve the "array decay" problem?
**Answer:** A C-style array automatically decays into a pointer to its first element when passed to a function, losing its size information. `std::array` is implemented as a class/struct. When passed to a function (typically by reference, e.g., `const std::array<int, 5>&`), it does not decay; it retains its exact type and size, preventing out-of-bounds errors.

## 3. If you want to access an element in `std::array`, when should you use `[index]` vs `.at(index)`?
**Answer:** 
- Use `[index]` when performance is absolutely critical and you have already manually proven (or logically guaranteed) that the index is within bounds. It does not perform bounds checking.
- Use `.at(index)` when you are accepting an index from an untrusted source (like user input or parsed sensor data). It performs runtime bounds checking and safely throws a `std::out_of_range` exception (or halts) if the index is invalid.
