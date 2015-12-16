#include <stdio.h>

#include "func.h"

int minus_one = -1;
int zero = 0;

int main(int argc, char *argv[]) {
  int result0 = func0(zero, minus_one);
  printf("result0 = %d\n", result0);

  int result3 = func3(minus_one, zero);
  printf("result3 = %d\n", result3);

  return result3;
}
