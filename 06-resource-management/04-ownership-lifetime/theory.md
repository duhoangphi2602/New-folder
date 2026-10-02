# Ownership & Lifetime

## 1. Concept

**Lifetime:** The exact duration between an object's Constructor finishing and its Destructor starting. Once the lifetime ends, the object's memory is reclaimed by the system. Any pointer pointing to it becomes a Dangling Pointer.

**Ownership:** The responsibility of managing an object's lifetime. Whoever "owns" the object is the one who decides when it dies (when to call `delete`, or when it falls out of scope).

## 2. Why
In C, ownership is conveyed purely by verbal communication or comments.
```c
// Does this function take ownership of 'data'? Will it call free(data)?
// Or is it just reading it? I have to read the documentation to find out!
void process_data(uint8_t* data); 
```
In C++, ownership is explicitly embedded into the type system. If you try to violate ownership rules, the code will refuse to compile.

## 3. The 3 Types of Ownership

### 1. Exclusive Ownership (The standard in Bare-Metal)
Exactly one entity is responsible for the resource.
- **Local Variable:** The Stack exclusively owns it. It dies when the function ends.
- **`std::unique_ptr`:** Exclusively owns heap memory. It dies when the unique_ptr is destroyed.

### 2. Shared Ownership (Banned in critical Bare-Metal)
Multiple entities claim responsibility. The resource only dies when *every* owner is destroyed.
- **`std::shared_ptr`:** Uses a dynamic reference count. It is non-deterministic and incurs CPU overhead, so aerospace/automotive embedded systems avoid it entirely.

### 3. Non-Owning (Observing)
An entity wants to look at or modify the resource, but has absolutely no responsibility for cleaning it up.
- **Raw Pointers (`T*`)**: In modern C++, a raw pointer implies "I am just looking, I do not own this, I will never call `delete` on it."
- **References (`T&`)**: Same as a pointer, but mathematically guaranteed to not be `nullptr`.
- **`std::string_view`**: A non-owning window into a string.

## 4. Syntax (Communicating Intent)

```cpp
class Packet {};

// 1. I am taking EXCLUSIVE OWNERSHIP. You cannot use it after passing it to me!
void consume_packet(std::unique_ptr<Packet> p) {}

// 2. I am just LOOKING at it. I might modify it, but I won't destroy it.
void modify_packet(Packet* p) {}

// 3. I am just LOOKING at it, and I promise NOT to modify it.
void read_packet(const Packet& p) {}
```

## 5. Example
*(See `examples/` for a demonstration of Lifetime bugs and Ownership transfer).*

## 6. Embedded usage (The Lifetime Trap)
The most common embedded C++ bug occurs when passing asynchronous callbacks to RTOS tasks or Interrupts.
```cpp
void setup_timer() {
    Packet my_packet; // Local variable on the Stack.
    
    // We give the Timer a pointer to our packet.
    hardware_timer_set_callback([&my_packet]() {
        send_over_uart(my_packet); 
    });
} // my_packet is DESTROYED here! The Stack Frame is gone!

// ... 5 seconds later, the hardware timer fires. 
// It tries to read 'my_packet', which no longer exists. System crashes!
```
When crossing asynchronous boundaries (like Timers or RTOS Tasks), you must ensure the Lifetime of the data outlives the Execution of the callback (often by using `static` allocation or passing ownership via RTOS Queues).

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
