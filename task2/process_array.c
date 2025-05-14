#include <stdlib.h>
#include <stdio.h>
#include "process_array.h"
#include "../libs/armstrong/armstrong.h"

int process_array(int **arr, int *size, int n) {
    int i = 0;
    int new_size = 0;

    while (i < *size) {
        int val = (*arr)[i];
        int temp_sum;
        // Определяем статус числа и одновременно получаем сумму его цифр
        NumberStatus status = check_armstrong(val, &temp_sum);
        if (status == ERROR) {
            printf("Ошибка при анализе числа\n");
            return -1;
        }

        // Если сумма цифр меньше или равна n — удаляем элемент
        if (temp_sum <= n) {
            // Удаляем элемент: сдвигаем всё влево
            for (int j = i; j < *size - 1; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*size)--;
            continue; // не увеличиваем i
        }

        // Если число Армстронга — вставляем дубликат
        if (status == ARMSTRONG) {
            // Увеличиваем размер массива для дублирования числа Армстронга
            *arr = realloc(*arr, sizeof(int) * (*size + 1));
            if (!*arr) {
                printf("Ошибка при перераспределении памяти\n");
                return -1;
            }

            // Сдвигаем элементы вправо, чтобы освободить место под дубликат
            for (int j = *size; j > i + 1; j--) {
                (*arr)[j] = (*arr)[j - 1];
            }

            // Вставляем дубликат
            (*arr)[i + 1] = val;
            (*size)++;
            i += 2; // пропускаем обе копии
        } else {
            i++;
        }
    }

    return 0;
}

int process_array_with_buffer(int **arr, int *size, int n) {
    // Буферная версия: собираем новый массив, затем копируем результат в исходный
    int *new_arr = malloc(sizeof(int) * (*size) * 2);
    if (!new_arr) {
        printf("Ошибка при выделении памяти\n");
        return -1;
    }

    int new_size = 0;
    for (int i = 0; i < *size; i++) {
        int val = (*arr)[i];
        int temp_sum;
        NumberStatus status = check_armstrong(val, &temp_sum);
        if (status == ERROR) {
            printf("Ошибка при анализе числа\n");
            free(new_arr);
            return -1;
        }
        if (temp_sum <= n) continue;

        if (status == ARMSTRONG) {
            new_arr[new_size++] = val;
            new_arr[new_size++] = val;
        } else {
            new_arr[new_size++] = val;
        }
    }

    // Перераспределяем память исходного массива под новый размер
    *arr = realloc(*arr, new_size * sizeof(int));
    if (!*arr) {
        printf("Ошибка при выделении памяти\n");
        free(new_arr);
        return -1;
    }

    // Копируем данные из временного буфера в исходный массив
    for (int i = 0; i < new_size; i++) {
        (*arr)[i] = new_arr[i];
    }

    *size = new_size;
    free(new_arr);

    return 0;
}