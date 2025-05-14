cmake_minimum_required(VERSION 3.10)

add_library(process_array STATIC
    process_array.c
    process_array.h
)

target_include_directories(process_array PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(process_array armstrong) 