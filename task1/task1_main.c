#include <stdio.h>
#include "../armstrong/armstrong.h"

int main() {
    int number = 0;
    int sum = 0;

    printf("Введите число: ");
    if (scanf("%d", &number) != 1) {
        printf("Ошибка при вводе числа\n");
        return 1;
    }

    NumberStatus status = check_armstrong(number, &sum);

    switch (status) {
        case ERROR:
            printf("Ошибка при анализе числа\n");
            break;
        case ARMSTRONG:
            printf("Проанализированное число является числом Армстронга.\nСумма цифр: %d\n", sum);
            break;
        case NOT_ARMSTRONG:
            printf("Проанализированное число не является числом Армстронга.\nСумма цифр: %d\n", sum);
            break;
    }
    return 0;
}