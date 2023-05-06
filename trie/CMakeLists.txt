cmake_minimum_required(VERSION 3.26)

project(trie VERSION 0.1 LANGUAGES C)

add_library(trie STATIC ./src/trie.c ./src/trie.h)
