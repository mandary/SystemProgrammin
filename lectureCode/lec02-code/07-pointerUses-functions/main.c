#include <stdio.h>
#include <stdlib.h>

int sub(int a, int b) {
  return a-b;
}

int add(int a, int b) {
  return a+b;
}

int main(int argc, char *argv[]) {

  int (*op)(int, int);
  int x = 10;
  int y = 100;

  op = add;
  printf("(op <- add) => op(x, y) = %d\n", op(x, y));

  op = sub;
  printf("(op <- sub) => op(x, y) = %d\n", op(x, y));

  return 0;
}
