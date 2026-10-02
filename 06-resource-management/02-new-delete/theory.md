# new and delete

## 1. Concept
In C++, `new` does two things:
1. It requests memory from the Heap (just like `malloc`).
2. It immediately calls the object's **Constructor** to initialize that memory.

`delete` does two things:
1. It immediately calls the object's **Destructor** to clean up its internal state.
2. It returns the memory to the Heap (just like `free`).

## 2. Why
```cpp
class Sensor {
public:
    Sensor() { std::cout << "Sensor Initialized!\n"; }
};

// C-Style (WRONG)
Sensor* s1 = (Sensor*)malloc(sizeof(Sensor)); 
// ^ The memory exists, but the Constructor NEVER ran! The object is broken.

// C++-Style (RIGHT)
Sensor* s2 = new Sensor(); 
// ^ The memory exists, AND the Constructor ran perfectly.
```

## 3. Syntax (Single Objects vs Arrays)
If you allocate an array, you MUST use the array version of delete (`delete[]`).

```cpp
void create_objects() {
    // 1. Single Object
    int* single = new int(42); 
    delete single; 
    
    // 2. Array of Objects
    int* array = new int[100]; 
    delete[] array; // CRITICAL: Notice the [] !
}
```

## 4. Example
*(See `examples/` for demonstrations of constructors firing via `new`).*

## 5. Embedded usage (Placement New)
In heavily constrained embedded systems, you might have a dedicated memory region (e.g., Fast SRAM) where you want to place a specific C++ object, but you don't want to use the generic Heap.
C++ allows a specialized syntax called **Placement New**: `new (memory_address) ObjectType();`
This does *not* allocate memory; it simply executes the Constructor directly on top of a specific hardware memory address that you provide!

## 6. Trade-offs (The Modern C++ Rule)
Because `new` and `delete` are manual, they still cause Memory Leaks and Dangling Pointers just like C. 
The modern C++ rule (since C++11) is: **Never use raw `new` and `delete`.**
Instead, use Smart Pointers (`std::unique_ptr` and `std::make_unique`), which automatically call `new` and `delete` for you, ensuring mathematical safety. We cover this in Topic 05.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
