#include "three.h"

#include <iostream>
#include <vector>
#include <string>
#include <regex>

void three(const std::vector<std::string> &input) {
    std::cout << "Day three" << std::endl;

    std::regex mul_regex(R"(mul\([0-9]{1,3},[0-9]{1,3}\)|don\'t\(\)|do\(\))");

    long long result = 0;
    bool enabled = true;
    for (const auto &line : input) {
        auto mul_begin = std::sregex_iterator(line.begin(), line.end(), mul_regex);
        auto mul_end = std::sregex_iterator();

        for (std::sregex_iterator i = mul_begin; i != mul_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str();

            if (match_str == "don't()") {
                    enabled = false;
            } else if (match_str == "do()") {
                enabled = true;
            } else {

                auto l = match_str.substr(4, match_str.find(',') - 4);
                auto r = match_str.substr(match_str.find(',') + 1, match_str.find(')') - 1);
                if (enabled) {
                    result += std::stoll(l) * std::stoll(r);
                }

            }
        }
    }

    std::cout << "Result: " << result << std::endl;
}