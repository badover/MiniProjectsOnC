
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/*
10, 20, 25%  11, 44, 30, 50% 40, 50 ,75%  10, 99, 44 99%

1 2 75 3 85  100 4 125 5 6 7 8 250 9 10 11 500
O(log) ~7

односвязный список
      10
      next>>>>>*324OI23U4P
          20
          next >>>> 30
          <<<< prev 10
          *324OI23U4P                       800            
            30                    next == &&&&&&▼
            next >>>>>>>>>>>>>>>>>>▲            ▼
                              ▼
                            ▼
                50  <<<<<<<<<<<<<<<<<<<<
                next
         <<<<<<<<<<<<<<<<<<
      88

  0     10       22
next > next >  next
   <       <

 O(1) 1 1000  //  O(n)  ~ 10 =~10
*/


typedef struct Node {
  int value;
  struct Node* prev;
  struct Node* next;
} Node;

Node* create_node(int value) {
  Node* new_node = malloc(sizeof(Node));
  if (!new_node) {
    printf("Ошибка выделения памяти \n");
    exit(1);
  }
  new_node->value = value;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}

void append(Node **head, int value){
  Node* new_node = create_node(value);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  new_node->prev = current;
/*
 10   20   30
  N    <     <
 >    >    N      
↑↑
*/
}

void print_forward(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }  
  printf("NULL\n");
}

void print_backward(Node *tail) {
  Node *current = tail;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->prev;
  }  
  printf("NULL\n");
}

void free_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
}

int main() {
  Node *head = NULL;

  append(&head, 10);
  append(&head, 20);
  append(&head, 30);
  append(&head, 40);

  print_forward(head);

  Node *tail = head;
  while (tail && tail->next != NULL) {
    tail = tail->next;
  }
  print_backward(tail);

  // free_list(head);


  return 0;
}
