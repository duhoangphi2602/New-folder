# Interview Questions: typedef and using

## 1. What is the fundamental difference between `typedef` and `using`?
**Answer:** Functionally, they do exactly the same thing for basic types: they create a synonym for an existing type. The differences are syntactic and feature-based. `using` provides a much cleaner, left-to-right assignment syntax (`Alias = Type`), which makes aliasing function pointers much easier to read. Furthermore, `using` supports C++ templates (e.g., `template<typename T> using MapList = std::map<int, T>;`), whereas `typedef` does not support templates at all.

## 2. Does a type alias create a new distinct type for the compiler?
**Answer:** No. It is strictly an alias (a synonym). If you write `using Distance = int;` and `using Weight = int;`, the compiler treats both of them simply as `int`. You can accidentally pass a `Distance` variable into a function expecting a `Weight` variable, and the compiler will not warn you, because they are the exact same underlying type. (To create a strictly new type, you would need to wrap the `int` inside a `struct` or `class`).
