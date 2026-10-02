# Interview: STL Strategy cho Embedded

## 1. Vì sao `std::vector` bị coi là nguy hiểm trong Embedded?
**Answer:** `std::vector` sử dụng heap allocation (`new`/`delete`) nội bộ. Khi `push_back` vượt capacity, vector tự động allocate buffer mới lớn hơn (thường gấp đôi), copy dữ liệu cũ sang, rồi free buffer cũ. Trong Embedded với 20KB RAM, hành vi resize bất ngờ này gây heap fragmentation (RAM bị chia nhỏ thành các mảnh không liên tục), dẫn đến `malloc` thất bại sau vài giờ chạy. Thay thế bằng `std::array<T, N>` (compile-time fixed size, stack-allocated).

## 2. `std::string_view` và `std::string` khác nhau thế nào về mặt bộ nhớ?
**Answer:** `std::string` sở hữu dữ liệu chuỗi, allocate heap khi chuỗi dài hơn SSO buffer (~15 bytes). Mọi thao tác copy/substring đều tạo heap allocation mới. `std::string_view` KHÔNG sở hữu dữ liệu — chỉ lưu pointer + length (8 bytes trên 32-bit). Substring chỉ tạo string_view mới trỏ vào vùng nhớ gốc (zero-copy). Trong Embedded nơi heap bị cấm, `string_view` là giải pháp duy nhất cho xử lý chuỗi an toàn.

## 3. Trong một dự án Embedded C++17, bạn sẽ configure compiler flags như thế nào?
**Answer:**
```
arm-none-eabi-g++ -std=c++17 -fno-exceptions -fno-rtti -Os -Wall -Werror
```
- `-std=c++17`: Bật C++17 features.
- `-fno-exceptions`: Tắt exception → giảm binary 10-30%, buộc dùng `std::optional`.
- `-fno-rtti`: Tắt RTTI → giảm binary, cấm `dynamic_cast`.
- `-Os`: Tối ưu kích thước binary (quan trọng cho Flash giới hạn).
- `-Wall -Werror`: Mọi warning thành error → bắt bug sớm.
