cmake_minimum_required(VERSION 3.26)

project(types VERSION 0.1 LANGUAGES C)

add_library(types STATIC ./src/types.c ./src/types.h)
