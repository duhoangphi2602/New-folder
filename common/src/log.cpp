#include "common/log.h"
#include <iostream>

namespace common {

void log_info(std::string_view msg) {
    std::cout << "[INFO] " << msg << '\n';
}

void log_error(std::string_view msg) {
    std::cerr << "[ERROR] " << msg << '\n';
}

void log_debug(std::string_view msg) {
    std::cout << "[DEBUG] " << msg << '\n';
}

} // namespace common
