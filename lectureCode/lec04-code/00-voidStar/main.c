//------------------------------------------------
// void* package
//------------------------------------------------

#include <stdio.h>

#include "llist.h"

#define LEN  5

static char* string_data[] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  NULL
};

bool printIntEl(void *el) {
  printf("%ld\n", (long int)el);
  return false; // indicate we should continue the iteration
}

bool printStringEl(void *el) {
  printf("%s\n", (char*)el);
  return false; // indicate we should continue the iteration
}

int main(int argc, char *argv[]) {
  LList myList = LList_init(&myList);

  //---------------------------------------------
  // Usage with int's
  for (long int i=0; i<LEN; i++) {
    LList_push(&myList, (void*)i);
  }

  printf("LList map:\n");
  LList_map(myList, printIntEl);
  printf("\n");

  printf("Successive pop()'s:\n");
  while ( !LList_isEmpty(myList) ) {
    long int data = (long int)LList_pop(&myList);
    printf("%ld\n", data);
  }
  
  //---------------------------------------------
  // Usage with string's
  for (char **p=string_data; *p; p++) {
    LList_push(&myList, *p);
  }

  printf("\n\nLList map:\n");
  LList_map(myList, printStringEl);
  printf("\n");

  printf("Successive pop()'s:\n");
  while ( !LList_isEmpty(myList) ) {
    char* data = (char*)LList_pop(&myList);
    printf("%s\n", data);
  }

  return 0;
}
