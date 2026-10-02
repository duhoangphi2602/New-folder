# Exercises: std::string_view

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: C API Compatibility
You are using a legacy C library to print text to an LCD screen. The API looks like this:
```c
void lcd_print(const char* null_terminated_text);
```
You have parsed an incoming message using `std::string_view` and you want to print just the first 5 characters (the word "HELLO") from a larger string `"HELLO WORLD"`.
```cpp
std::string_view message = "HELLO WORLD";
std::string_view first_word = message.substr(0, 5);

lcd_print(first_word.data()); // <--- Is this safe?
```
**Task:** Is passing `.data()` here safe? What will actually be printed to the LCD screen? Why?

## Exercise 2: Pass by Value vs Reference
A junior developer reviews your code and leaves this comment:
*"You passed `std::string_view` by value! You should pass it by `const std::string_view&` to avoid copying the whole string!"*
**Task:** Explain to the junior developer why they are incorrect, and what is actually being copied when you pass a `string_view` by value.
