# Chapter 03 — Interview Questions

## Beginner

1. **What is a struct?**
   A composite type that groups related variables of different types under one name. In C++, `struct` and `class` differ only in default access (public vs private).

2. **What is `typedef`?**
   A keyword that creates an alias for an existing type. It doesn't create a new type. Common in embedded for callback types (`typedef void (*callback_t)(uint8_t)`), configuration structs, and fixed-width type names.

3. **What is `enum class` and how does it differ from `enum`?**
   `enum class` (C++11) provides scoped, strongly-typed enumerations. Unlike C-style `enum`, its values don't implicitly convert to integers and don't pollute the surrounding namespace.

## Intermediate

4. **Why is `sizeof(struct)` often larger than the sum of its fields?**
   The compiler inserts **padding** bytes to align members to their natural alignment boundaries. This ensures efficient CPU access but wastes memory.

5. **How can you minimize struct padding?**
   Order members from largest to smallest alignment requirement. Alternatively, use `#pragma pack(1)` — but beware of unaligned access on some architectures.

6. **What is a bit-field?**
   A struct member with a specified number of bits (`uint32_t enable : 1`). Bit-fields improve readability but their **layout is implementation-defined** — different compilers may order bits differently.

7. **When should you use bit-masks instead of bit-fields?**
   When accessing hardware registers or when the bit layout must be deterministic and portable. Bit-masks give you explicit control over which physical bits are manipulated.

## Advanced

8. **Why can't you directly `memcpy` a struct to a UART buffer for transmission?**
   Three problems: (1) Padding — extra bytes between members. (2) Endianness — byte order may differ between sender and receiver. (3) Alignment — struct layout is compiler/architecture dependent.

9. **What is endianness?**
   The order in which bytes of a multi-byte value are stored in memory. Little-endian: LSB first (ARM, x86). Big-endian: MSB first (network byte order, some DSPs). When serializing, you must explicitly choose a byte order.

10. **What is the difference between `typedef` and `using` in C++?**
    They are equivalent for simple type aliases. `using` (C++11) additionally supports template aliases, which `typedef` cannot do: `template<typename T> using Buffer = std::array<T, 256>;`

11. **What is type punning through a union?**
    Accessing a union member that was not the last one written. In C, this is well-defined. In C++, it is technically undefined behavior, though many compilers support it as an extension. In embedded, `memcpy` is the safe alternative.
