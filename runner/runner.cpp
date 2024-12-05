// Copyright (c) Spotify AB

#include "runner.h"

#include <iostream>
#include "../day.h"
#include "../puzzles/five/five.h"
#include "../puzzles/one/one.h"

#include "../puzzles/four/four.h"
#include "../puzzles/three/three.h"
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
            case Three:
                three(input);
                break;
            case Four:
                four(input);
                break;
            case Five:
                five(input);
                break;
        }
    };
} // namespace utils
