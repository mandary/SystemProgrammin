#define  _POSIX_C_SOURCE  200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"

static char* filename = NULL;
static FILE* f = NULL;

static void fileError() {
  fprintf(stderr, "Some error reading file '%s'\n", filename);
  exit(2);
}

void openFile(const char* fname) {
  f = fopen(fname, "r");
  if ( f == NULL ) fileError(fname);
  filename = strdup(fname);
}

char nextChar() {
  if ( f == NULL ) fileError();
  return fgetc(f);
}

void closeFile() {
  if ( filename != NULL ) free(filename);
  filename = NULL;

  if ( 0 != fclose(f) ) {
    perror("fclose");
    exit(3);
  }
}
