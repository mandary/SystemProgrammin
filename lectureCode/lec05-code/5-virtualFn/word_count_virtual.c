// License

// This version has a more flexible code struture: extracting
// characters from their source is left ot a helper class,
// file_reader.
// Depending on which file_reader implementation you link with,
// you get different versions of the application.
// To build, compile this file and one of the file_reader .c files.
//
// file_reader.c:  Does fgetc
// file_reader_getline.c: Uses getline to retrieve a line at a time
// file_reader_read: Uses the unbuffered file interface, and reads file chunks

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>

#include "file_reader_virtual.h"

void usage(const char* exeName) {
  fprintf(stderr, "Usage: %s file\nPrints out the number of lines, words, and characters in the file\n", exeName);
  exit(1);
}

int main(int argc, char* argv[]) {
  if ( argc != 2 ) usage(argv[0]);

  typedef enum {IN_WS, IN_WORD} StateType;
  StateType state = IN_WS;

  FileReaderVirtual reader = FileReaderVirtual_new(argv[1]);

  uint64_t  chars=0, words=0, lines=0;
  char c;

  while ( (c=reader->vtable->nextChar(reader)) != EOF ) {
    chars++;
    if ( c == '\n' ) lines++;
    switch (state) {
      case IN_WS:  if ( !isspace(c) ) {
		     words++;
		     state = IN_WORD;
		   }
                   break;
      case IN_WORD:  if ( isspace(c) ) {
	               state = IN_WS;
                     }
                     break;
    }
  }

  FileReaderVirtual_delete(reader);

  printf(" %" PRIu64 " lines, %" PRIu64 " words, %" PRIu64 " characters\n",
	 lines, words, chars );
}
