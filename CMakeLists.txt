cmake_minimum_required(VERSION 3.21)
project(Homework C)

set(PROJECT_AUTHOR "Raul P. Pelaez")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)
add_subdirectory(docs)
