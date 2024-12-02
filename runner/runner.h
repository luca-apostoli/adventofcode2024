#pragma once

#include <string>
#include <vector>
#include "../day.h"

namespace utils {
class Runner {
    public:
        static void run(const std::vector<std::string>& input, const Day &day) noexcept;
};

} // namespace utils