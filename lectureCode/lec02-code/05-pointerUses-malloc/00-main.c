#include <stdio.h>
#include <stdlib.h>  // for malloc
#include <error.h>

#define ARRAY_SIZE 100

int main(int argc, char **argv) {
  int *p;

  printf("pre-malloc:\n");
  printf("sizeof(p) = %lu\n", sizeof(p));
  printf("sizeof(*p) = %lu\n", sizeof(*p));

  p = (int*)malloc(ARRAY_SIZE * sizeof(int));
  if ( p == NULL ) error(1, 0, "Out of memory!");

  printf("\npost-malloc:\n");
  printf("sizeof(p) = %lu\n", sizeof(p));
  printf("sizeof(*p) = %lu\n", sizeof(*p));

  printf("ARRAY_SIZE * sizeof(in) = %lu\n", 100*sizeof(int));

  printf("\np[0] = %d\n", p[0]);

  return 0;
}
