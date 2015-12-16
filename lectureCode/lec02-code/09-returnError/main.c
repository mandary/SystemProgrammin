#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef char* str;

str upperify(str s) {
  char result[strlen(s)+1];
  char *p;

  strcpy(result, s);
  for (p=result; *p != '\0'; p++) {
    *p = toupper(*p);
  }
  return result;
}

int main(int argc, char *argv[]) {

  int arg;

  // args before upperify'ing
  printf("1st phase:\n");
  for (arg=0; arg<argc; arg++) {
    printf("%3d: %s\n", arg, argv[arg]);
  }

  // upperify them and print
  printf("\n2nd phase:\n");
  for (arg=0; arg<argc; arg++) {
    argv[arg] = upperify(argv[arg]);
    printf("%3d: %s\n", arg, argv[arg]);
  }

  // just print them again
  printf("\n3rd phase:\n");
  for (arg=0; arg<argc; arg++) {
    printf("%3d: %s\n", arg, argv[arg]);
  }

  return 0;
}
