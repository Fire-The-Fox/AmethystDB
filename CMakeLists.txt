cmake_minimum_required(VERSION 3.0)
project(amethyst VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_subdirectory(./trie)
add_subdirectory(./types)

add_executable(test ./test.c)
add_library(core SHARED ./core.c)

target_link_libraries(test trie)
target_link_libraries(test types)
target_link_libraries(core trie)
target_link_libraries(core types)
