#include <stdio.h>

typedef struct my_st {
  int intVar;
} MyStruct;


int main(int argc, char *argv[]) {
  MyStruct one = {1};
  MyStruct two = {2};
  MyStruct three;

  three = one + two;
  printf("three = %d\n", three);

  (int)three = (int)one + (int)two;
  printf("(int)three = %d\n", (int)three);

  return 0;
}
