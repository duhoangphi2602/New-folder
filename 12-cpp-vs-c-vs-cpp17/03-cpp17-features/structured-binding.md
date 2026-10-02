# Structured Bindings (C++17)

## Khái niệm
Structured binding cho phép **"destructure"** một struct, pair, tuple, hoặc array thành các biến riêng lẻ trong một dòng khai báo. Tương tự JavaScript `const {x, y} = point;`.

## Code
```cpp
// TRƯỚC (C++11)
std::pair<bool, float> read_sensor();
auto result = read_sensor();
bool ok = result.first;     // .first / .second — khó đọc
float temp = result.second;

// SAU (C++17 Structured Binding)
auto [ok, temp] = read_sensor();  // Rõ ràng, sạch sẽ
if (ok) { log(temp); }

// Với struct
struct SensorData { uint8_t id; float temp; float humidity; };
SensorData data = {1, 25.5f, 60.0f};
auto [id, temp, hum] = data;  // id=1, temp=25.5, hum=60.0

// Với array
int arr[3] = {10, 20, 30};
auto [a, b, c] = arr;  // a=10, b=20, c=30

// Trong vòng lặp (map iteration)
std::map<int, std::string> errors = {{-1, "Timeout"}, {-2, "CRC Fail"}};
for (auto& [code, msg] : errors) {
    printf("Error %d: %s\n", code, msg.c_str());
}
```

## Khi nào cần dùng / Bối cảnh
- **Trả về nhiều giá trị** từ hàm (thay vì output pointer).
- **Iterate map/set** — đỡ phải viết `.first` / `.second`.
- **Destructure struct** — gán nhanh các field vào biến cục bộ.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Code ngắn gọn, dễ đọc | Tên biến phải đặt đúng thứ tự (theo field order) |
| Tránh `.first/.second` | Không hoạt động với tất cả custom class (cần public members hoặc get<>) |
| Hoạt động với struct, pair, tuple, array | Chỉ dùng với `auto` |

## Ở C có tồn tại không?
**Không.** C bắt buộc truy cập từng field thủ công: `data.id`, `data.temp`, `data.humidity`. Không có cú pháp destructuring.
