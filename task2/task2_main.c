#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_array.h"


int main(int argc, char *argv[]) {
    int *array = NULL;
    int size = 0, n;

    printf("Введите элементы массива (целые числа), окончание - ввод:\n");

    // Выделяем начальный буфер под массив
    int capacity = 10;
    size = 0;
    array = malloc(sizeof(int) * capacity);
    if (!array) {
        printf("Ошибка при выделении памяти\n");
        return -1;
    }

    // Считываем всю строку чисел из ввода
    char input[1024];
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Ошибка ввода строки\n");
        return -1;
    }

    char *token = strtok(input, " \t\n");
    while (token != NULL) {
        // При необходимости увеличиваем буфер массива
        if (size >= capacity) {
            capacity *= 2;
            int *tmp = realloc(array, sizeof(int) * capacity);
            if (!tmp) {
                printf("Ошибка при перераспределении памяти\n");
                free(array);
                return -1;
            }
            array = tmp;
        }

        // Преобразуем токен в число и проверяем корректность
        char *endptr;
        array[size] = (int)strtol(token, &endptr, 10);
        if (*endptr != '\0') {
            printf("Недопустимое значение: %s\n", token);
            free(array);
            return -1;
        }
        size++;
        token = strtok(NULL, " \t\n");
    }

    // Вводим значение порога суммы цифр
    printf("Введите порог суммы цифр (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка при вводе числа\n");
        free(array);
        return -1;
    };

    // Определяем, какую версию обработки массива использовать
    int result = 0;
    if (argc > 1 && strcmp(argv[1], "buffer") == 0) {
        printf("Используется версия с буфером.\n");
        result = process_array_with_buffer(&array, &size, n);
    } else {
        printf("Используется версия без буфера.\n");
        result = process_array(&array, &size, n);
    }
    if (result != 0) {
        printf("Ошибка при обработке массива\n");
        free(array);
        return -1;
    }

    // Выводим обработанный массив
    printf("Результат: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
