#include "five.h"

#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#include "../../utils/string_utils.h"

void five(const std::vector<std::string> &input) {
    std::cout << "Day five" << std::endl;

    std::map<uint32_t, std::vector<uint32_t>> tree;

    std::vector<std::vector<uint32_t>> instruction;
    std::vector<std::vector<uint32_t>> incorrect;

    for (auto &line: input) {
        if (line.contains('|')) {
            auto lr = utils::split(line, '|');
            auto l = std::stol(lr[0]);
            auto r = std::stol(lr[1]);
            if (tree.contains(l)) {
                tree[l].push_back(r);
            } else {
                tree[l] = std::vector<uint32_t>();
                tree[l].push_back(r);
            }
        } else if (line.contains(',')) {
            auto in = utils::split(line, ',');
            std::vector<uint32_t> ins = std::vector<uint32_t>(in.size());
            std::ranges::transform(in, ins.begin(), [](const std::string &s) { return std::stol(s); });
            instruction.push_back(ins);
        }
    }

    uint64_t result = 0;

    for (auto &up: instruction) {
        uint64_t middle = 0;
        for (int i = 0; i < up.size(); i++) {
            auto u = up[i];
            if (tree.contains(u)) {
                auto rules = tree[u];
                auto nok = std::any_of(up.begin(), up.begin() + i,
                                       [&rules](uint32_t &v) { return std::ranges::find(rules, v) != rules.end(); });
                if (nok) {
                    middle = 0;
                    incorrect.push_back(up);
                    break;
                } else {
                    middle = up[(up.size() - 1) / 2];
                }
            }
        }
        result += middle;
    }

    std::cout << "Result: " << result << std::endl;


    uint64_t inc_result = 0;

    for (auto &inc: incorrect) {
        std::ranges::sort(inc, [tree](auto a, auto b) -> bool {
            if (tree.contains(a)) {
                auto rules = tree.find(a)->second;
                return std::ranges::find(rules, b) != rules.end();
            }
            if (tree.contains(b)) {
                auto rules = tree.find(b)->second;
                return std::ranges::find(rules, a) == rules.end();
            }
            return true;
        });
        inc_result += inc[(inc.size() - 1) / 2];
    }

    std::cout << "Incorrect result: " << inc_result << std::endl;
}
