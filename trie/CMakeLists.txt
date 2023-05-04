cmake_minimum_required(VERSION 3.26)

project(
    Trie
    VERSION 0.1
    LANGUAGES C
)

find_program(LLVM_COMPILER clang)

IF(LLVM_COMPILER)
    set(CMAKE_C_COMPILER clang)
ENDIF()

add_library(trie STATIC ./src/trie.c ./src/trie.h)
