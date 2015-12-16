//------------------------------------------------------------
// preprocessor package
//------------------------------------------------------------

#include <stdio.h>

#include "llist.h"

// Create instances of "the llist class" specialized
// for int and char* types.
// Note that the full definition of the implementations
// will be injected as a result of these macro invocations.
CREATE_LLIST_TYPE(int,int);
CREATE_LLIST_TYPE(char*,string);

static char* string_data[] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  NULL
};
#define LEN  5

//-----------------------------------------------------
// Helper functions
//-----------------------------------------------------
bool printIntEl(int el) {
  printf("%d\n", el);
  return false; // indicate we should continue the iteration
}

bool printStringEl(char *el) {
  printf("%s\n", el);
  return false; // indicate we should continue the iteration
}


// main
int main(int argc, char *argv[]) {

  //-----------------------------------------------------
  // Usage of an int LList
  //-----------------------------------------------------
  LList_int myIntList = LList_int_init(&myIntList);
  for (int i=0; i<LEN; i++) {
    LList_int_push(&myIntList, i);
  }
  printf("LList map:\n");
  LList_int_map(myIntList, printIntEl);
  printf("\n");
  printf("Successive pop()'s:\n");
  while ( !LList_int_isEmpty(myIntList) ) {
    int data = LList_int_pop(&myIntList);
    printf("%d\n", data);
  }

  //-----------------------------------------------------
  // Usage of a char LList
  //-----------------------------------------------------
  LList_string myStringList = LList_string_init(&myStringList);
  for (char **p=string_data; *p; p++) {
    LList_string_push(&myStringList, *p);
  }
  printf("\n\nLList map:\n");
  LList_string_map(myStringList, printStringEl);
  printf("\n");
  printf("Successive pop()'s:\n");
  while ( !LList_string_isEmpty(myStringList) ) {
    char *str = LList_string_pop(&myStringList);
    printf("%s\n", str);
  }
  
  return 0;
}
