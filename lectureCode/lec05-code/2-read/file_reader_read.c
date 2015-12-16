#define  _POSIX_C_SOURCE  200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "file_reader.h"

static char* filename = NULL;
static int f = -1;

#define BUFLEN 4096
static char buf[BUFLEN];
static ssize_t bufLen = 0;
static int bufIndex = 0;

static void fileError() {
  perror(filename);
  fprintf(stderr, "Some error reading file '%s'\n", filename);
  exit(2);
}

void openFile(const char* fname) {
  f = open(fname, O_RDONLY);
  if ( f < 0 ) fileError();
  filename = strdup(fname);
}

char nextChar() {
  if ( f < 0 ) fileError();

 if ( bufIndex >= bufLen ) {
    bufLen = read( f, buf, BUFLEN );
    if ( bufLen == -1 ) fileError();
    if ( bufLen == 0 ) return EOF;
    bufIndex = 0;
  }
  return buf[bufIndex++];
  
}

void closeFile() {
  if ( 0 != close(f) ) {
    perror("fclose");
    exit(3);
  }
}
