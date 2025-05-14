#include <stdio.h>
#include <stdlib.h>
#include "list_processor.h"
#include "../armstrong/armstrong.h"

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_after(Node* prev_node, int data) {
    if (prev_node == NULL) return;
    Node* new_node = create_node(data);
    if (new_node == NULL) {
        printf("Ошибка при выделении памяти\n");
        return;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void remove_after(Node* prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) return;
    Node* temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

void process_list(Node** head, int n) {
    if (head == NULL || *head == NULL) return;

    // Сначала удаляем числа с суммой цифр <= n
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        int sum = 0;
        check_armstrong(current->data, &sum);

        if (sum <= n) {
            if (prev == NULL) {
                *head = current->next;
                free(current);
                current = *head;
            } else {
                remove_after(prev);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    // Затем дублируем числа Армстронга
    current = *head;
    while (current != NULL) {
        int sum = 0;
        NumberStatus status = check_armstrong(current->data, &sum);

        if (status == ARMSTRONG) {
            insert_after(current, current->data);
            current = current->next->next;  // Пропускаем дублированное число
        } else {
            current = current->next;
        }
    }
}

void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
} 