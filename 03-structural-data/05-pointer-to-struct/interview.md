# Interview Questions: Pointer to Struct

## 1. What does the `->` operator actually do?
**Answer:** The arrow operator `->` is syntactic sugar. It performs two operations simultaneously: it dereferences a pointer to a struct (or class), and then it accesses a specific member of that struct. `ptr->member` is strictly equivalent to `(*ptr).member`.

## 2. Why is passing a struct to a function by pointer (or reference) critical for performance?
**Answer:** If you pass a struct by value, the entire memory footprint of that struct must be copied byte-by-byte onto the call stack. For a large struct (e.g., a 2KB network packet buffer), this copying process burns massive amounts of CPU cycles and risks overflowing the limited stack memory of a microcontroller. Passing a pointer only copies 4 bytes (the address itself), which is virtually instantaneous.

## 3. In modern C++, when should you pass a struct via pointer (`Struct*`) versus reference (`const Struct&`)?
**Answer:** You should default to passing by reference (`const Struct&` for read-only, `Struct&` for read-write). References use the cleaner dot (`.`) syntax and are guaranteed not to be null, eliminating the need for `nullptr` checks. You should only pass by pointer if the argument is explicitly optional (meaning the caller is allowed to pass `nullptr` to indicate "no data").
