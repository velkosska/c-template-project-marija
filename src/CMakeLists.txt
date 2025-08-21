
add_library(some_library SHARED some_library.c)
add_executable(some_executable some_executable.c)
target_link_libraries(some_executable some_library)
