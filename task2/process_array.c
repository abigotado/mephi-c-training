#include <stdlib.h>
#include <stdio.h>
#include "process_array.h"
#include "../sum_of_digits/sum_of_digits.h"
#include "../armstrong/armstrong.h"

int process_array(int **arr, int *size, int n) {
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

    *arr = realloc(*arr, new_size * sizeof(int));
    if (!*arr) {
        printf("Ошибка при выделении памяти\n");
        free(new_arr);
        return -1;
    }

    for (int i = 0; i < new_size; i++) {
        (*arr)[i] = new_arr[i];
    }

    *size = new_size;
    free(new_arr);

    return 0;
}