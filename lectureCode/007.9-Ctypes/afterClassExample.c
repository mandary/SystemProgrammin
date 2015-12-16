#include <stdio.h>
#include <inttypes.h>

int main(int argc, char *argv[]) {
  int64_t  intVar;
  double   doubleVar = 8.5;

  intVar = doubleVar;
  printf("1: intVar = %" PRId64 "\n", intVar);

  intVar = (int64_t)doubleVar;
  printf("2: intVar = %" PRId64 "\n", intVar);

  intVar = *(int64_t*)&doubleVar;
  printf("3: intVar = %" PRId64 "\n", intVar);

}
