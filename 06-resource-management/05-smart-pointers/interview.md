# Interview Questions: Smart Pointers

## 1. What is the fundamental difference between `std::unique_ptr` and `std::shared_ptr`?
**Answer:** `std::unique_ptr` enforces strict exclusive ownership; exactly one pointer owns the heap memory at any given time, meaning it cannot be copied. It has zero memory or performance overhead. `std::shared_ptr` allows multiple pointers to own the same memory using a reference-counting mechanism. The memory is only freed when the last `shared_ptr` is destroyed. It incurs overhead because it must allocate a control block to track the reference count dynamically.

## 2. Why does `std::unique_ptr` have "Zero Overhead" compared to a raw pointer?
**Answer:** `std::unique_ptr` is a simple template class that contains nothing but the raw pointer itself. It has no extra fields, no counters, and no virtual functions. When compiled with standard optimizations (`-O2`), the compiler completely strips away the class abstraction and simply inlines the `new` instruction at the creation site and the `delete` instruction at the destruction site. The resulting machine code is completely indistinguishable from code written by a human perfectly managing a raw pointer.

## 3. What is the purpose of `std::make_unique`, and why should you use it instead of calling `new` directly?
**Answer:** `std::make_unique` was introduced in C++14 to cleanly construct an object and wrap it in a `unique_ptr` in a single step. It is preferred over `new` for two reasons:
1. **Safety:** If you write `foo(std::unique_ptr<T>(new T()), function_that_throws())`, the compiler might execute `new T()`, then execute `function_that_throws()`, and if an exception occurs, the pointer is never passed into the `unique_ptr` constructor, causing a memory leak. `std::make_unique` prevents this interleaving bug.
2. **Readability:** It removes the need to type the raw `new` keyword, aligning with modern C++'s goal of removing naked memory allocation from user code.
