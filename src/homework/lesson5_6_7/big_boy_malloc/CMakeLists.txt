cmake_minimum_required(VERSION 3.10)
project(bigboy C)
set(CMAKE_C_STANDARD 11)

add_library(bigboy_lib src/library.c)
target_include_directories(bigboy_lib PUBLIC include)

add_executable(bigboy_app src/main.c)
target_link_libraries(bigboy_app PRIVATE bigboy_lib)

enable_testing()
add_executable(sum_test tests/sum_test.c)        # (create tests/sum_test.c as needed)
target_link_libraries(sum_test PRIVATE bigboy_lib)
add_test(NAME sum_runs COMMAND sum_test)
