cmake_minimum_required(VERSION 3.10)
project(rectangle_exercise C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(PROJ_INC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJ_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJ_TEST ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_library(rectangle STATIC
    ${PROJ_SRC}/rectangle.c
)
target_include_directories(rectangle PUBLIC ${PROJ_INC})

add_executable(rect_demo
    ${PROJ_SRC}/main.c
)
target_link_libraries(rect_demo PRIVATE rectangle)

enable_testing()
add_executable(test_rectangle tests/test_rectangle.c)
target_link_libraries(test_rectangle PRIVATE rectangle)


target_include_directories(test_rectangle PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/third_party
)
