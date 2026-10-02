# Interview Questions: Struct Basics

## 1. What is the fundamental difference between `struct` and `class` in C++?
**Answer:** In C++, the *only* functional difference is default visibility. Members of a `struct` are `public` by default, whereas members of a `class` are `private` by default. Aside from that, they are identical (a struct can have constructors, methods, and inheritance). By convention, however, we use `struct` for passive data containers (Plain Old Data) and `class` for complex objects with encapsulated logic.

## 2. In C, you often see `typedef struct { int x; } Point;`. In C++, you just see `struct Point { int x; };`. Why the difference?
**Answer:** In C, defining `struct Point` only introduces the tag `Point` into the `struct` namespace, requiring you to type `struct Point my_pt;` every time. The `typedef` is a hack to allow you to just type `Point my_pt;`. In C++, the language automatically injects the struct name into the global scope as a first-class type, so the `typedef` is completely unnecessary.

## 3. What does C++20 Designated Initialization provide over C++11 Uniform Initialization?
**Answer:** C++11 uniform initialization (`Point p{10, 20};`) is highly dependent on the strict order of members in the struct. If someone adds a variable to the middle of the struct later, the code might still compile but assign the wrong values. C++20 Designated Initialization (`Point p{.x=10, .y=20};`) explicitly names the members being initialized, making the code self-documenting and immune to accidental ordering bugs.
