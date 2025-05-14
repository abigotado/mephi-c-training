#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "../libs/string_processor/string_processor.h"

int main() {
    char *line;
    int n;

    printf("Введите порог суммы цифр (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка при вводе числа\n");
        return 1;
    }
    getchar(); // Пропускаем оставшийся символ новой строки

    while ((line = readline("Введите строку (Ctrl+D для завершения): ")) != NULL) {
        char *result = process_string(line, n);
        if (result) {
            printf("Результат: %s\n", result);
            free(result);
        }
        free(line);
    }

    return 0;
} 