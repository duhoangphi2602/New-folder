# Exercises: Nested Structs

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Anonymous Structs
In older C codebases, you will sometimes see structs defined *without a name* directly inside another struct.
```c
struct SensorNode {
    uint32_t id;
    struct {
        float x;
        float y;
    } location;
};
```
**Task:** How do you access the `x` variable of a `SensorNode` named `node`? What is the disadvantage of declaring `location` as an anonymous struct rather than defining a separate `Point2D` struct first?

## Exercise 2: Padding Cascades
Calculate the `sizeof` the outer struct `SystemState`. Draw the memory layout.
```cpp
struct Header {
    uint8_t version;
    uint32_t magic_word;
};

struct SystemState {
    uint8_t status_flag;
    Header  pkt_header;
};
```
*(Hint: Remember that the inner struct has its own internal padding, AND the outer struct must align the inner struct based on the inner struct's largest member).*
