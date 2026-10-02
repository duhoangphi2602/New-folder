# 03 — Structural Data

This chapter covers the C/C++ mechanisms for organizing and representing complex data. This includes structures, unions, enumerations, type aliases, and the critical embedded topics of bit-fields, bit-masks, padding, alignment, endianness, and packet serialization.

## Prerequisites
- Chapter 02 (Pointers & Arrays)

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [struct](./01-struct/) | Basic struct, member access |
| 02 | [struct Memory Layout](./02-struct-memory-layout/) | `sizeof`, field order, compiler layout |
| 03 | [Padding & Alignment](./03-padding-alignment/) | Why `sizeof` ≠ sum of fields |
| 04 | [Nested struct](./04-nested-struct/) | Struct containing struct |
| 05 | [Pointer to struct](./05-pointer-to-struct/) | `->` operator, passing by pointer |
| 06 | [typedef](./06-typedef/) | Type aliases, function pointer typedef |
| 07 | [Fixed-width Integers](./07-fixed-width-integers/) | `<cstdint>`, `uint8_t`, `uint32_t` |
| 08 | [enum](./08-enum/) | C-style enumerations |
| 09 | [enum class](./09-enum-class/) | Scoped enums, underlying type |
| 10 | [union](./10-union/) | Shared storage, type punning |
| 11 | [bit-field](./11-bit-field/) | Struct bit-fields, compiler dependency |
| 12 | [bit-field vs bit-mask](./12-bit-field-vs-bit-mask/) | When to use which approach |
| 13 | [Endianness](./13-endianness/) | Little-endian vs big-endian |
| 14 | [Packet Data Representation](./14-packet-data-representation/) | Serialization, protocol design |

## Learning Outcomes
After completing this chapter, you should be able to:
- Predict the size of a struct including padding
- Use `typedef` and `using` for type aliases and callback types
- Choose between `enum` and `enum class` with justification
- Explain why bit-field layout is compiler-dependent
- Choose between bit-fields and bit-masks for register access
- Serialize struct data correctly considering endianness and padding
