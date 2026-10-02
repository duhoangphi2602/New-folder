# Solutions: Lambda

## Solution 1: The Dangling Capture
**Answer:** The program will exhibit **Undefined Behavior** (likely printing garbage or crashing). 
**Why:** The lambda captures `local_count` by reference `[&]`. However, `local_count` is a local variable on the stack of `create_counter()`. When `create_counter()` returns, the stack frame is destroyed. When `my_counter()` is called in `main`, it tries to access a memory address that no longer exists (a dangling reference).
**The Fix:** Capture by value `[local_count]`, and mark the lambda `mutable` if you need to modify the copied state.

## Solution 2: `mutable` Keyword
**Answer:**
```cpp
int strikes = 0;
auto play = [strikes]() mutable {
    strikes++;
    std::cout << "Strikes: " << strikes << "\n";
};
```
The `mutable` keyword removes the implicit `const` from the lambda's call operator, allowing it to modify the variables it captured by value (modifying its *own copies*, not the original `strikes` in the outer scope).

## Solution 3: Sorting with Lambdas
**Answer:**
```cpp
#include <algorithm>

struct Task { int priority; };

int main() {
    Task tasks[3] = {{3}, {1}, {2}};
    
    // Sort expects a function that returns true if arg1 < arg2
    std::sort(tasks, tasks + 3, [](const Task& a, const Task& b) {
        return a.priority < b.priority;
    });
}
```
This is where lambdas shine! The comparison logic is written exactly where it is needed, without having to define a separate `bool compare_tasks(...)` function elsewhere in the file.
