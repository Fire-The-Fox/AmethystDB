cmake_minimum_required(VERSION 3.26)
project(libs LANGUAGES C)

add_library(toml STATIC ./toml.c ./toml.h)
