/***********************************************
 *
 * Dynamic array implementation
 *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct DynamicArray_s {
  int *data;
  size_t size;
  size_t count;
} DynamicArray;


const int INITIAL_SIZE = 10;


DynamicArray *create_array() {

  DynamicArray *vec = malloc(sizeof(DynamicArray));
  int *data = malloc(INITIAL_SIZE * sizeof(int));
  vec->data = data;
  vec->size = INITIAL_SIZE;
  vec->count = 0;
  return vec;

}

void clear_array(DynamicArray *vec) {

  free(vec->data);
  int *data = malloc(vec->size * sizeof(int));
  vec->data = data;
  vec->count = 0;

}

void push(DynamicArray *vec, int value) {

  if (vec->count == vec->size) {
    vec->size = vec->size * 2;
    vec->data = realloc(vec->data, vec->size * sizeof(int));
  }

  vec->data[vec->count] = value;
  vec->count++;

}

void print_array(DynamicArray *vec) {
  printf("{ ");
  for (size_t i = 0; i < vec->count; i++) {
    printf("%d, ", vec->data[i]);
  }
  printf(" }\n");
}

bool isin(DynamicArray *vec, int value) {

  for (size_t i = 0; i < vec->count; i++) {
    if (value == vec->data[i]) {
      return true;
    }
  }
  return false;

}

// ********************************************

int lengthOfLongestSubstring(char* s) {

  size_t len_s = strlen(s);
  size_t mss = 1;

  if (len_s < 2) {
    return len_s;
  }

  DynamicArray *vec = create_array();

  for (size_t i = 0; i <  len_s - 1; i++) {
    clear_array(vec);
    push(vec, s[i]);

    // If the longest substring is greater
    // than the rest of the string, we
    // already got the LARGEST substring.
    if (mss > len_s - i) {
      break;
    }

    for (size_t j = i + 1; j < strlen(s); j++) {

      if (isin(vec, s[j])) {
        break;
      } else {
        push(vec, s[j]);
      }

      if (vec->count > mss) {
        mss = vec->count;
      }

    }
  }

  free(vec->data);
  free(vec);
  return mss;

}

int main() {


  char *test = "abcabcbb";
  // char *test = "bbbbbb";
  // char *test = "au";
  int mss = lengthOfLongestSubstring(test);
  printf("LSS = %d ", mss);

  return 0;
}
