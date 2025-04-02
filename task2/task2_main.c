#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_array.h"


int main() {
    int *array = NULL;
    int size = 0, n;

    printf("Введите элементы массива (целые числа), окончание - ввод:\n");

    int capacity = 10;
    size = 0;
    array = malloc(sizeof(int) * capacity);
    if (!array) {
        printf("Ошибка при выделении памяти\n");
        return -1;
    }

    char input[1024];
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Ошибка ввода строки\n");
        return -1;
    }

    char *token = strtok(input, " \t\n");
    while (token != NULL) {
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

    printf("Введите порог суммы цифр (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка при вводе числа\n");
        free(array);
        return -1;
    };

    if (process_array(&array, &size, n) != 0) {
        printf("Ошибка при обработке массива\n");
        free(array);
        return -1;
    };

    printf("Результат: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
