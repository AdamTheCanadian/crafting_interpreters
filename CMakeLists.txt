cmake_minimum_required(VERSION 3.19)
project(crafting_interpreters C)

set(CMAKE_C_STANDARD 11)

add_library(ci
        chunk.c
        memory.c
        debug.c
        value.c)
add_executable(crafting_interpreters main.c)
target_link_libraries(crafting_interpreters ci)