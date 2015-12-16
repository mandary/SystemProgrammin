#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  char **p;

  for ( p = argv+1; *p; p++ ) {
    printf("%12s\n", *p);
  }
  
  return 0;
}
