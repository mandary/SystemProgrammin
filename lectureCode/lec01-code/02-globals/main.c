#include <stdio.h>

void func();

int globalInt = 12345;

int main(int argc, char *argv[]) {

  printf("globalInt = %d\n", globalInt);
  func();
  printf("globalInt = %d\n", globalInt);

  return 0;
}
