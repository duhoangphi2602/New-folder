# Interview Questions: C-Style Enums

## 1. What is the default underlying data type of a C-style enum?
**Answer:** In standard C and C++, the compiler is allowed to choose the underlying integral type based on the values defined in the enum, but it usually defaults to `int` (which is typically 4 bytes on 32-bit systems). This can sometimes waste memory if you only need the enum to represent values from 0 to 3. (Note: C++11 allows you to explicitly set the underlying type).

## 2. What is "Namespace Pollution" in the context of C-style enums?
**Answer:** Namespace pollution occurs because the enumerators (the names of the constants inside the enum) are injected into the scope where the enum itself is defined. This means you cannot have two different enums in the same scope that share a common state name like `OK`, `ERROR`, or `IDLE`, causing naming collisions and forcing developers to use long, redundant prefixes.

## 3. Why are C-style enums considered "not type-safe"?
**Answer:** Because they implicitly convert to integers. You can pass an enum into a function expecting an `int`, you can compare an enum to an arbitrary integer, and you can perform arithmetic on an enum (`MyEnum x = STATE_1; int y = x + 42;`). This allows developers to write mathematically nonsensical code that the compiler will accept without warnings.
