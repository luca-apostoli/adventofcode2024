#include "eight.h"

#include <iostream>
#include <string>
#include <valarray>
#include <vector>

namespace {
    void print_antennas(const std::vector<std::vector<std::pair<char, int>>> &antennas) {
        for (auto const &antenna : antennas) {
            for (auto a: antenna) {
                if (a.second > 0 && a.first == '.') {
                    std::cout << "#";
                }
                else {
                    std::cout << a.first;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}


void eight(const std::vector<std::string> &input) {
    std::cout << "Day eight" << std::endl;

    std::vector<char> antennas;
    std::vector<std::vector<std::pair<char, int>>> positions;
    for (int j = 0; j < input.size(); ++j) {
        const auto &line = input[j];
        positions.emplace_back(std::vector<std::pair<char, int>>());
        for (int i = 0; i < line.size(); ++i) {
            positions[j].push_back({line[i], 0});
            if (line[i]!='.' && std::find(antennas.begin(), antennas.end(), line[i]) == antennas.end()) {
                antennas.push_back(line[i]);
            }
        }
    }

    long anitnodes_count = 0;
    auto antinodes = positions;
    for (char antenna : antennas) {
        std::cout << "Antenna: " << antenna << " ";
        for (int y = 0; y < antinodes.size(); ++y) {
            for (int x = 0; x < antinodes[y].size(); ++x) {
                if (antinodes[y][x].first == antenna) {
                    // scan forward
                    for (int i = 0; i < antinodes[y].size(); ++i) {
                        for (int j = 0; j < antinodes.size(); ++j) {
                            if (i != x && j != y && antinodes[j][i].first == antenna) {
                                if (antinodes[j][i].second == 0) {
                                    anitnodes_count++;
                                    antinodes[j][i].second++;
                                }
                                auto dx = i - x;
                                auto dy = j - y;
                                while (dx + i < antinodes[y].size() && dy + j < antinodes.size()) {
                                    if (antinodes[j + dy][i + dx].second == 0) {
                                        anitnodes_count++;
                                    }
                                    antinodes[j + dy][i + dx].second++;
                                    dx += i - x;
                                    dy += j - y;
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << std::endl;
    }
    print_antennas(antinodes);
    std::cout << "Antinode count: " << anitnodes_count << std::endl;
}


