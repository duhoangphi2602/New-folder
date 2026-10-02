# std::string_view (C++17)

## Khái niệm
`std::string_view` là một **tham chiếu read-only** đến một chuỗi ký tự đã tồn tại (trong Flash, RAM, hoặc std::string). Nó KHÔNG copy dữ liệu, KHÔNG allocate heap. Nó chỉ lưu 2 thứ: con trỏ đến ký tự đầu tiên + độ dài.

## Code
```cpp
#include <string_view>

// TRƯỚC (C): truyền const char* — không biết độ dài, phải gọi strlen()
void log_c(const char* msg) {
    int len = strlen(msg);  // Duyệt toàn bộ chuỗi để đếm → O(n)
    uart_send(msg, len);
}

// SAU (C++17): truyền string_view — biết độ dài ngay lập tức
void log(std::string_view msg) {
    uart_send(msg.data(), msg.size());  // O(1), không cần strlen
}

// Sử dụng — hoạt động với MỌI loại chuỗi
log("Hello from Flash");           // const char* literal
std::string s = "Dynamic";
log(s);                             // std::string
log(std::string_view("Partial", 4)); // Chỉ lấy "Part"

// Substring KHÔNG copy
std::string_view full = "ERROR: Sensor timeout";
std::string_view prefix = full.substr(0, 5);   // "ERROR" — chỉ di chuyển pointer
std::string_view detail = full.substr(7);       // "Sensor timeout"
```

## Khi nào cần dùng / Bối cảnh
- **Logging/Debug** — truyền message string mà không copy.
- **Protocol parsing** — cắt packet thành header/payload bằng `substr()` mà không allocate.
- **Hàm nhận chuỗi** — thay thế `const char*` và `const std::string&` bằng 1 parameter duy nhất.
- **Embedded** — cực kỳ phù hợp vì zero-copy, zero-heap, O(1) length.

## Ưu/nhược điểm, so sánh

| | `const char*` (C) | `const std::string&` (C++) | `std::string_view` (C++17) |
|-|-------------------|---------------------------|---------------------------|
| Biết độ dài | ❌ Phải strlen() O(n) | ✅ .size() O(1) | ✅ .size() O(1) |
| Heap allocation | ❌ Không | ⚠️ std::string có thể heap | ❌ Không bao giờ |
| Nhận const char* | ✅ Trực tiếp | ⚠️ Tạo tạm std::string (heap!) | ✅ Trực tiếp |
| Nhận std::string | ⚠️ .c_str() | ✅ Trực tiếp | ✅ Trực tiếp |
| Substring | ❌ Phải copy hoặc thay đổi gốc | ⚠️ .substr() tạo string mới (heap) | ✅ .substr() zero-copy |
| Nguy hiểm | ⚠️ NULL pointer | ✅ An toàn | ⚠️ Dangling nếu source bị hủy |

## Ở C có tồn tại không?
**Không.** C chỉ có `const char*` (pointer đến mảng ký tự kết thúc bằng `\0`). Không biết độ dài trừ khi duyệt toàn bộ. Không có substring an toàn (phải dùng `strncpy` hoặc tự tính offset thủ công).
