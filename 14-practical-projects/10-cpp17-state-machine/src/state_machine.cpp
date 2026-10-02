/*
 * Language: C++17
 * Target: PC (Simulation)
 * Build: g++ -std=c++17 state_machine.cpp -o state_machine
 * Run: ./state_machine
 * Expected output:
 *   State: Idle → starting measurement
 *   State: Measuring → reading sensor...
 *   State: Measuring → got value: 2500, transition to Idle
 *   State: Idle → triggering error
 *   State: Error → handling error, resetting
 *   State: Idle → system reset
 * What to learn: How std::variant + std::visit implements a type-safe
 *                state machine — a common embedded pattern using C++17
 */

#include <cstdint>
#include <cstdio>
#include <variant>

// --- State types ---
struct Idle {};
struct Measuring { int sample_count = 0; };
struct Error { int code = 0; };

using State = std::variant<Idle, Measuring, Error>;

// --- Events ---
struct StartMeasurement {};
struct SensorDataReady { std::uint16_t value; };
struct FaultDetected { int error_code; };
struct Reset {};

// --- State Machine ---
class SensorController {
public:
    void process(const StartMeasurement&) {
        std::visit([this](auto& s) { handle_start(s); }, state_);
    }

    void process(const SensorDataReady& event) {
        std::visit([this, &event](auto& s) { handle_data(s, event); }, state_);
    }

    void process(const FaultDetected& event) {
        std::visit([this, &event](auto& s) { handle_fault(s, event); }, state_);
    }

    void process(const Reset&) {
        std::visit([this](auto& s) { handle_reset(s); }, state_);
    }

private:
    // --- Handle StartMeasurement ---
    void handle_start(Idle&) {
        std::printf("State: Idle → starting measurement\n");
        state_ = Measuring{};
    }
    void handle_start(Measuring&) { /* Already measuring, ignore */ }
    void handle_start(Error&) { /* In error, ignore */ }

    // --- Handle SensorDataReady ---
    void handle_data(Measuring& s, const SensorDataReady& e) {
        std::printf("State: Measuring → reading sensor...\n");
        s.sample_count++;
        std::printf("State: Measuring → got value: %u, transition to Idle\n",
                    e.value);
        state_ = Idle{};
    }
    void handle_data(Idle&, const SensorDataReady&) { /* Unexpected, ignore */ }
    void handle_data(Error&, const SensorDataReady&) { /* In error, ignore */ }

    // --- Handle FaultDetected ---
    void handle_fault(Idle&, const FaultDetected& e) {
        std::printf("State: Idle → triggering error\n");
        state_ = Error{e.error_code};
    }
    template<typename S>
    void handle_fault(S&, const FaultDetected& e) {
        state_ = Error{e.error_code};
    }

    // --- Handle Reset ---
    void handle_reset(Error&) {
        std::printf("State: Error → handling error, resetting\n");
        state_ = Idle{};
    }
    void handle_reset(Idle&) {
        std::printf("State: Idle → system reset\n");
    }
    void handle_reset(Measuring&) {
        state_ = Idle{};
    }

    State state_{Idle{}};
};

int main() {
    SensorController controller;

    controller.process(StartMeasurement{});
    controller.process(SensorDataReady{2500});
    controller.process(FaultDetected{42});
    controller.process(Reset{});

    return 0;
}
