# Exercises: Ownership & Lifetime

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Communicating Intent
You are writing a C++ driver for an I2C Sensor. You have three functions. Based on their signatures, state exactly what type of ownership/interaction they represent:
1. `void set_config(const SensorConfig& config);`
2. `void process_raw_data(uint8_t* raw_buffer);`
3. `void attach_logger(std::unique_ptr<Logger> system_logger);`

## Exercise 2: The RTOS Trap
You create a FreeRTOS task inside a helper function:
```cpp
void boot_system() {
    int max_retries = 5;
    
    // Create an RTOS task, pass a pointer to max_retries as an argument
    xTaskCreate(NetworkTask, "Net", 256, &max_retries, 1, NULL);
}
```
**Task:** Why is passing `&max_retries` into the RTOS task a catastrophic Lifetime bug? How would you fix it without using the Heap?
