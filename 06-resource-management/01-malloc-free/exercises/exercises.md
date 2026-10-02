# Exercises: malloc() and free()

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Sizeof Bug
A junior developer tries to allocate an array of 10 integers:
```c
int* arr = (int*)malloc(10);
arr[5] = 42;
```
**Task:** Why will line 2 likely crash the system or corrupt memory? How should line 1 be written?

## Exercise 2: The Hidden Leak
```c
void process_packet(uint8_t* data) {
    uint8_t* decompressed = (uint8_t*)malloc(1024);
    
    if (data[0] == 0xFF) {
        printf("Invalid packet header\n");
        return; 
    }
    
    // Decompress and process...
    
    free(decompressed);
}
```
**Task:** Identify the memory leak. How many bytes are leaked every time an invalid packet is received?
