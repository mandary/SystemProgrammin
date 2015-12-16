#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *p = array;
  int i;

  printf("array = %p\n", array);
  printf("    p = %p\n", p);

  for (i=0; i<10; i++) {
    printf("%d %d %d\n", array[i], p[i], *(p+i));
  }

  return 0;
}
