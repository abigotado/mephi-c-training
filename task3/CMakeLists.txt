cmake_minimum_required(VERSION 3.10)
project(task3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(../libs/armstrong armstrong)
    add_subdirectory(../libs/process_array process_array)
    add_subdirectory(../libs/string_processor string_processor)
endif()

# Поиск библиотеки readline
find_library(READLINE_LIBRARY readline)
if(NOT READLINE_LIBRARY)
    message(FATAL_ERROR "readline library not found")
endif()

add_executable(task3 task3_main.c)
target_link_libraries(task3 armstrong process_array string_processor ${READLINE_LIBRARY})
target_include_directories(task3 PRIVATE ${CMAKE_SOURCE_DIR}/libs) 