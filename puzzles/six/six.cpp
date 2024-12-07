#include "six.h"

#include <__algorithm/ranges_all_of.h>
#include <__algorithm/ranges_any_of.h>
#include <iostream>
#include <string>
#include <vector>

namespace {
    void print_grid(const std::vector<std::vector<unsigned char>> &grid) {
        for (const auto &row: grid) {
            for (const auto &cell: row) {
                std::cout << cell;
            }
            std::cout << std::endl;
        }
    }

    void print_visited(const std::vector<std::pair<int, int>> &visited) {
        for (const auto &point: visited) {
            std::cout << "(" << point.first << "," << point.second << ")";
        }
        std::cout << std::endl;
    }

    bool is_visited(const std::vector<std::pair<int, int>> &visited, const std::pair<int, int> &point) {
        return std::find(visited.begin(), visited.end(), point) != visited.end();
    }


    bool play(std::vector<std::vector<unsigned char>> &&grid, const std::pair<int, int> &start, long &steps,
              std::vector<std::pair<int, int>> &visited) {
        int x, y = 0;
        x = start.first;
        y = start.second;
        const auto row_len = grid[0].size();
        const auto col_len = grid.size();
        std::vector<std::string> loopy;
        while (x < grid.size() && y < grid[0].size()) {
            if (steps > 0 && std::find(loopy.begin(), loopy.end(),
                std::to_string(x) + "," + std::to_string(y) + "," + std::string(1, grid[x][y])) != loopy.end()) {
                return true;
            }
            loopy.push_back(std::to_string(x) + "," + std::to_string(y) + "," + std::string(1, grid[x][y]));
            if (grid[x][y] == '^') {
                // move up
                if (x - 1 >= 0 && grid[x - 1][y] != '#') {
                    grid[x][y] = '|';

                    x -= 1;
                    if (!is_visited(visited, {x, y})) {
                        steps += 1;
                        visited.emplace_back(x, y);
                    }
                    grid[x][y] = '^';
                }
                // turn right
                else if (x - 1 >= 0 && grid[x - 1][y] == '#') {
                    grid[x][y] = '>';
                } else {
                    break;
                }
            }
            if (grid[x][y] == '>') {
                // move right
                if (y + 1 < row_len && grid[x][y + 1] != '#') {
                    grid[x][y] = '-';

                    y += 1;
                    if (!is_visited(visited, {x, y})) {
                        steps += 1;
                        visited.emplace_back(x, y);
                    }
                    grid[x][y] = '>';
                }
                // turn down
                else if (y + 1 < row_len && grid[x][y + 1] == '#') {
                    grid[x][y] = 'v';
                } else {
                    break;
                }
            }
            if (grid[x][y] == 'v') {
                // move down
                if (x + 1 < col_len && grid[x + 1][y] != '#') {
                    grid[x][y] = '|';

                    x += 1;
                    if (!is_visited(visited, {x, y})) {
                        steps += 1;
                        visited.emplace_back(x, y);
                    }
                    grid[x][y] = 'v';
                }
                // turn left
                else if (x + 1 < col_len && grid[x + 1][y] == '#') {
                    grid[x][y] = '<';
                } else {
                    break;
                }
            }
            if (grid[x][y] == '<') {
                // move left
                if (y - 1 >= 0 && grid[x][y - 1] != '#') {
                    grid[x][y] = '-';

                    y -= 1;
                    if (!is_visited(visited, {x, y})) {
                        steps += 1;
                        visited.emplace_back(x, y);
                    }
                    grid[x][y] = '<';
                }
                // turn up
                else if (y - 1 >= 0 && grid[x][y - 1] == '#') {
                    grid[x][y] = '^';
                } else {
                    break;
                }
            }
        }
        return false;
    }

    bool play(std::vector<std::vector<unsigned char>> &&grid, const std::pair<int, int> &start) {
        std::vector<std::pair<int, int>> visited = {};
        long steps = 0;
        return play(move(grid), start, steps, visited);
    }
} // namespace

void six(const std::vector<std::string> &input) {
    std::cout << "Day six" << std::endl;

    std::vector<std::vector<unsigned char>> grid;
    std::pair<int, int> start = {0, 0};
    for (int i = 0; i < input.size(); ++i) {
        const auto &line = input[i];
        std::vector<unsigned char> row;
        row.reserve(line.size());
        for (int j = 0; j < line.size(); ++j) {
            row.push_back(line[j]);
            if (line[j] == '^') {
                start = {i, j};
            }
        }
        grid.push_back(row);
    }

    long steps = 0;
    std::vector<std::pair<int, int>> visited;
    const auto original_grid = grid;
    play(std::move(grid), start, steps, visited);
    std::cout << "Steps: " << steps << std::endl;

    long num_loops = 0;
    for (auto pair: visited) {
        if (pair != start) {
            auto new_grid = original_grid;
            new_grid[pair.first][pair.second] = '#';

            if (play(std::move(new_grid), start)) {
                num_loops += 1;
                std::cout << "Loop: " << num_loops << std::endl;
            }
        }
    }
    std::cout << "Number of loops: " << num_loops << std::endl;
}
