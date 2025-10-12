cmake_minimum_required(VERSION 4.1.1)
project(lesson8 C)

include_directories(include)
add_executable(lesson8
    src/main.c
    src/read.c
    src/count.c
)