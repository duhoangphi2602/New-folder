# Exercises: Bin and Hex

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Bootloader Size Limit
You are writing a custom bootloader for an IoT device over a cellular connection (where data is very expensive). The firmware is 100 KB in Flash memory. 
You run `objcopy` to generate `app.bin` and `app.hex`. 
`app.bin` is 100 KB on disk.
`app.hex` is 250 KB on disk.
**Task:** Why is the `.hex` file so much larger? Which file should you transmit over the cellular network to perform the OTA update, and why?

## Exercise 2: The Giant Gap
Your microcontroller has two distinct Flash banks:
Bank 1: `0x08000000` (10 KB of code)
Bank 2: `0x08100000` (10 KB of data)
Notice the massive empty space (nearly 1 Megabyte) between the two banks.
**Task:** If you use `objcopy -O binary` to create a single `app.bin` file covering both banks, roughly how large will the file be on your PC's hard drive? What happens if you use `objcopy -O ihex` instead?
