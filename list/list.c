#include <stdio.h>
#include <stdlib.h>


struct node {
  int data;
  struct node* next; // pointer to prev node
};
// head is a pointer to a node whose next is a pointer to the top of list
// if next is NULL, its node is the end of list (called as tail)


struct node* init() {
  struct node* new = malloc(sizeof(struct node));

  // if fail to malloc
  if (new == NULL) {
    fprintf(stderr, "Fail to malloc.\n"); // output error message
    return NULL;
  }

  // initialize next
  new->next = NULL;
  return new;
}


// insert value after head
void push(struct node* head, int value) {
  // allocate a new node
  struct node *new = init();

  // if fail to malloc, do nothing
  if (new == NULL)
    return;

  // set data
  new->data = value;

  // insert new node between head and head->next
  new->next = head->next;
  head->next = new;
}


int pop(struct node* head) {
  // get node to pop
  struct node *top = head->next;

  // if list is empty
  if (top == NULL) {
    fprintf(stderr, "List is empty.\n"); // output error message
    return 0;
  }

  // detach top
  head->next = top->next;

  // get data for return value
  int res = top->data;

  // deallocate top
  free(top);
  return res;
}


void display(struct node* head) {
  // traverse all elements
  // loop condition: cur is not NULL, because tail's next is NULL
  for (struct node* cur = head->next; cur != NULL; cur = cur->next) {
    printf("%d ", cur->data);
  }
  printf("\n");
}


void remove_all(struct node* head, int value) {
  struct node* prev = head, *cur;

  // traverse all elements
  // loop condition: prev is not tail
  while (prev->next != NULL) {
    cur = prev->next;
    if (cur->data == value) {
      pop(prev); // prev->next <- prev->next->next
      // prev->next has not been seen yet, so don't go to a next node
    } else {
      prev = cur; // go to a next node
    }
  }
}


// calculate sum of list
int sum(struct node* head) {
  int s = 0;
  for (struct node* cur=head->next; cur != NULL; cur=cur->next) {
    s += cur->data;
  }
  return s;
}


// add 1 to all elements
void increment(struct node* head) {
  for (struct node* cur=head->next; cur != NULL; cur=cur->next) {
    cur->data += 1;
  }
}


void delete(struct node* head) {
  for (;head->next != NULL;) {
    pop(head);
  }
  free(head);
}


int main() {
  struct node* head = init();

  push(head, 0);
  push(head, 1);
  push(head, 2);
  push(head, 3);
  push(head, 4);

  display(head); // 4 3 2 1 0

  pop(head);
  pop(head);
  pop(head);

  display(head); // 1 0

  push(head, 0);
  push(head, 0);
  push(head, 0);
  push(head, 0);

  display(head); // 0 0 0 0 1 0

  remove_all(head, 0);

  display(head); // 1

  push(head, 2);
  push(head, 3);
  push(head, 4);
  push(head, 5);

  display(head); // 5 4 3 2 1

  int s = sum(head);
  printf("%d\n", s); // 15

  increment(head);

  display(head); // 6 5 4 3 2

  s = sum(head);
  printf("%d\n", s); // 20

  delete(head);
  return 0;
}
