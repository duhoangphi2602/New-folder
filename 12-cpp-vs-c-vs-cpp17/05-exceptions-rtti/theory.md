# Exceptions & RTTI trong Embedded

## Khái niệm
- **Exception** (`throw`/`catch`): Cơ chế xử lý lỗi bằng cách "ném" lỗi lên call stack. Khi `throw`, runtime phải "unwind" stack — tìm ngược từng frame để gọi destructor cho mọi object local.
- **RTTI** (Run-Time Type Information): `dynamic_cast<>` và `typeid()`. Cho phép kiểm tra kiểu của object lúc runtime.

## Code
```cpp
// Exception
try {
    auto data = i2c_read(0x48);
    if (!data) throw std::runtime_error("I2C read failed");
} catch (const std::exception& e) {
    log_error(e.what());
}

// RTTI
class Sensor { virtual ~Sensor() = default; };
class TempSensor : public Sensor {};
class HumSensor : public Sensor {};

void process(Sensor* s) {
    if (auto* temp = dynamic_cast<TempSensor*>(s)) {
        // Kiểm tra kiểu lúc runtime
    }
}
```

## Vì sao bị TẮT trong Embedded?

| Vấn đề | Chi tiết |
|--------|---------|
| **Binary size** | Exception tables (`.eh_frame`, `.gcc_except_table`) thêm 10–30% kích thước binary |
| **Latency** | Stack unwinding là non-deterministic — không biết mất bao lâu |
| **Heap** | `throw` có thể allocate heap (cho exception object) |
| **RTTI size** | `typeid` lưu tên class dưới dạng string literal trong Flash |

## Cách tắt
```
# GCC / arm-none-eabi-g++
-fno-exceptions -fno-rtti
```
Sau khi tắt, `throw`, `try`, `catch`, `dynamic_cast`, `typeid` đều bị cấm (compile error).

## Thay thế bằng gì?
| Exception | Thay thế C++17 |
|-----------|---------------|
| `throw` error | `return std::optional<T>` hoặc `return std::variant<Result, Error>` |
| `try/catch` | `if (auto val = func(); val.has_value()) { ... }` |
| `dynamic_cast` | `std::variant` + `std::visit` hoặc `if constexpr` |

## Ở C có tồn tại không?
**Không.** C không có exception hay RTTI. C dùng return code + `errno`, đơn giản nhưng dễ bỏ qua.

## Interview
Xem `interview.md`.
