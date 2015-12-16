#include <stdio.h>

int main(int argc, char *argv[]) {
  int x, y;
  x = 0;
  y = 1;

  { int x,y;
    x = 10;
    y = 11;
    printf("x/y = %d / %d\n", x ,y);
  }

  printf("x/y = %d / %d\n", x ,y);

  return 0;
}
