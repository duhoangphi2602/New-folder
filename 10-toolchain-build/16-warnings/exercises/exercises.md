# Exercises: Warnings

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Ignored Parameter
You are implementing an Interrupt Service Routine (ISR) callback function required by the HAL library:
```cpp
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    // We only have one UART, so we don't need to check which 'huart' fired.
    process_incoming_data();
}
```
You compile with `-Wall -Wextra -Werror`. The build immediately crashes, complaining that the parameter `huart` is declared but never used. 
**Task:** You are not allowed to change the function signature (it is mandated by the HAL). You are not allowed to remove `-Werror` (it is mandated by your company). How can you modify the code inside the function to explicitly tell the C++ compiler, "Yes, I know I'm not using this, please ignore it"?

## Exercise 2: Signed vs Unsigned
A junior developer writes this timeout loop:
```cpp
uint32_t timeout = 5000;
int counter = 0;
while (counter < timeout) {
    counter++;
}
```
**Task:** If compiled with `-Wall -Wextra`, the compiler will throw a `sign-compare` warning. Explain exactly why comparing a signed `int` to an unsigned `uint32_t` is mathematically dangerous and worthy of a compiler warning.
