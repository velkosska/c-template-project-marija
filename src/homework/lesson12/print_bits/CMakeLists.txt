cmake_minimum_required(VERSION 4.1)
project(print_bits C)
include_directories(include)
add_executable(print_bits src/main.c src/bits.c)
