// Copyright (c) Spotify AB

#include "file_utils.h"

#include <iostream>
#include <fstream>

namespace utils {
    std::vector<std::string> FileUtils::read(const std::string &file_name) noexcept {
        std::vector<std::string> lines;
        std::string line;
        std::ifstream in;
        in.open(file_name, std::ios::in);
        if (in.is_open())
        {
            while ( getline (in,line) )
            {
                lines.push_back(line);
            }
            in.close();
        }
        return lines;
    }

    void FileUtils::write(const std::string &file_name, const std::string &content) noexcept {
        std::ofstream out;
        out.open(file_name, std::ios::out);
        if (out.is_open())
        {
            out << content;
            out.close();
        }
    }
}