# Interview Questions: Namespace

## 1. What is a namespace and why is it used?
**Answer:** A namespace is a declarative region that provides a scope for the identifiers (functions, classes, variables) inside it. It is used to logically organize code and, most importantly, prevent naming collisions between different libraries or modules in a large project.

## 2. What is an anonymous namespace and how does it relate to `static`?
**Answer:** An anonymous namespace is a namespace without a name (`namespace { ... }`). Any function or variable declared inside it is given internal linkage, meaning it is completely invisible outside of that specific translation unit (`.cpp` file). It achieves the exact same encapsulation goal as the C-style `static` keyword applied to globals, but can also be used to hide entire classes or structs.

## 3. Why should you avoid `using namespace` in header files?
**Answer:** Header files are included by multiple `.cpp` files. If you put `using namespace std;` in a header, every single `.cpp` file that includes it is forced to have the entire `std` namespace dumped into its global scope. This completely defeats the purpose of namespaces and vastly increases the likelihood of naming collisions.
