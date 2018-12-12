#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 100

struct Stack {
  int last;
  int items[MAX_DATA];
};

struct Stack *Init_stack() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  stack->last = 0;
  int i;
  for (i = 0; i < MAX_DATA; i++) {
    stack->items[i] = -1;
  }
  return stack;
}

int pop_last(struct Stack *stack) {
  int ret = stack->items[stack->last];
  stack->items[stack->last] = -1;
  stack->last--;
  return ret;
}

void add_item(struct Stack *stack, int n) {
  stack->last++;
  stack->items[stack->last] = n;
}

int main() {
  struct Stack *stack = Init_stack();
  int i;


  for (i = 1; i < 11; i++) {
    add_item(stack, i);
  }

  for (i = 0; i < 10; i++) {
    printf("%d\n", pop_last(stack));
  }

  return 0;
}
