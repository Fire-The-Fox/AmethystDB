cmake_minimum_required(VERSION 3.0)
project(amethyst)

add_subdirectory(trie)

add_executable(test ./test.c)
target_link_libraries(test trie)
