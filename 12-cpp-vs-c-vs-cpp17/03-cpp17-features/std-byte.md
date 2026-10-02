# std::byte (C++17)

## Khái niệm
`std::byte` là kiểu dữ liệu đại diện cho **một byte thô** (8 bit). Khác với `uint8_t` (số nguyên) và `char` (ký tự), `std::byte` chỉ cho phép thao tác bitwise (AND, OR, XOR, SHIFT). Nó cấm hoàn toàn phép toán số học (`+`, `-`, `*`) — giúp phân biệt rõ ràng "dữ liệu byte thô" vs "số nguyên".

## Code
```cpp
#include <cstddef>

std::byte b{0xFF};

// Bitwise OK
std::byte masked = b & std::byte{0x0F};  // OK
std::byte shifted = b >> 4;               // OK

// Số học CẤM
// std::byte x = b + std::byte{1};  // ❌ Compile error!
// int y = b * 2;                    // ❌ Compile error!

// Chuyển đổi
uint8_t raw = std::to_integer<uint8_t>(b);  // byte → int
std::byte from_int = std::byte{42};          // int → byte

// Ứng dụng: Buffer truyền nhận rõ ràng
void send_packet(const std::byte* data, size_t len);  // Rõ ràng: đây là raw bytes
void send_text(const char* text, size_t len);           // Rõ ràng: đây là text
```

## Khi nào cần dùng
- **Protocol buffer** — raw byte stream, không phải text, không phải số.
- **Crypto/Hash** — thao tác bitwise trên dữ liệu nhị phân.
- **Phân biệt ý nghĩa** — `char` = text, `uint8_t` = số, `std::byte` = raw data.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Type safety: cấm phép toán số học vô nghĩa trên byte thô | Phải convert qua `std::to_integer` khi cần tính toán |
| Phân biệt rõ ý nghĩa trong API | Không phải mọi thư viện C đều tương thích |
| Zero overhead (cùng kích thước uint8_t) | Nhiều embedded codebase vẫn quen dùng uint8_t |

## Ở C có tồn tại không?
**Không.** C dùng `uint8_t` hoặc `unsigned char` cho tất cả: text, số, raw byte. Compiler không phân biệt và không cảnh báo nếu bạn vô tình cộng 2 byte của packet header lại với nhau.
