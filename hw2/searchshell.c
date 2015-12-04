/*
 * Copyright 2011 Steven Gribble
 *
 *  This file is part of the UW CSE 333 course project sequence
 *  (333proj).
 *
 *  333proj is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  333proj is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 333proj.  If not, see <http://www.gnu.org/licenses/>.
 */

// Feature test macro for strtok_r (c.f., Linux Programming Interface p. 63)

// Yufang Sun
// 1334960
// mandary@uw.edu


#define _XOPEN_SOURCE 600
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "libhw1/CSE333.h"
#include "memindex.h"
#include "filecrawler.h"

static void Usage(void);

static void printResult(DocTable table, LinkedList list);


int main(int argc, char **argv) {
  if (argc != 2) Usage();

  // Implement searchshell!  We're giving you very few hints
  // on how to do it, so you'll need to figure out an appropriate
  // decomposition into functions as well as implementing the
  // functions.  There are several major tasks you need to build:
  //
  //  - crawl from a directory provided by argv[1] to produce and index
  //  - prompt the user for a query and read the query from stdin, in a loop
  //  - split a query into words (check out strtok_r)
  //  - process a query against the index and print out the results
  //
  // When searchshell detects end-of-file on stdin (cntrl-D from the
  // keyboard), searchshell should free all dynamically allocated
  // memory and any other allocated resources and then exit.
  printf("Indexing '%s'\n", argv[1]);
  DocTable docTable;
  MemIndex index;
  int res = CrawlFileTree(argv[1], &docTable, &index);
  if (res == 0) {
    fprintf(stderr, "Path '%s' is not indexable\n", argv[1]);
    Usage();
  }

  size_t size = 1024;
  char* str = (char*)malloc(size);  // allocate string buf
  while (1) {  // loop forever
    printf("enter query:\n");
    size_t read = 0;

    if ((read = getline(&str, &size, stdin)) == EOF) break;  // ctrl+d pressed
    for (int i = 0; i < strlen(str); i++) {
      str[i] = tolower(str[i]);  // to lower case
    }
    char* query[read], *left, *temp;
    int i = 0;
    temp = strtok_r(str, " \n", &left);  // split str
    while (temp != NULL) {
      query[i] = temp;
      i++;
      temp = strtok_r(NULL, " \n", &left);
    }
    LinkedList list = MIProcessQuery(index, query, i);
    if (list == NULL) continue;
    printResult(docTable, list);
  }

  printf("shutting down...\n");  // clean up
  free(str);
  FreeDocTable(docTable);
  FreeMemIndex(index);

  return EXIT_SUCCESS;
}


// This prints the searchresult from list
static void printResult(DocTable table, LinkedList list) {
  LLIter it = LLMakeIterator(list, 0);
  SearchResultPtr searchResult;
  do {
    LLIteratorGetPayload(it, (LLPayload_t*)&searchResult);
    printf("  %s (%d)\n", DTLookupDocID(table, searchResult->docid),
     searchResult->rank);
  } while (LLIteratorNext(it));
  LLIteratorFree(it);
  FreeLinkedList(list, free);
}

static void Usage(void) {
  fprintf(stderr, "Usage: ./searchshell <docroot>\n");
  fprintf(stderr,
          "where <docroot> is an absolute or relative " \
          "path to a directory to build an index under.\n");
  exit(-1);
}

