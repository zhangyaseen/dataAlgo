#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
  int data;
  struct LinkedList *next;
} LinkedList;

LinkedList *create_linkedlist();
void print_list(LinkedList *);
void insert_linkedlist(LinkedList *head, int data);
int insert_after_linkedlist(LinkedList *head, int data, int new_value);
LinkedList *find_linkedlist(LinkedList *head, int data);
int delete_linkedlist(LinkedList *head, int data);
void clean_Linkedlist(LinkedList *head);

int main(void) {
  LinkedList *head = create_linkedlist();
  print_list(head);

  insert_linkedlist(head, 1);
  insert_linkedlist(head, 2);
  insert_linkedlist(head, 3);
  insert_linkedlist(head, 6);
  insert_linkedlist(head, 7);
  print_list(head);

  LinkedList *pos = find_linkedlist(head, 6);
  if (pos != NULL) {
    printf("pos value is :%d\n", pos->data);
  }

  insert_after_linkedlist(head, 3, 5);
  print_list(head);

  delete_linkedlist(head, 5);
  print_list(head);

  clean_Linkedlist(head);
  print_list(head);

  return 0;
}

void clean_Linkedlist(LinkedList *head) {
  LinkedList *current = head;
  while (current != NULL) {
    LinkedList *temp = current;
    current = current->next;
    free(temp);
  }
  head->next = NULL;
}

int delete_linkedlist(LinkedList *head, int data) {
  LinkedList *current = head;
  LinkedList *preview = NULL;
  while (current != NULL) {
    if (current->data == data) {
      LinkedList *temp = current;
      preview->next = current->next;
      free(temp);
      return 0;
    } else {
      preview = current;
      current = current->next;
    }
  }

  return -1;
}

LinkedList *find_linkedlist(LinkedList *head, int data) {
  LinkedList *current = head;
  while (current != NULL) {
    if (data == current->data) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

int insert_after_linkedlist(LinkedList *head, int data, int new_value) {
  LinkedList *current = head;
  LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
  node->data = new_value;

  while (current != NULL) {
    if (current->data == data) {
      node->next = current->next;
      current->next = node;
      return 0;
    }
    current = current->next;
  }

  return -1;
}

void insert_linkedlist(LinkedList *head, int data) {
  LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
  node->data = data;
  node->next = NULL;

  LinkedList *current = head;
  LinkedList *preview;
  while (current != NULL) {
    preview = current;
    current = current->next;
  }

  preview->next = node;
}

void print_list(LinkedList *head) {
  LinkedList *current = head->next;
  while (current != NULL) {
    printf("linedlist val: %d\t", current->data);
    current = current->next;
  }
  printf("\n");
}

LinkedList *create_linkedlist() {
  LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList));
  head->next = NULL;
  return head;
}