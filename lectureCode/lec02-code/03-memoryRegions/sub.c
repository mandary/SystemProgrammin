#include <stdio.h>

#include "sub.h"

int globalInt;  // this is a declaration of the global

// We're just defining a global function symbol.
// The function doesn't do anything...
void sub() {
  int localChar;

  printf("\nHi from sub\n");
  printf("I'm at %p\n", sub);
  printf("My localChar variable is at %p\n", &localChar);
  printf("globalInt is at %p\n", &globalInt);

}
