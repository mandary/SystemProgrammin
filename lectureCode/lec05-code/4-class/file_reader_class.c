#define  _POSIX_C_SOURCE  200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "file_reader_class.h"

#define BUFLEN 4096

static void fileError(FileReader this) {
  perror(this->filename);
  fprintf(stderr, "Some error reading file '%s'\n", this->filename);
  exit(2);
}

FileReader FileReader_constructor(FileReader this, const char* fname) {
  this->f = open(fname, O_RDONLY);
  if ( this->f < 0 ) fileError(this);
  this->filename = strdup(fname);

  this->buf = (char*)malloc(BUFLEN*sizeof(char));
  if ( this->buf == NULL ) fileError(this);

  this->bufLen = 0;
  this->bufIndex = 0;

  return this;
}

FileReader FileReader_new(const char* fname) {
  FileReader this = (FileReader)malloc(sizeof(struct FileReader_st));
  if ( this == NULL ) fileError(this);

  return FileReader_constructor(this, fname);
}

char FileReader__newBuf(FileReader this) {
  if ( this->f < 0 ) fileError(this);

  this->bufLen = read( this->f, this->buf, BUFLEN );
  if ( this->bufLen == -1 ) fileError(this);
  if ( this->bufLen == 0 ) return EOF;
  this->bufIndex = 0;

  return this->buf[this->bufIndex++];
}

void FileReader_destructor(FileReader this) {
  if ( 0 != close(this->f) ) fileError(this);
  if ( this->filename ) free(this->filename);
  if ( this->buf ) free(this->buf);
}

void FileReader_delete(FileReader this) {
  FileReader_destructor(this);
  free(this);
}
