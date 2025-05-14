cmake_minimum_required(VERSION 3.10)

add_library(string_processor STATIC
    string_processor.c
    string_processor.h
)

target_include_directories(string_processor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(string_processor process_array) 