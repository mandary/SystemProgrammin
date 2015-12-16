#include <stdio.h>

int main(int argc, char *argv[]) {

  int array[10];
  char c = 'a';

  int *ip = &array[4];
  int *iq = &array[2];

  void *vp = &array[4];
  void *vq = &array[2];

  char *cp = &c;

  // the base type of the pointer is important to
  // the usual type checking operation of the compiler


  printf("main = %X\n", main);
  ip = main;
  cp = ip;
  printf("*ip = %X\n", *ip);
  printf("*cp = %X (%c)\n", *cp, *cp);

  ip = &array[4];
  
  // the base type also affects the outcome of pointer
  // arithmetic operations 

  long unsigned int idistance = ip - iq;
  printf("\nint* distance = %lu\n", idistance);

  long unsigned int vdistance = vp - vq;
  printf("void* distance = %lu\n", vdistance);

  return 0;
}
