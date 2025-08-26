cmake_minimum_required(VERSION 3.21)
project(Homework C)

set(PROJECT_AUTHOR "Raul P. Pelaez")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)
# MSVC ignores these CMAKE variables for some reason
if(MSVC)
  add_compile_options(/std:clatest)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)
add_subdirectory(docs)
