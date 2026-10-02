# Solutions: Nested Structs

## Solution 1: Anonymous Structs
**Answer:** You access it via `node.location.x`. 
**Disadvantage:** Because the inner struct has no name (it is an anonymous type), you cannot reuse it anywhere else in your codebase. You cannot write a function like `void print_location(const ???& loc)` because there is no type name to put in the argument list. It violates the DRY (Don't Repeat Yourself) principle.

## Solution 2: Padding Cascades
**Answer:** The size of `SystemState` is **12 bytes**.
**Memory Map:**
- `status_flag`: 1 byte (Offset 0).
- **PADDING (Outer)**: 3 bytes (Offsets 1-3). *Why? Because `Header` contains a `uint32_t`, so `Header` has an alignment requirement of 4. `pkt_header` must start at an address divisible by 4.*
- `pkt_header.version`: 1 byte (Offset 4).
- **PADDING (Inner)**: 3 bytes (Offsets 5-7). *Injected internally inside `Header` to align `magic_word`.*
- `pkt_header.magic_word`: 4 bytes (Offsets 8-11).
