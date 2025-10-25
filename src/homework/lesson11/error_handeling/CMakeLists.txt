cmake_minimum_required(VERSION 4.1)
project(error_handling C)
include_directories(include)
add_executable(error_handling src/main.c src/error.c)
