# Interview Questions: new and delete

## 1. What are the two fundamental differences between `malloc`/`free` and `new`/`delete`?
**Answer:** 
1. **Object Initialization:** `malloc` only allocates raw, uninitialized memory (bytes). `new` allocates memory AND automatically calls the object's constructor. Similarly, `delete` calls the destructor before freeing the memory.
2. **Type Safety:** `malloc` returns a `void*` which must be manually cast to the target type, leaving room for pointer mismatch errors. `new` is strictly typed and returns a pointer of the exact correct type.

## 2. What is "Placement New" and how is it used in Embedded Systems?
**Answer:** Placement New is a specialized syntax: `new (address) Type();`. It does not allocate memory from the Heap. Instead, it takes a pre-existing memory address (like a static byte array in `.bss`, or a specific hardware RAM region) and executes the Constructor directly on top of that memory. It allows embedded developers to bypass the dynamic allocator entirely while still utilizing C++ object-oriented constructors.

## 3. Why is mixing `new` with `free()`, or `malloc()` with `delete`, catastrophic?
**Answer:** The underlying allocator implementation for `new` might be completely different from the C library's `malloc`. Furthermore, `delete` expects the memory to have an active C++ object so it can call its Destructor. If you `malloc` memory and call `delete` on it, the C++ runtime will try to execute a Destructor on uninitialized garbage data. If you `new` an object and call `free()` on it, the memory will be returned to the OS, but the object's Destructor will never execute, leaking any internal resources (like opened files or mutex locks) held by that object.
