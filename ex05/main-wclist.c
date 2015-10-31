
//Yufang Sun
//1334960
//mandary@uw.edu


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>
#include "FileListReader.h"
#include "FileReader.h"
#include "WordCounter.h"

void usage(const char* exeName) {
  fprintf(stderr, "Usage: %s a list of file\nPrints out the number of lines, words, and characters in the list of files\n", exeName);
  exit(1);
}

int main(int argc, char* argv[]) {
  if ( argc < 2 ) usage(argv[0]); //illegal arg
  if (argc == 2) {//only one file
    FileReader reader = FileReader_new(argv[1]);
    if ( reader == NULL ) usage(argv[0]);
    WordCounter wc = WordCounter_new((CharSource)reader);
    WordCounter_count(wc);
    ((CharSource)reader)->vtable->delete((CharSource)reader);
    printf(" %" PRIu64 " lines, %" PRIu64 " words, %" PRIu64 " characters\n", WordCounter_lines(wc), WordCounter_words(wc), WordCounter_chars(wc));
    WordCounter_delete(wc);
  } else {//list of files
    FileListReader reader = FileListReader_new(argv, argc - 1);
    if (reader == NULL) usage(argv[0]);
    WordCounter wc = WordCounter_new((CharSource)reader);
    WordCounter_count(wc);
    ((CharSource)reader)->vtable->delete((CharSource)reader);
    printf(" %" PRIu64 " lines, %" PRIu64 " words, %" PRIu64 " characters\n", WordCounter_lines(wc), WordCounter_words(wc), WordCounter_chars(wc));
    WordCounter_delete(wc);
  }
  return 0;
}

