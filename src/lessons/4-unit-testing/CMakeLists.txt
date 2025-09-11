


add_executable(1-first-unit-test 1-first-unit-test.c)
target_include_directories(1-first-unit-test PRIVATE ${PROJECT_SOURCE_DIR}/third_party)
add_test(NAME 1-first-unit-test COMMAND 1-first-unit-test)
