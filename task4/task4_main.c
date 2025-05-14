#include <stdio.h>
#include <stdlib.h>
#include "../libs/list_processor/list_processor.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Node* head = NULL;
    int n;
    int number;
    int count = 0;
    char input[256];

    printf("Введите порог суммы цифр (n): ");
    while (scanf("%d", &n) != 1) {
        printf("Ошибка ввода. Введите число: ");
        clear_input_buffer();
    }
    clear_input_buffer();  // Очищаем буфер после ввода n

    printf("\nВведите числа (для завершения ввода введите любой нечисловой символ):\n");
    while (1) {
        printf("Введите число %d: ", count + 1);
        if (scanf("%d", &number) != 1) {
            clear_input_buffer();
            break;
        }
        clear_input_buffer();  // Очищаем буфер после каждого числа

        Node* new_node = create_node(number);
        if (new_node == NULL) {
            printf("Ошибка при выделении памяти\n");
            free_list(head);
            return 1;
        }

        if (head == NULL) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
        count++;
    }

    if (count == 0) {
        printf("Список пуст\n");
        return 0;
    }

    printf("\nИсходный список: ");
    print_list(head);
    fflush(stdout);

    printf("Обработка списка...\n");
    process_list(&head, n);

    printf("Результат обработки: ");
    print_list(head);
    fflush(stdout);

    free_list(head);
    return 0;
} 