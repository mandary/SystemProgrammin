#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 1;
  int j = 2;

  int *p = &i;
  printf("i / j / p / *p = %2d / %2d / %p / %2d\n", i, j, p, *p);

  *p = -1;
  printf("i / j / p / *p = %2d / %2d / %p / %2d\n", i, j, p, *p);

  p = &j;
  printf("i / j / p / *p = %2d / %2d / %p / %2d\n", i, j, p, *p);
  
  return 0;
}
