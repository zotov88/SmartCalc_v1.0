#include "headers/stack.h"

Stack *push_c(Stack *stack, char c) {
  Stack *element = (Stack *)malloc(sizeof(Stack));
  element->c = c;
  element->next = stack;
  return element;
}

Stack *push_d(Stack *stack, double d) {
  Stack *element = (Stack *)malloc(sizeof(Stack));
  element->d = d;
  element->next = stack;
  return element;
}

char pop_c(Stack **stack) {
  Stack *ptr;
  char c;
  if (*stack == NULL) {
    return '\0';
  }
  ptr = *stack;
  c = ptr->c;
  *stack = ptr->next;
  free(ptr);
  return c;
}

double pop_d(Stack **stack) {
  Stack *ptr;
  double d;
  if (*stack == NULL) {
    return '\0';
  }
  ptr = *stack;
  d = ptr->d;
  *stack = ptr->next;
  free(ptr);
  return d;
}

char peek_c(Stack *stack) {
  char c = '\0';
  if (stack != NULL) {
    c = stack->c;
  }
  return c;
}

int size(Stack *stack) {
  int size = 0;
  Stack *tmp = stack;
  while (tmp != NULL) {
    stack = stack->next;
    tmp = stack;
    size++;
  }
  free(tmp);
  return size;
}

int isEmpty(Stack *stack) { return size(stack) == 0; }

void destroy(Stack *stack) {
  Stack *tmp = stack;
  while (stack != NULL) {
    tmp = tmp->next;
    free(stack);
    stack = tmp;
  }
}
