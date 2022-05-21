cmake_minimum_required(VERSION 3.23)

project(Tetris
    VERSION 0.0.1
    DESCRIPTION "Simple CLI Tetris"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_compile_options(-Wall -std=c++17)

include_directories(./includes ./includes/items ./includes/lib)

file(GLOB_RECURSE SOURCES
    "./src/**.cpp"
)
add_executable(Tetris ${SOURCES})

target_link_libraries(Tetris ${CURSES_LIBRARIES})