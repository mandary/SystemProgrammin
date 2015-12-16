#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define TEST_STRING "test string"

char  globalChar = 'c';
int   globalInt = 25;
char *globalStr = NULL;
int  *globalIntPtr = NULL;

int main(int argc, char *argv[]) {
  char      localChar;
  uint64_t  localUint64;
  char     *localStr;

  globalIntPtr = &globalInt;
  (*globalIntPtr)++;
  printf("*globalIntPtr = %d\n", *globalIntPtr);
  printf("*globalIntPtr = %08x\n", *globalIntPtr);

  localStr = malloc(strlen(TEST_STRING) + 1);
  strcpy(localStr, TEST_STRING);
  globalStr = localStr;
  printf("globalStr = '%s'\n", globalStr);

  *(int*)globalStr = globalInt;
  printf("*(int*)globalStr = %d\n", *(int*)globalStr);
  printf("globalStr = '%s'\n", globalStr);

  localUint64 = (uint64_t)globalStr;
  printf("*(char*)localUint64 = '%s'\n", (char*)localUint64);

  return 0;
}
