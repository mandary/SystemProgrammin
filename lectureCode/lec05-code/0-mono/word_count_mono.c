// License

// This version is just monolithic code -- not very flexible, but potentially fast.
// Build:  gcc -Wall -std=gnu99 -o word_count_fget word_count_fgetc

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>

void usage(char* exeName) {
  fprintf(stderr, "Usage: %s file\nPrints out the number of lines, words, and characters in the file\n", exeName);
  exit(1);
}

void fileError(char* filename) {
  fprintf(stderr, "Some error reading file '%s'\n", filename);
  exit(2);
}

int main(int argc, char* argv[]) {
  if ( argc != 2 ) usage(argv[0]);

  typedef enum {IN_WS, IN_WORD} StateType;
  StateType state = IN_WS;

  FILE* f = fopen(argv[1], "r");
  if ( f == NULL ) fileError(argv[1]);

  uint64_t  chars=0, words=0, lines=0;
  char c;

  while ( (c = fgetc(f)) != EOF ) {
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

  if ( 0 != fclose(f) ) {
    perror("fclose");
    exit(3);
  }

  printf(" %" PRIu64 " lines, %" PRIu64 " words, %" PRIu64 " characters\n",
	 lines, words, chars );
}
