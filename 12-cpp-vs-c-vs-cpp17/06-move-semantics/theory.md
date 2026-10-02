# Move Semantics (C++11)

## Khái niệm
Move semantics cho phép **chuyển quyền sở hữu** tài nguyên (bộ nhớ, file handle, peripheral) từ object này sang object khác mà **không copy dữ liệu**. Thay vì copy 1MB buffer, bạn chỉ di chuyển pointer (4 bytes).

## Code
```cpp
class DmaBuffer {
    uint8_t* data;
    size_t size;
public:
    // Constructor thông thường
    DmaBuffer(size_t n) : data(new uint8_t[n]), size(n) {}
    
    // Copy constructor — TỐN KÉM: copy toàn bộ buffer
    DmaBuffer(const DmaBuffer& other) : data(new uint8_t[other.size]), size(other.size) {
        memcpy(data, other.data, size);  // Copy 1MB data!
    }
    
    // Move constructor — RẺ: chỉ copy pointer
    DmaBuffer(DmaBuffer&& other) noexcept 
        : data(other.data), size(other.size) {
        other.data = nullptr;  // "Cướp" quyền sở hữu
        other.size = 0;
    }
    
    ~DmaBuffer() { delete[] data; }
};

// Sử dụng
DmaBuffer create_buffer() {
    DmaBuffer buf(1024);
    // fill buf...
    return buf;  // Move, KHÔNG copy! (Copy Elision / RVO)
}

DmaBuffer a(1024);
DmaBuffer b = std::move(a);  // Move: b sở hữu data, a trở thành empty
```

## Khi nào cần dùng / Bối cảnh
- **Trả object từ hàm** — compiler tự động move (Return Value Optimization).
- **Transfer ownership** — chuyển buffer từ Producer task sang Consumer task.
- **Container resize** — `std::vector` dùng move thay copy khi resize nếu move constructor là `noexcept`.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Tránh copy tốn kém (memcpy) | Phải viết move constructor/assignment |
| Object sau move ở trạng thái "valid but unspecified" | Dùng object sau std::move = bug |
| Zero-cost nếu compiler tối ưu (RVO/NRVO) | Syntax `&&` khó đọc cho người mới |

## Ở C có tồn tại không?
**Không.** C chỉ có `memcpy` (luôn copy) hoặc truyền pointer (nhưng phải quản lý ownership thủ công). C++ move semantics tự động hóa việc "transfer pointer + nullify source", và destructor đảm bảo không double-free.
