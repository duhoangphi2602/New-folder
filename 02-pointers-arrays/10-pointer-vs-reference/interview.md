# Interview Questions: Pointer vs Reference

## 1. What are the key differences between a pointer and a reference?
**Answer:** 
- A pointer can be uninitialized, can be null (`nullptr`), and can be reassigned to point to different addresses throughout its lifetime. 
- A reference must be initialized immediately, cannot be null, and is permanently bound to its original variable (cannot be re-seated). Pointers require special syntax (`*`, `&`, `->`), while references use standard variable syntax.

## 2. In an embedded C++ code review, you see a function `void process(SensorData* data)`. Under what specific condition is using a pointer here the *correct* design choice over a reference?
**Answer:** It is the correct choice ONLY if `data` is an **optional parameter**—meaning it is perfectly valid for the caller to pass `nullptr` because they don't have sensor data, and the `process` function internally checks `if(data != nullptr)` to handle that case. If the function *requires* valid sensor data to work, it should be changed to `void process(SensorData& data)` to enforce non-null safety at compile time.

## 3. Can you do pointer arithmetic on a reference?
**Answer:** No. A reference is not a memory address variable; it is a strict alias. If you do `ref++`, you are incrementing the *value* of the variable the reference is bound to, not changing a memory address. To step through memory blocks (like an array buffer), you must use pointers.
