cmake_minimum_required(VERSION 3.10)
project(task2 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(../libs/armstrong armstrong)
    add_subdirectory(../libs/process_array process_array)
endif()

add_executable(task2 task2_main.c)
target_link_libraries(task2 armstrong process_array)
target_include_directories(task2 PRIVATE ${CMAKE_SOURCE_DIR}/libs) 