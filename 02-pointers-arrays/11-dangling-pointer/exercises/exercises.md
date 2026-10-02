# Exercises: Dangling Pointer

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Spot the Bug
Look at the following function. Is there a bug? If so, what is it, and how would you fix it without using dynamic memory (heap)?
```cpp
const char* get_status_message(int status_code) {
    char message[64];
    
    if (status_code == 0) {
        sprintf(message, "OK");
    } else {
        sprintf(message, "Error Code: %d", status_code);
    }
    
    return message;
}
```

## Exercise 2: `std::string_view` Trap
In C++17, `std::string_view` was introduced as a highly optimized, read-only reference to a string. It essentially contains a pointer to the string data and a length.
A developer writes this:
```cpp
std::string_view create_header() {
    std::string header = "HTTP/1.1 200 OK\r\n";
    return header;
}

int main() {
    std::cout << create_header();
}
```
**Task:** This code crashes or prints garbage at runtime. Based on your knowledge of dangling pointers, why does this happen?
