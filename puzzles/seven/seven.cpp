#include "seven.h"

#include <iostream>
#include <vector>

#include "../../utils/string_utils.h"


void seven(const std::vector<std::string> &input) {
    std::cout << "Day seven" << std::endl;

    long found = 0;
    for (const auto &line : input) {
        auto l = utils::split(line, ':');
        auto res = std::stol(l[0]);
        auto op = utils::split(utils::ltrim_copy(l[1]), ' ');
        auto root = std::stol(op[0]);
        std::vector<std::vector<long>> children;
        children.reserve(std::pow(3, op.size() - 1));
        children.push_back(std::vector<long>(1, root));
        for (int i = 1; i < op.size(); ++i) {
            children.emplace_back(std::vector<long>(std::pow(3, i)));
            const auto &o = std::stol(op[i]);
            auto p = 0;
            for (int j = 0; j < std::pow(3, i); j += 3) {
                children[i][j] = children[i - 1][p] + o;
                children[i][j + 1] = children[i - 1][p] * o;
                children[i][j + 2] = std::stol(std::to_string(children[i - 1][p]) + std::to_string(o));
                p += 1;
            }

        }

        auto last = children[children.size() - 1];

        if (std::ranges::find(last, res) != last.end()) {
            std::cout << "Found: " << res << std::endl;
            found += res;
        } else {
            std::cout << "Not found: " << res << std::endl;
        }

    }
    std::cout << "Total: " << found << std::endl;


}