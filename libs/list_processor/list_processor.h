#ifndef LIST_PROCESSOR_H
#define LIST_PROCESSOR_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);
void insert_after(Node* prev_node, int data);
void remove_after(Node* prev_node);
void process_list(Node** head, int n);
void free_list(Node* head);
void print_list(Node* head);

#endif // LIST_PROCESSOR_H 