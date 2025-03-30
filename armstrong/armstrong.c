#include <stdio.h>
#include <math.h>
#include <armstrong.h>

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
    while (temp > 0) {
        int digit = temp % 10;
        *sum += (int) pow(digit, count);
        temp /= 10;
    }
    
    // Если сумма равна исходному числу, то число является Армстронговым
    if (*sum == number) {
        return ARMSTRONG;
    } else {
        return NOT_ARMSTRONG;
    }
}