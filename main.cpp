#include <iostream>
#include <__filesystem/operations.h>

#include "utils/file_utils.h"
#include "runner/runner.h"
#include "day.h"


const Day selected_day = One;

namespace {
    std::string getFileName(const Day &selected_day) noexcept {
        return std::filesystem::canonical("../data/" + std::to_string(selected_day) + ".txt");
    }
}

int main() {
    std::cout << "Hello and welcome to day " << selected_day << "!\n";


    auto content = utils::FileUtils::read(getFileName(selected_day));


    utils::Runner::run(content, selected_day);


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.