#pragma once

#include <string>

namespace utils {
    class FileUtils {
    public:
        static std::vector<std::string> read(const std::string &file_name) noexcept;
        static void write(const std::string &file_name, const std::string &content) noexcept;
    };
} // namespace utils