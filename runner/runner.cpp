// Copyright (c) Spotify AB

#include "runner.h"

#include "../day.h"
#include "../one/one.h"
#include <iostream>

namespace utils {

void Runner::run(const std::vector<std::string>& input, const Day &day) noexcept {
    std::cout << "Running day " << day << std::endl;
    switch (day) {
      case One:
        one(input);
        break;
    }
};

} // namespace utils