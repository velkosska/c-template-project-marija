cmake_minimum_required(VERSION 3.12)
project(lesson10 C)
set(CMAKE_C_STANDARD 11)

add_executable(main
  src/main.c
  src/welcome.c
)
target_include_directories(main PRIVATE include)

add_executable(super_assert_demo
  src/super_assert_demo.c
)
target_include_directories(super_assert_demo PRIVATE include)

add_executable(test_welcome
  tests/test_welcome.c
  src/welcome.c
)
target_include_directories(test_welcome PRIVATE include tests)

target_compile_definitions(test_welcome PRIVATE LANGUAGE=1)

enable_testing()
add_test(NAME test_welcome COMMAND test_welcome)
