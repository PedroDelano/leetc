/***********************************
 *
 * Simple stack implementation
 *
 ***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int NULL_VAL = -1;

typedef struct Stack_s {
  int size;
  int count;
  int *data;
} Stack;


Stack *create_stack(int size) {
  Stack *s = malloc(sizeof(Stack));
  int *data = malloc(size * sizeof(int));
  s->size = size;
  s->count = 0;
  s->data = data;
  // initialize data with -1
  for (int i = 0; i < size; i++) {
    s->data[i] = NULL_VAL;
  }
  return s;
}

void push(Stack *s, int value) {
  assert(s->count < s->size && "trying to push on full stack");
  s->data[s->count] = value;
  s->count++;
}

void pop(Stack *s) {
  if (s->count == 0) {
    return;
  }
  s->data[s->count] = NULL_VAL;
  s->count--;
}

// Testing

int main(){

  Stack *s1 = create_stack(5);
  printf("Stack created with size %d\n", s1->size);
  push(s1, 1);
  push(s1, 4);
  push(s1, 9);
  for (int i = 0; i < s1->size; i++) {
    printf("s1[%d] = %d\n", i, s1->data[i]);
  }


  printf("------\n");

  pop(s1);
  pop(s1);
  for (int i = 0; i < s1->size; i++) {
    printf("s1[%d] = %d\n", i, s1->data[i]);
  }

  return 0;
}
