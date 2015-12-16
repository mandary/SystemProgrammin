#include <stdio.h>
#include <error.h>

int globalInt = 160;

void usage(char *cmd) {
  error(1, 0, "Usage: %s <address in hex>\n", cmd);
}

int main(int argc, char *argv[]) {

  if ( argc != 2 ) usage(argv[0]);

  // convert the command line arg from a string (in hex) to a long int
  long unsigned int addr;
  int retcode = sscanf(argv[1], "%lx", &addr);
  if ( retcode != 1 ) usage(argv[0]);

  char *p = (char*)addr;
  printf("p = %ld\n", (long)p);

  printf("*p = %X\n", *p);
  printf("I can read address %ld!\n", addr);

  // try to write to that address
  *p = 0;
  printf("I can write the address!\n");

  return 0;
}
