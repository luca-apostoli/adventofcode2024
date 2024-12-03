#include <iostream>
#include <vector>
#include <string>

#include "../../utils/string_utils.h"

void part_one(std::vector<long> left, std::vector<long> right) {
    long distance = 0;
    while (!left.empty()) {
        auto l_min = std::ranges::min(left);
        auto r_min = std::ranges::min(right);
        distance += std::abs(l_min - r_min);
        left.erase(std::find(left.begin(), left.end(), l_min));
        right.erase(std::find(right.begin(), right.end(), r_min));
    }

    std::cout << "Distance: " << distance << std::endl;
}

void part_two(const std::vector<long>& left, std::vector<long> right) {
    long similarity = 0;
    for (auto l: left) {
        auto num = std::ranges::count_if(right, [l](long r) {
            if (l == r) {
                return true;
            }
            return false;
        });
        if (num > 0) {
            similarity += l * num;
        }
    }

    std::cout << "Similarity: " << similarity << std::endl;
}

void one(const std::vector<std::string> &input) {
    std::cout << "Day one" << std::endl;

    std::vector<long> left, right;
    for (const auto &line : input) {
        auto l = line.substr(0, line.find(' '));
        auto r = line.substr(line.find(' ') + 1);
        left.push_back(std::stol(l));
        right.push_back(std::stol(utils::trim_copy(r)));
    }

    part_one(left, right);

    part_two(left, right);

}