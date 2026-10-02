# std::variant (C++17)

## Khái niệm
`std::variant<T1, T2, ...>` là **type-safe union**. Nó chứa chính xác MỘT giá trị tại một thời điểm, nhưng giá trị đó có thể thuộc bất kỳ kiểu nào trong danh sách. Khác với `union` trong C, `std::variant` biết chính xác kiểu nào đang active và cấm truy cập sai kiểu.

## Code
```cpp
#include <variant>

// State Machine cho một thiết bị IoT
struct Idle {};
struct Connecting { uint8_t retry_count; };
struct Connected  { uint32_t session_id; };
struct Error      { int error_code; };

using DeviceState = std::variant<Idle, Connecting, Connected, Error>;

DeviceState state = Idle{};

// std::visit — gọi hàm phù hợp dựa trên kiểu đang active
void process_state(DeviceState& s) {
    std::visit([](auto& current) {
        using T = std::decay_t<decltype(current)>;
        
        if constexpr (std::is_same_v<T, Idle>) {
            printf("Device idle, starting connection...\n");
        } else if constexpr (std::is_same_v<T, Connecting>) {
            printf("Connecting, retry %d...\n", current.retry_count);
        } else if constexpr (std::is_same_v<T, Connected>) {
            printf("Connected! Session: %u\n", current.session_id);
        } else if constexpr (std::is_same_v<T, Error>) {
            printf("Error: %d\n", current.error_code);
        }
    }, s);
}

// Chuyển state
state = Connecting{0};      // Chuyển sang Connecting
state = Connected{42};      // Chuyển sang Connected
state = Error{-1};           // Chuyển sang Error
```

## Khi nào cần dùng / Bối cảnh
- **State Machine** — thay thế enum + switch/case bằng type-safe states.
- **Protocol parser** — một message có thể là `CommandMsg`, `DataMsg`, hoặc `ErrorMsg`.
- **Heterogeneous container** — danh sách chứa nhiều kiểu dữ liệu khác nhau.
- **Thay thế inheritance** — khi số lượng type cố định và biết trước lúc compile.

## Ưu/nhược điểm, so sánh

| | `union` (C) | `enum` + `switch` | `std::variant` (C++17) |
|-|-------------|-------------------|------------------------|
| Type safety | ❌ Truy cập sai field = UB | ⚠️ Compiler không enforce | ✅ Compile-time error nếu sai |
| Biết kiểu đang active | ❌ Phải tự track | ✅ Bằng enum variable | ✅ Tự động (index()) |
| Hỗ trợ non-POD type | ❌ Không (C) | N/A | ✅ Có (string, vector...) |
| Visitor pattern | ❌ Không | ❌ Switch thủ công | ✅ std::visit |
| Heap allocation | ❌ Không | ❌ Không | ❌ Không |
| Kích thước | max(sizeof(members)) | sizeof(enum) + data | max(sizeof(types)) + tag |

## Ở C có tồn tại không?
**Không trực tiếp.** C có `union` nhưng nó hoàn toàn **unsafe**: 
```c
union Value { int i; float f; };
union Value v;
v.i = 42;
float x = v.f;  // Undefined Behavior! Đọc sai field.
```
C dev thường kết hợp `union` + `enum` tag thủ công (tagged union), nhưng compiler không kiểm tra — nếu quên update enum tag, bug âm thầm xảy ra.
