#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "armstrong.h"

NumberStatus check_armstrong(int number, int* sum) {
    // Отрицательные числа не являются Армстронговыми, 
    // указатель на сумму не должен быть NULL
    if (number < 0 || sum == NULL) {
        return ERROR;
    }

    int count = 0;

    // Подсчет количества цифр в числе
    int temp = number;
    while (temp > 0) {
        count++;
        temp /= 10;
    }

    // Подсчет суммы цифр в степени count
    temp = number;
    int sum_of_cubes = 0;
    while (temp > 0) {
        int digit = temp % 10;
        sum_of_cubes += (int) pow(digit, count);
        temp /= 10;
    }

    *sum = sum_of_digits(number); 
    
    // Если сумма кубов равна исходному числу, то число является Армстронговым
    if (sum_of_cubes == number) {
        return ARMSTRONG;
    } else {
        return NOT_ARMSTRONG;
    }
}

int sum_of_digits(int num) {
    int sum = 0;
    num = abs(num);
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}