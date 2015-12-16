#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFLEN 24

int main(int argc, char *argv[]) {

  char   buf[BUFLEN+1];  // +1 for the '\0'
  char*  str;
  char*  comparisonOp[] = {"<", "==", ">"};
  char** argP;
  int    size;
  char*  catResult;
  int    cmpResult;

  // copy a string
    strcpy(buf, "test string");  // bug
    printf("buf = '%s'\n", buf);

    //strcpy(str, "test string");  // bigger bug
    //printf("str = '%s'\n", str);

    // duplicate a string
    str = strdup(buf);
    printf("str = '%s'\n", str);

  // string length + concatenate strings
    printf("\nConcatenation result:\n");
    size = 0;
    for (argP=argv; *argP; argP++) {
      size += strlen(*argP);
    }
    catResult = (char*)malloc(sizeof(char)*(size+1));
    if ( catResult == NULL ) {
      perror("string test main()");
    }
    catResult[0] = '\0';
    for (argP=argv; *argP; argP++) {
      strcat(catResult, *argP);
    }
    printf("%s\n", catResult);
    free(catResult);

  // compare successive command line args
    printf("\nComparisons:\n");
    for ( argP=&argv[1]; *argP; argP++ ) {
      printf("%s ", *(argP-1));
      cmpResult = strcmp(*(argP-1), *argP);
      if (cmpResult < 0) cmpResult = -1;
      if (cmpResult > 0) cmpResult = 1;
      printf("%s", (comparisonOp+1)[cmpResult]);
      printf(" %s\n", *argP);
    }
  
  return 0;
}
