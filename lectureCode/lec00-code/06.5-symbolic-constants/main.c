#include <stdio.h>

#include "func.h"

#define MINUS_ONE -1
#define ZERO       0

int main(int argc, char *argv[]) {
  int result0 = func0(ZERO, MINUS_ONE);
  printf("result0 = %d\n", result0);

  int result3 = func3(MINUS_ONE, ZERO);
  printf("result3 = %d\n", result3);

  return result3;
}
