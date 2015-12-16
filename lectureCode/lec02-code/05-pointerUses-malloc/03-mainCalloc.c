#include <stdio.h>
#include <stdlib.h>  // for malloc
#include <error.h>

#define ARRAY_SIZE 100

int main(int argc, char **argv) {
  int *p;

  printf("pre-malloc:\n");
  printf("sizeof(p) = %lu\n", sizeof(p));
  printf("sizeof(*p) = %lu\n", sizeof(*p));

  // calloc zeroes the memory it allocates
  p = (int*)calloc(sizeof(int), ARRAY_SIZE);
  if ( p == NULL ) error(1, 0, "Out of memory!");

  printf("\npost-malloc:\n");
  printf("sizeof(p) = %lu\n", sizeof(p));
  printf("sizeof(*p) = %lu\n", sizeof(*p));

  printf("ARRAY_SIZE * sizeof(in) = %lu\n", 100*sizeof(int));

  printf("\np[0] = %d\n", p[0]);

  free(p);

  return 0;
}
