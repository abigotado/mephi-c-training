#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_processor.h"
#include "../process_array/process_array.h"

char *process_string(const char *input, int n) {
    if (!input) return NULL;

    // Разбиваем строку на числа
    int *array = NULL;
    int size = 0;
    int capacity = 10;
    
    array = malloc(sizeof(int) * capacity);
    if (!array) {
        printf("Ошибка при выделении памяти\n");
        return NULL;
    }

    char *str = strdup(input);
    if (!str) {
        free(array);
        return NULL;
    }

    char *token = strtok(str, " \t\n");
    while (token != NULL) {
        // Проверяем, является ли токен числом
        char *endptr;
        long num = strtol(token, &endptr, 10);
        if (*endptr == '\0') { // Если токен полностью преобразован в число
            // При необходимости увеличиваем буфер
            if (size >= capacity) {
                capacity *= 2;
                int *tmp = realloc(array, sizeof(int) * capacity);
                if (!tmp) {
                    printf("Ошибка при перераспределении памяти\n");
                    free(array);
                    free(str);
                    return NULL;
                }
                array = tmp;
            }
            array[size++] = (int)num;
        }
        token = strtok(NULL, " \t\n");
    }
    free(str);

    // Обрабатываем массив
    if (process_array(&array, &size, n) != 0) {
        printf("Ошибка при обработке массива\n");
        free(array);
        return NULL;
    }

    // Формируем результирующую строку
    char *result = malloc(size * 12 + 1); // 12 символов на число + пробел
    if (!result) {
        printf("Ошибка при выделении памяти\n");
        free(array);
        return NULL;
    }

    int pos = 0;
    for (int i = 0; i < size; i++) {
        pos += sprintf(result + pos, "%d ", array[i]);
    }
    if (pos > 0) {
        result[pos - 1] = '\0'; // Убираем последний пробел
    } else {
        result[0] = '\0';
    }

    free(array);
    return result;
} 