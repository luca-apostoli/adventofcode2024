// Copyright (c) Spotify AB

#include "runner.h"

#include "../day.h"
#include "../puzzles/one/one.h"
#include <iostream>
#include "../puzzles/two/two.h"

namespace utils {
    void Runner::run(const std::vector<std::string> &input, const Day &day) noexcept {
        std::cout << "Running day " << day << std::endl;
        switch (day) {
            case One:
                one(input);
                break;
            case Two:
                two(input);
                break;
        }
    };
} // namespace utils
