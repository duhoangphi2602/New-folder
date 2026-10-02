# Interview Questions: Declaration vs Definition

## 1. What is the One Definition Rule (ODR)?
**Answer:** The ODR states that within a given translation unit, an entity (variable, function, class) can be declared multiple times but defined only once. Across the entire program, variables and non-inline functions with external linkage must have exactly one definition.

## 2. What is the difference between `int x;` and `extern int x;`?
**Answer:**
- `int x;` is a **definition**. It allocates memory for `x` (and initializes it to 0 if it's a global variable).
- `extern int x;` is a **declaration**. It tells the compiler that `x` exists and is of type `int`, but its memory is allocated somewhere else.

## 3. When would you use a forward declaration instead of `#include`?
**Answer:** You use a forward declaration (e.g., `class Sensor;`) in a header file when you only need to use the type as a pointer or reference. This avoids `#include`ing the full definition, which speeds up compile times and breaks circular dependencies between classes.

## 4. Can you use `sizeof` on a forward-declared type?
**Answer:** No. A forward declaration creates an "incomplete type". The compiler knows the type's name, but not its size or members. Therefore, `sizeof` will result in a compiler error.
