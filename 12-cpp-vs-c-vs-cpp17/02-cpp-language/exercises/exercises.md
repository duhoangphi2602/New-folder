# Exercises: C++ Language

## Exercise 1
Bạn có một C driver cho sensor nhiệt độ:
```c
int temp_sensor_init(uint8_t i2c_addr);
int temp_sensor_read(float* out_temp);
void temp_sensor_deinit(void);
```
Caller phải nhớ gọi `deinit()` khi xong, nếu không sẽ leak tài nguyên I2C bus.
**Task:** Viết một C++ wrapper class `TempSensor` sử dụng RAII. Constructor gọi `init()`, destructor gọi `deinit()`. Đảm bảo rằng ngay cả khi hàm `read()` throw exception hoặc return sớm, I2C bus vẫn được giải phóng.

## Exercise 2
So sánh assembly output (giả định) của 2 đoạn code sau khi compile với `-O2`:
```c
// C version
void led_on(void) { *(volatile uint32_t*)0x40020014 |= (1 << 5); }
```
```cpp
// C++ version
class Led {
    volatile uint32_t* odr;
    uint8_t pin;
public:
    Led(uint32_t base, uint8_t p) : odr(reinterpret_cast<volatile uint32_t*>(base + 0x14)), pin(p) {}
    void on() { *odr |= (1 << pin); }
};
Led led(0x40020000, 5);
led.on();
```
**Task:** Hai đoạn code này có sinh ra assembly giống nhau không? Giải thích khái niệm "zero-cost abstraction".
