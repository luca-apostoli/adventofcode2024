#include "two.h"

#include "../../utils/string_utils.h"
#include <iostream>
#include <string>
#include <variant>
#include <vector>

constexpr int kMaxStep = 3;
constexpr int kMinStep = 1;

enum Status {
    ASC,
    DESC,
    INVALID,
    PENDING
};

void two(const std::vector<std::string> &input) {

    std::cout << "Day two" << std::endl;

    long num_valid = 0;
    for (const auto &line : input) {
        auto parts = utils::split(line, ' ');
        std::vector<long> range = {};
        std::ranges::for_each(parts, [&range](std::string &part) {
            auto r = std::stol(part);
            range.push_back(r);
        });

        Status status = PENDING;
        long ignoring_one_value = 0;
        for (int i = 0; i < range.size() - 1; ++i) {
            auto a = range[i];
            auto b = range[i + 1];
            if (status == PENDING && i > 0) {
                ignoring_one_value = range[i];
            }
            if (status == PENDING || status == DESC) {
                if (a > b && a - b <= kMaxStep && a - b >= kMinStep) {
                    status = DESC;
                }
                else if (ignoring_one_value == 0) {
                    ignoring_one_value = range[i];
                } else if (ignoring_one_value > 0 && status == DESC) {
                    status = INVALID;
                    break;
                }
            }

            if (status == PENDING || status == ASC) {
                if (a < b &&  b - a <= kMaxStep && b - a >= kMinStep) {
                    status = ASC;
                }
                else if (ignoring_one_value == 0) {
                    ignoring_one_value = range[i];
                } else if (ignoring_one_value > 0 && status == ASC) {
                    status = INVALID;
                    break;
                }
            }
        }

        std::cout << line << " Status: " << status << " Ignoring: " << ignoring_one_value << std::endl;
        if (status != INVALID && status != PENDING) {
            num_valid++;
        }

    }

    std::cout << "Valid: " << num_valid << std::endl;
}