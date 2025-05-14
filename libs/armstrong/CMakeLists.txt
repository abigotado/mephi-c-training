cmake_minimum_required(VERSION 3.10)

# Определение библиотеки
add_library(armstrong STATIC
    armstrong.c
    armstrong.h
)

# Директории с заголовочными файлами
target_include_directories(armstrong PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Подключение математической библиотеки
target_link_libraries(armstrong m)

# Установка стандарта C
set_target_properties(armstrong PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
)
