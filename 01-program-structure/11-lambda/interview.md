# Interview Questions: Lambda

## 1. What is a lambda function?
**Answer:** An anonymous, inline function object. It allows developers to define a function exactly where it is used, which improves readability, especially when passing small callbacks to algorithms like `std::sort`.

## 2. What does `[&]` and `[=]` capture? What are the risks of `[&]`?
**Answer:**
- `[&]` captures all local variables used in the lambda by reference.
- `[=]` captures all local variables used in the lambda by value (creating copies).
**Risk:** Capturing by reference `[&]` is highly dangerous if the lambda outlives the scope where it was created (e.g., returning the lambda from a function, or storing it in an async queue). The local variables will be destroyed, leaving the lambda with dangling references.

## 3. Can you pass a C++ lambda to a C library expecting a function pointer (like `void (*cb)(void)`)?
**Answer:** Yes, but **only if the lambda captures absolutely nothing** (an empty capture list `[]`). A stateless lambda decays automatically into a standard C function pointer. If the lambda captures any state, it becomes a functor (a class object) and cannot be converted to a raw function pointer, causing a compile error.
