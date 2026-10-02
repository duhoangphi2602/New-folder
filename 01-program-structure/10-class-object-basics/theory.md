# Class & Object Basics

## 1. Concept
A **class** is a blueprint for a user-defined type that bundles data (member variables) and behavior (member functions) together. An **object** is a specific instance of that class allocated in memory.

In C++, `struct` and `class` are essentially the exact same thing. The only difference is the default access level:
- `struct` defaults to `public`.
- `class` defaults to `private`.

## 2. Why
Encapsulation. By making data `private` and only exposing specific `public` functions, you prevent other developers from accidentally corrupting the internal state of your hardware driver or data structure.

## 3. Syntax

```cpp
class Sensor {
public: // Anyone can call these
    // Constructor (called when object is created)
    explicit Sensor(int id) : id_(id), is_active_(false) {}

    void turn_on() {
        is_active_ = true;
    }

    // const member function (promises not to modify data)
    int get_id() const { return id_; }

private: // Only member functions can access these
    int id_;
    bool is_active_;
};
```

## 4. Example
*(See `examples/` for runnable code demonstrating a basic class).*

## 5. Embedded usage (Zero-Overhead Abstraction)
A common fear among C developers is that C++ classes are "heavy" or "slow". 
This is completely false for standard classes (without `virtual` functions).
- A class with 2 `uint32_t` variables takes exactly 8 bytes of RAM, identical to a C `struct`.
- Calling `sensor.turn_on()` is translated by the compiler into a standard C function call: `turn_on(&sensor)`. 
There is **zero runtime overhead** for using classes, constructors, or member functions compared to C structs.

**Convention in embedded C++:**
- Use `struct` for Plain Old Data (POD) (e.g., protocol packets, register maps).
- Use `class` for types with behavior, invariants, and encapsulation (e.g., drivers).

## 6. Trade-offs

| Paradigm | Pros | Cons |
|----------|------|------|
| **C++ Classes** | Strong encapsulation. Automatic initialization (Constructors). | Can encourage overly deep hierarchies if misused. |
| **C Structs + Functions** | Extremely simple. Highly portable. | Prone to misuse (e.g., forgetting to call `init()`). No data protection. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice building a class.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
