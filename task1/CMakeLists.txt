cmake_minimum_required(VERSION 3.10)
project(task1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(../libs/armstrong armstrong)
endif()

add_executable(task1 task1_main.c)
target_link_libraries(task1 armstrong)
target_include_directories(task1 PRIVATE ${CMAKE_SOURCE_DIR}/libs) 