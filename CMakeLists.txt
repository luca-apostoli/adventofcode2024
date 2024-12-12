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
        puzzles/four/four.cpp
        puzzles/four/four.h
        puzzles/five/five.cpp
        puzzles/five/five.h
        puzzles/six/six.cpp
        puzzles/six/six.h
        puzzles/seven/seven.cpp
        puzzles/seven/seven.h
        puzzles/eight/eight.cpp
        puzzles/eight/eight.h
        puzzles/nine/nine.cpp
        puzzles/nine/nine.h
        puzzles/ten/ten.cpp
        puzzles/ten/ten.h
        puzzles/eleven/eleven.cpp
        puzzles/eleven/eleven.h
)

