cmake_minimum_required(VERSION 3.26)
project(amethyst VERSION 0.2 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

# libraries preparation
add_subdirectory(libs/)
include_directories(libs/)

# built-in libraries
add_library(trie STATIC src/trie.c src/trie.h)
add_library(types STATIC src/types.c src/types.h)
add_library(config STATIC src/config.c src/config.h)
include_directories(src/)

# CORE library that can be used for embedding
add_library(core SHARED core.c)

add_executable(test test.c)

target_link_libraries(test trie)
target_link_libraries(test types)
target_link_libraries(core trie)
target_link_libraries(core types)
