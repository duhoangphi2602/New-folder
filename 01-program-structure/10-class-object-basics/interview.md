# Interview Questions: Class & Object Basics

## 1. What is the difference between a `struct` and a `class` in C++?
**Answer:** Technically, there is only one difference: a `struct` defaults to `public` inheritance and `public` members, while a `class` defaults to `private` inheritance and `private` members. Culturally, C++ developers use `struct` for plain data objects (PODs) and `class` when encapsulation, constructors, or complex logic are involved.

## 2. What is a constructor initializer list and why should you use it?
**Answer:** The initializer list (the part after the colon in a constructor: `MyClass() : var1(0) {}`) initializes member variables *before* the constructor body executes. If you instead assign variables inside the constructor body, the compiler first default-constructs them, and then overwrites them. For complex types, using the initializer list is much more efficient, and it is strictly required for initializing `const` or reference members.

## 3. What does the `explicit` keyword do on a constructor?
**Answer:** It prevents the compiler from using that constructor for implicit type conversions. For example, if you have `explicit Sensor(int id);`, you cannot do `Sensor s = 5;`. You must explicitly call `Sensor s(5);`. This prevents subtle bugs where an integer is accidentally passed into a function expecting a `Sensor` object.

## 4. What does `const` mean at the end of a member function declaration?
**Answer:** It means the function promises not to modify any member variables of the class. It is required if you want to call that function on an object that has been passed by `const reference`.
