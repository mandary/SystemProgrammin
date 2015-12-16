#include <stdio.h>
#include <ctype.h>

int globalInt = 10000;

void sub(int x, int *intPtr, int *kindaRef) {
  x = 0;
  intPtr = &globalInt;
  *kindaRef = 0;
}

int main(int argc, char *argv[]) {

  int localInt = 1;
  int refInt = 100;
  int *pInt = &localInt;

  printf("localInt / pInt / refInt = %d / %p (%d) / %d\n",
	 localInt, pInt, *pInt, refInt);

  sub(localInt, pInt, &refInt);

  printf("localInt / pInt / refInt = %d / %p (%d) / %d\n",
	 localInt, pInt, *pInt, refInt);

  return 0;
}
