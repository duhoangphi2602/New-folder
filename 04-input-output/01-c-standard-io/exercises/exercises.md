# Exercises: C Standard I/O

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Hexadecimal Bug
A junior developer is trying to print the ID of a CAN bus packet, which is the number `15`. They want it to look like `0x0F`.
They write:
```cpp
uint8_t can_id = 15;
printf("Packet ID: 0x%X\n", can_id);
```
**Task:** This will print `0xF`. What exact format modifier must they add between the `%` and the `X` to make it print `0x0F`?

## Exercise 2: The Crash
The following code will crash (Segmentation Fault) instantly upon user input:
```cpp
int target_temp;
printf("Enter target temperature: ");
scanf("%d", target_temp);
```
**Task:** Identify the missing character that causes this crash, and explain *why* the standard C library requires it.
