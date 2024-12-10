#include "ten.h"

#include <__algorithm/ranges_contains.h>
#include <iostream>
#include <string>
#include <vector>

namespace {
    void hike(const std::vector<std::vector<int>> &trails_map, int x, int y, long &hikes,
              std::vector<std::pair<int, int>> &reached) {
        auto val = trails_map[x][y];
        if (val == 9 && !std::ranges::contains(reached, std::pair<int, int>{x, y})) {
            hikes++;
            reached.push_back({x, y});
            return;
        }
        if (x + 1 < trails_map.size() && trails_map[x + 1][y] == val + 1) {
            hike(trails_map, x + 1, y, hikes, reached);
        }
        if (y + 1 < trails_map[x].size() && trails_map[x][y + 1] == val + 1) {
            hike(trails_map, x, y + 1, hikes, reached);
        }
        if (x - 1 >= 0 && trails_map[x - 1][y] == val + 1) {
            hike(trails_map, x - 1, y, hikes, reached);
        }
        if (y - 1 >= 0 && trails_map[x][y - 1] == val + 1) {
            hike(trails_map, x, y - 1, hikes, reached);
        }
    }

    void count_paths(const std::vector<std::vector<int>> &trails_map, int x, int y, long &hikes,
                     std::vector<std::vector<std::pair<int, int>>> paths, std::vector<std::pair<int, int>> path) {
        auto val = trails_map[x][y];
        if (val == 9 && !std::ranges::contains(paths, std::vector<std::pair<int, int>>{path})) {
            paths.push_back(path);
            hikes++;
            return;
        }
        path.push_back({x, y});
        if (x + 1 < trails_map.size() && trails_map[x + 1][y] == val + 1) {
            count_paths(trails_map, x + 1, y, hikes, paths, path);
        }
        if (y + 1 < trails_map[x].size() && trails_map[x][y + 1] == val + 1) {
            count_paths(trails_map, x, y + 1, hikes, paths, path);
        }
        if (x - 1 >= 0 && trails_map[x - 1][y] == val + 1) {
            count_paths(trails_map, x - 1, y, hikes, paths, path);
        }
        if (y - 1 >= 0 && trails_map[x][y - 1] == val + 1) {
            count_paths(trails_map, x, y - 1, hikes, paths, path);
        }
    }
} // namespace

void ten(const std::vector<std::string> &input) {
    std::cout << "Day ten" << std::endl;

    std::vector<std::pair<int, int>> starting;
    std::vector<std::vector<int>> trails_map;
    for (int i = 0; i < input.size(); ++i) {
        auto line = input[i];
        std::vector<int> trail;
        for (int j = 0; j < input[i].size(); ++j) {
            char c = line[j];
            auto val = std::stoi(std::string(1, c));
            trail.push_back(val);
            if (val == 0) {
                starting.push_back({i, j});
            }
        }
        trails_map.push_back(trail);
    }

    long hikes = 0;
    for (int i = 0; i < starting.size(); ++i) {
        long h = 0;
        auto start = starting[i];
        std::vector<std::pair<int, int>> reached;
        int x = start.first;
        int y = start.second;
        hike(trails_map, x, y, h, reached);
        hikes += h;
    }
    std::cout << "Hikes: " << hikes << std::endl;

    long num_paths = 0;
    for (int i = 0; i < starting.size(); ++i) {
        long c = 0;
        auto start = starting[i];
        std::vector<std::vector<std::pair<int, int>>> paths;
        std::vector<std::pair<int, int>> path;
        int x = start.first;
        int y = start.second;
        count_paths(trails_map, x, y, c, paths, path);
        num_paths += c;
    }

    std::cout << "Num Paths: " << num_paths << std::endl;
}
