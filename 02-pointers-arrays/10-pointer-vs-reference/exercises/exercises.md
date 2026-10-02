# Exercises: Pointer vs Reference

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Reassignment Trap
A developer wants to write a function that changes what an external pointer points to (like in topic `06-pointer-to-pointer`). They try to use references to make the syntax cleaner.
```cpp
void change_target(int& my_ref, int& new_target) {
    my_ref = new_target;
}

int main() {
    int a = 10;
    int b = 99;
    int& ref_to_a = a;

    change_target(ref_to_a, b);
    
    // What is the value of 'a' now? 
    // Is 'ref_to_a' pointing to 'b' now?
}
```
**Task:** Answer the questions in the comments. Explain the behavior of the assignment operator `=` when used with references.

## Exercise 2: Null Reference (Undefined Behavior)
References are "guaranteed" not to be null. However, C++ allows you to do almost anything if you try hard enough.
```cpp
int* bad_ptr = nullptr;
int& bad_ref = *bad_ptr; 
```
**Task:** This code compiles perfectly. What happens at runtime? Why does the C++ standard classify this as Undefined Behavior?
