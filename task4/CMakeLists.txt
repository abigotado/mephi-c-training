cmake_minimum_required(VERSION 3.10)
project(task4)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add the list_processor library
add_library(list_processor
    ${CMAKE_SOURCE_DIR}/../libs/list_processor/list_processor.c
)

# Add the armstrong library
add_library(armstrong
    ${CMAKE_SOURCE_DIR}/../libs/armstrong/armstrong.c
)

# Add the main executable
add_executable(task4 task4_main.c)

# Link libraries
target_link_libraries(task4
    list_processor
    armstrong
) 