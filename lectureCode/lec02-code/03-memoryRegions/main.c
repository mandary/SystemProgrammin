#include <stdio.h>
#include <stdlib.h>

#include "sub.h"

int globalInt = 0;  // This is the definition of the global

int main(int argc, char *argv[]) {
  char localChar = 0;

  void *p;

  p = &globalInt;
  printf("&globalInt = %p\n", p);

  p = main;
  printf("main = %p\n", p);
  p = &main;
  printf("&main = %p\n", p);

  p = malloc(1);
  printf("malloc returned %p\n", p);

  p = &localChar;
  printf("&localChar = %p\n", p);

  p = "string literal (which is put in static data area)";
  printf("string literal is at %p\n", p);

  // Confusingly, this is both legal and means the same thing
  p = &"string literal (which is put in static data area)";
  printf("&string literal is at %p\n", p);

  printf("sub is at %p\n", sub);
  sub();

  return localChar;

}
