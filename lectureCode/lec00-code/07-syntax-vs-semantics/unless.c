#include <stdio.h>

#include "unless.h"

int main(int argc, char *argv[]) {
  unless( argc > 1 ) printf("No arguments\n");

  return 0;
}

