// Copyright (c) Spotify AB

#include "runner.h"

#include <iostream>
#include "../day.h"
#include "../puzzles/eight/eight.h"
#include "../puzzles/five/five.h"
#include "../puzzles/four/four.h"
#include "../puzzles/nine/nine.h"
#include "../puzzles/one/one.h"
#include "../puzzles/seven/seven.h"
#include "../puzzles/six/six.h"
#include "../puzzles/three/three.h"
#include "../puzzles/two/two.h"
#include "../puzzles/ten/ten.h"

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
            case Six:
                six(input);
                break;
            case Seven:
                seven(input);
                break;
            case Eight:
                eight(input);
                break;
            case Nine:
                nine(input);
                break;
            case Ten:
                ten(input);
                break;
        }
    };
} // namespace utils
