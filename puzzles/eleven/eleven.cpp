#include "eleven.h"

#include <__ranges/elements_view.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../../utils/string_utils.h"

namespace {

    uint64_t blink(uint64_t val, std::map<std::pair<uint64_t, uint64_t>, uint64_t> &memo, uint8_t num) {

        if (num == 0) {
            return 1;
        }

        if (val == 0) {
            auto t = blink(1, memo, num - 1);
            memo[{num, val}];
            return t;
        }

        if (memo.contains({num, val})) {
            return memo[{num, val}];
        }

        auto val_string = std::to_string(val);
        if (val_string.size() % 2 == 0) {
            auto l = stol(val_string.substr(0, val_string.length() / 2));
            auto r = stol(val_string.substr(val_string.length() / 2));

            auto l_t = blink(l, memo, num - 1) ;
            auto r_t = blink(r, memo, num - 1);
            memo[{num - 1, l}] = l_t;
            memo[{num - 1, r}] = r_t;
            memo[{num, val}] = l_t + r_t;
            return l_t + r_t;
        }
        auto t = blink(val * 2024, memo, num - 1);
        memo[{num - 1, val * 2024}] = t;
        return t;
    }

} // namespace

void eleven(const std::vector<std::string> &input) {
    std::cout << "Day eleven" << std::endl;

    std::vector<uint64_t> stones;
    auto n = utils::split(input[0], ' ');
    stones.reserve(n.size());
    for (const auto &in: n) {
        stones.push_back(stoull(in));
    }

    std::map<std::pair<uint64_t, uint64_t>, uint64_t> memo;

    long long len = 0;
    for (auto stone: stones) {
         len += blink(stone, memo, 75);
    }


    std::cout << "Num: " << len << std::endl;


}

