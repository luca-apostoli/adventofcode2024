#include "four.h"

#include <iostream>
#include <vector>

namespace {
    int countFreq(std::string pat, std::string txt) {
        auto M = pat.length();
        auto N = txt.length();
        auto res = 0;

        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                    break;

            if (j == M) {
                res++;
            }
        }
        return res;
    }


    void part_two(const std::vector<std::vector<char>> &grid) {
        auto res2 = 0;
        for (int i = 0; i < grid.size(); ++i) {
            const auto &row = grid[i];
            for (int j = 0; j < row.size(); ++j) {
                if (row[j] == 'A') {
                    if (j + 1 < row.size() && i + 1 < grid.size() && i > 0 && j > 0) {
                        // MAS MAS
                        if (grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M' &&
                            grid[i - 1][j + 1] == 'S') {
                            res2++;
                        }
                        // MAS SAM
                        if (grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'S' &&
                            grid[i - 1][j + 1] == 'M') {
                            res2++;
                        }
                        // SAM SAM
                        if (grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S' &&
                            grid[i - 1][j + 1] == 'M') {
                            res2++;
                        }
                        // SAM MAS
                        if (grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'M' &&
                            grid[i - 1][j + 1] == 'S') {
                            res2++;
                        }
                    }
                }
            }
        }
        std::cout << "Result MAS: " << res2 << std::endl;
    }

} // namespace

void four(const std::vector<std::string> &input) {
    std::cout << "Day four" << std::endl;
    auto res = 0;
    std::vector<std::vector<char>> grid;
    for (const auto &line: input) {
        res += countFreq("XMAS", line);
        res += countFreq("SAMX", line);
        grid.emplace_back(line.begin(), line.end());
    }

    for (int i = 0; i < grid.size(); ++i) {
        const auto &row = grid[i];
        for (int j = 0; j < row.size(); ++j) {
            if (row[j] == 'X') {
                // Column BACKWARD
                if (i >= 3 && grid[i - 1][j] == 'M' && grid[i - 2][j] == 'A' && grid[i - 3][j] == 'S') {
                    res++;
                }
                // Column FORWARD
                if (i + 3 < grid.size() && grid[i + 1][j] == 'M' && grid[i + 2][j] == 'A' && grid[i + 3][j] == 'S') {
                    res++;
                }
                // Diagonal BACKWARD LEFT
                if (i >= 3 && j >= 3 && grid[i - 1][j - 1] == 'M' && grid[i - 2][j - 2] == 'A' &&
                    grid[i - 3][j - 3] == 'S') {
                    res++;
                }
                // Diagonal BACKWARD RIGHT
                if (i >= 3 && j + 3 < row.size() && grid[i - 1][j + 1] == 'M' && grid[i - 2][j + 2] == 'A' &&
                    grid[i - 3][j + 3] == 'S') {
                    res++;
                }
                // Diagonal FORWARD LEFT
                if (i + 3 < grid.size() && j >= 3 && grid[i + 1][j - 1] == 'M' && grid[i + 2][j - 2] == 'A' &&
                    grid[i + 3][j - 3] == 'S') {
                    res++;
                }
                // Diagonal FORWARD RIGHT
                if (i + 3 < grid.size() && j + 3 < row.size() && grid[i + 1][j + 1] == 'M' &&
                    grid[i + 2][j + 2] == 'A' && grid[i + 3][j + 3] == 'S') {
                    res++;
                }
            }
        }
    }

    std::cout << "Result XMAS: " << res << std::endl;

    part_two(grid);
}
