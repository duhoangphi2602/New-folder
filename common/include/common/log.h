#pragma once

#include <string_view>

namespace common {

// A simple logging interface to mock embedded logging (like printing over UART)
void log_info(std::string_view msg);
void log_error(std::string_view msg);
void log_debug(std::string_view msg);

} // namespace common
