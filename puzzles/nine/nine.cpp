#include "nine.h"

#include <iostream>
#include <string>
#include <vector>

namespace {
    void print_memory(const std::vector<std::optional<long>> &memory) {
        for (auto m: memory) {
            if (m.has_value()) {
                std::cout << m.value();
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }


    void part_one(const std::string &disk_map) {
        std::vector<std::optional<long>> memory;
        for (int i = 0; i < disk_map.size(); ++i) {
            const auto &c = std::stol(std::string(1, disk_map[i]));
            if (i % 2 == 0) {
                for (int j = 0; j < c; ++j) {
                    memory.push_back(i / 2);
                }
            } else {
                for (int j = 0; j < c; ++j) {
                    memory.push_back(std::nullopt);
                }
            }
        }

        // part one - move one block at a time
        for (int i = 0; i < memory.size(); i++) {
            if (!memory[i].has_value()) {
                for (int j = memory.size() - 1; j > i; j--) {
                    if (memory[j].has_value() && memory[j].value() != 0) {
                        memory[i] = memory[j].value();
                        memory[j].emplace(0);
                        break;
                    }
                }
            }
        }

        long checksum = 0;
        for (int i = 0; i < memory.size(); i++) {
            checksum += i * memory[i].value_or(0);
        }

        std::cout << "Checksum: " << checksum << std::endl;

    }

    void part_two(const std::string &disk_map) {

        std::vector<std::pair<int, std::optional<long>>> mem;
        for (int i = 0; i < disk_map.size(); ++i) {
            const auto &c = std::stol(std::string(1, disk_map[i]));
            if (i % 2 == 0) {
                mem.push_back({c, i / 2});
            } else {
                mem.push_back({c, std::nullopt});
            }
        }

        // part two - move all blocks at once
        for (int i = 0; i < mem.size(); i++) {
            if (!mem[i].second.has_value()) {
                for (int j = mem.size() - 1; j > i; j--) {
                    if (mem[j].second.has_value() && mem[j].second.value() != 0
                        && mem[j].first <= mem[i].first
                        ) {
                        mem[i].second = mem[j].second.value();
                        mem[j].second = std::nullopt;
                        if (mem[j].first != mem[i].first) {
                            auto old = mem[i].first - mem[j].first;
                            mem[i].first = mem[j].first;
                            mem.insert(mem.begin() + i + 1, {old, std::nullopt});
                        }
                        break;
                        }
                }
            }
        }

        long checksum = 0;
        long id = 0;
        for (int i = 0; i < mem.size(); i++) {
            if (mem[i].second.has_value()) {
                for (int j = 0; j < mem[i].first; j++) {
                    checksum += id * mem[i].second.value();
                    std::cout << mem[i].second.value();
                    id++;
                }
            } else {
                for (int l = 0; l < mem[i].first; ++l) {
                    std::cout << ".";
                    id++;
                }

            }

        }

        std::cout << std::endl;

        std::cout << "Checksum: " << checksum << std::endl;

    }

} // namespace

void nine(const std::vector<std::string> &input) {
    std::cout << "Day nine" << std::endl;

    const auto disk_map = input[0];

    part_one(disk_map);
    part_two(disk_map);
}
