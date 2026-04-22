/***********************************
 *
 * Simple stack implementation
 *
 ***********************************/

#include <stdio.h>
#include <stdbool.h>
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

int head(Stack *s) {
    if (s->count == 0) {
      return NULL_VAL;
    }
    return s->data[s->count - 1];
}


bool is_empty(Stack *s) {
  return head(s) == -1;
}

/***************************************************
*
* TESTING
*
****************************************************/

void print_stack(Stack *s) {
  printf("Stack: { ");
  for (int i = 0; i < s->count; i++) {
    printf("%d", s->data[i]);
    if (i < s->count - 1) {
      printf(" , ");
    }
  }
  printf(" }\n");
}

int* finalPrices(int* prices, int pricesSize, int* returnSize) {

    *returnSize = pricesSize;
    int *newPrice = malloc(pricesSize * sizeof(int));
    Stack *s1 = create_stack(pricesSize);

    for (int i = pricesSize - 1; i >= 0; i--) {
      newPrice[i] = prices[i];
      while (!is_empty(s1) && head(s1) > prices[i]) {
        pop(s1);
      }
      if (!is_empty(s1)) {
        newPrice[i] = prices[i] - head(s1);
      }
      push(s1, prices[i]);
    }

    free(s1->data);
    free(s1);
    return newPrice;
}

int main(){

  int pricesSize = 4;
  int *returnSize = malloc(sizeof(int));
  int *prices = malloc(pricesSize * sizeof(int));

  prices[0] = 10;
  prices[1] = 1;
  prices[2] = 1;
  prices[3] = 6;

  int *final = finalPrices(prices, pricesSize, returnSize);

  for (int i = 0; i < *returnSize; i++) {
    printf("R[%d] = %d\n", i, final[i]);
  }

  free(prices);
  free(returnSize);
  free(final);

  return 0;
}
