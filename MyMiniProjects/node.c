#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;


Node* create_node(int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error while giving memory");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void append(Node **head, int value){
    Node* new_node = create_node(value);
    if (*head == NULL){
        *head = new_node;
        return;
    }
    Node *current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
}

void print_list(Node *head){
    Node *current = head;
    while(current->next != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("%d -> ", current->value);
    printf("NULL\n");
}

void free_list(Node *head){
    Node *current = head;
    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(){
    Node *head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    print_list(head);

    return 0;
}