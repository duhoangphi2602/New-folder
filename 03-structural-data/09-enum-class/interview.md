# Interview Questions: Enum Class

## 1. What are the two main problems with C-style enums that C++11 `enum class` solves?
**Answer:** 
1. **Namespace Pollution:** C-style enums leak their constants into the surrounding scope. `enum class` encapsulates them, requiring the scope resolution operator (e.g., `Color::RED`).
2. **Lack of Type Safety:** C-style enums implicitly convert to integers, allowing meaningless arithmetic or accidental cross-enum comparisons. `enum class` strongly enforces its type and requires explicit `static_cast` for integer conversion.

## 2. How do you specify the underlying integer size of an `enum class`, and why is this useful in embedded systems?
**Answer:** You specify the underlying type by appending a colon and the type to the declaration: `enum class Mode : uint8_t { ... };`. This is critical in embedded systems because compilers often default enums to 4-byte integers. By forcing it to `uint8_t`, you reduce its memory footprint to 1 byte, saving RAM and allowing it to be safely embedded into packed structs and network protocols.

## 3. Can you compare two different `enum class` types using the `==` operator?
**Answer:** No. Because they are strictly typed, comparing `State::IDLE` to `Status::IDLE` will result in a compiler error. This prevents logical bugs where a developer accidentally compares the state of two completely unrelated state machines.
