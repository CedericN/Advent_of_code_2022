cmake_minimum_required(VERSION 3.23)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(CMAKE_CXX_STANDARD 14)

add_executable(${ProjectId} main.cpp Assignments.cpp Assignments.h Elf_Pairs.cpp Elf_pairs.h)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/input.txt
        COMMAND ${CMAKE_COMMAND}
        -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
)

set_property(SOURCE main.cpp APPEND PROPERTY OBJECT_DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/input.txt)

string(SUBSTRING ${ProjectId} 3 2 Number)
add_definitions(-DDAY="${Number}")