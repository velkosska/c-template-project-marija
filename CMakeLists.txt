cmake_minimum_required(VERSION 3.21)
project(Homework C)

set(PROJECT_AUTHOR "Raul P. Pelaez")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)
add_subdirectory(docs)
