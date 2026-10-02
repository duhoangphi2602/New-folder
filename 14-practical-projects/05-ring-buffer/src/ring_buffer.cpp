/*
 * Language: C++17
 * Target: PC (Simulation)
 * Build: g++ -std=c++17 ring_buffer.cpp -o ring_buffer_test
 * Run: ./ring_buffer_test
 * Expected output:
 *   Push 10: OK
 *   Push 20: OK
 *   Push 30: OK
 *   Push 40: OK (buffer full after this)
 *   Push 50: FULL
 *   Pop: 10
 *   Pop: 20
 *   Pop: 30
 *   Pop: 40
 *   Pop: EMPTY
 *   Size: 0, Empty: true
 * What to learn: How to implement a zero-allocation ring buffer using
 *                templates and std::array — a core embedded pattern.
 */

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <optional>

template<typename T, std::size_t N>
class RingBuffer {
    static_assert(N > 0, "Buffer size must be greater than 0");

public:
    bool push(const T& value) {
        const auto next = (head_ + 1) % (N + 1);
        if (next == tail_) {
            return false;  // Full
        }
        buffer_[head_] = value;
        head_ = next;
        return true;
    }

    std::optional<T> pop() {
        if (tail_ == head_) {
            return std::nullopt;  // Empty
        }
        T value = buffer_[tail_];
        tail_ = (tail_ + 1) % (N + 1);
        return value;
    }

    [[nodiscard]] bool empty() const { return tail_ == head_; }

    [[nodiscard]] bool full() const {
        return ((head_ + 1) % (N + 1)) == tail_;
    }

    [[nodiscard]] std::size_t size() const {
        if (head_ >= tail_) {
            return head_ - tail_;
        }
        return (N + 1) - tail_ + head_;
    }

    [[nodiscard]] constexpr std::size_t capacity() const { return N; }

private:
    std::array<T, N + 1> buffer_{};  // +1 to distinguish full from empty
    std::size_t head_{0};
    std::size_t tail_{0};
};

int main() {
    RingBuffer<int, 4> rb;

    // Push items
    std::printf("Push 10: %s\n", rb.push(10) ? "OK" : "FULL");
    std::printf("Push 20: %s\n", rb.push(20) ? "OK" : "FULL");
    std::printf("Push 30: %s\n", rb.push(30) ? "OK" : "FULL");
    std::printf("Push 40: %s (buffer full after this)\n", rb.push(40) ? "OK" : "FULL");
    std::printf("Push 50: %s\n", rb.push(50) ? "OK" : "FULL");

    // Pop items
    while (auto val = rb.pop()) {
        std::printf("Pop: %d\n", *val);
    }
    std::printf("Pop: EMPTY\n");

    std::printf("Size: %zu, Empty: %s\n", rb.size(), rb.empty() ? "true" : "false");

    return 0;
}
