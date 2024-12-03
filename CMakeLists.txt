cmake_minimum_required(VERSION 3.30)
project(cpp)

set(CMAKE_CXX_STANDARD 26)

add_subdirectory(utils)
add_subdirectory(runner)


link_libraries(
        runner
        utils
)

add_executable(cpp
        main.cpp
        day.h
        puzzles/one/one.cpp
        puzzles/one/one.h
        puzzles/two/two.cpp
        puzzles/two/two.h
        puzzles/three/three.cpp
        puzzles/three/three.h
)

