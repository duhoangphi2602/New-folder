# RAII (Resource Acquisition Is Initialization)

## 1. Concept
RAII is a terrible acronym for a brilliant idea. A better name would be **"Scope-Bound Resource Management"**.
The core idea is simple: 
1. When a C++ object is created on the **Stack**, its **Constructor** is automatically called. We use this to *Acquire* a resource (e.g., lock a hardware Mutex, open a UART port, turn on an LED).
2. When the function ends, the Stack Frame is destroyed. C++ guarantees the object's **Destructor** is automatically called. We use this to *Release* the resource (e.g., unlock the Mutex, disable the UART, turn off the LED).

## 2. Why
Humans are bad at remembering to clean up. Look at this classic C-style bug:
```c
void read_sensor() {
    hardware_mutex_lock();
    if (sensor_is_broken()) {
        return; // BUG! We returned without unlocking the Mutex! The system is now deadlocked.
    }
    hardware_mutex_unlock();
}
```
If this function has 5 different `return` paths, the developer must remember to type `hardware_mutex_unlock()` 5 times. RAII does it automatically, 0 times.

## 3. Syntax (The Lock Guard)

```cpp
class MutexGuard {
public:
    // Constructor: Acquires the resource
    MutexGuard() {
        hardware_mutex_lock();
    }
    
    // Destructor (indicated by ~): Releases the resource
    ~MutexGuard() {
        hardware_mutex_unlock();
    }
    
    // Delete copy constructors so we don't accidentally copy the guard!
    MutexGuard(const MutexGuard&) = delete;
    MutexGuard& operator=(const MutexGuard&) = delete;
};

void read_sensor() {
    MutexGuard guard; // Constructor is called here. Mutex is LOCKED.
    
    if (sensor_is_broken()) {
        return; // Destructor is automatically called here! Mutex is UNLOCKED!
    }
    
} // Destructor is automatically called here! Mutex is UNLOCKED!
```

## 4. Example
*(See `examples/` for runnable demonstrations of RAII used for UART initialization and Lock Guards).*

## 5. Embedded usage (Zero-Cost Abstraction)
Some embedded C developers fear RAII because they think creating objects and calling Constructors/Destructors adds overhead. 
In C++17, if you compile with standard optimizations (`-O2` or `-Os`), the compiler completely removes the `MutexGuard` object from existence. It simply injects the assembly instruction to lock the mutex at the start of the function, and injects the assembly instruction to unlock it before every possible `return` path. 
You get bulletproof safety for **zero CPU cycles** of overhead.

## 6. Trade-offs (Global Objects)
RAII relies heavily on the Stack (local variables). If you create an RAII object globally, its Constructor runs during boot (in the Startup Code) and its Destructor never runs. This is useless for temporary hardware locks. Therefore, RAII classes should almost exclusively be instantiated locally inside functions.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
