# Interview Questions: Ownership & Lifetime

## 1. What does the term "Undefined Behavior" mean in the context of Object Lifetimes?
**Answer:** When an object's lifetime ends (e.g., it falls out of scope, or `delete` is called), its memory is conceptually returned to the system. However, the physical RAM chip doesn't instantly erase the bits to zero. If a dangling pointer accesses that memory, it might read the old data perfectly (making the program *seem* like it works), or it might read garbage data written by a new function, or it might trigger a hardware memory protection fault. Because the outcome depends entirely on the compiler's mood and the hardware state, the C++ standard defines it as "Undefined Behavior"—the program is mathematically invalid.

## 2. In Modern C++, what is the semantic meaning of a raw pointer (`T*`)?
**Answer:** In legacy C, a raw pointer could mean anything: an array, an object you need to free, or just a variable you are observing. In Modern C++ (C++11 and onwards), the language introduced Smart Pointers for ownership. Therefore, if a developer writes a raw pointer `T*`, it has a strict, universally agreed-upon semantic meaning: "I am a Non-Owning Observer. I want to look at or modify the data, but I am absolutely not responsible for managing its lifetime or calling `delete`."

## 3. How do you pass an object to a function if you want to transfer ownership, versus just sharing access?
**Answer:** 
- **Transfer Ownership:** You pass a `std::unique_ptr` by value (using `std::move()`). The calling function loses access to the object, and the receiving function becomes the sole owner.
- **Share Access (No Ownership):** You pass a reference (`T&`) or a const reference (`const T&`). The calling function retains ownership, and the receiving function merely borrows the object for the duration of the function call.
