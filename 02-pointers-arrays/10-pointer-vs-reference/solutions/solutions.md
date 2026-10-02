# Solutions: Pointer vs Reference

## Solution 1: The Reassignment Trap
**Answer:** The value of `a` is now **`99`**. `ref_to_a` is **NOT** pointing to `b`. It is still permanently bound to `a`.
**Why:** In C++, once a reference is initialized, it is bound to that original variable for its entire lifetime. It cannot be "reseated" to alias a different variable. When you use the assignment operator `my_ref = new_target;`, you are assigning the *value* of `new_target` (99) to the original variable that `my_ref` aliases (`a`). 
*(Note: To actually change what a pointer points to using C++ references, you must pass a Pointer Reference: `void change_target(int*& ptr, int* new_target)`).*

## Solution 2: Null Reference
**Answer:** At runtime, creating `bad_ref` might silently succeed, but the moment you try to use it (e.g., `bad_ref = 5;`), the program will crash with a segmentation fault/hard fault because it attempts to write to memory address `0x0`.
**Why it's UB:** The C++ standard explicitly states that dereferencing a null pointer is Undefined Behavior. By doing `*bad_ptr`, you violate the standard before the reference is even fully formed. The compiler is allowed to assume references are *never* null, so it might heavily optimize away any null-checks you attempt to write for `&bad_ref == nullptr`, leading to catastrophic execution flow.
