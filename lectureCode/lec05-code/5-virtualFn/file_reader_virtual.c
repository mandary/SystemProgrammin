#define  _POSIX_C_SOURCE  200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "file_reader_virtual.h"

#define BUFLEN 4096

static char _nextChar(FileReaderVirtual this) {
  return this->bufIndex < this->bufLen ? 
            this->buf[this->bufIndex++] : 
            FileReaderVirtual__newBuf(this);
}

FileReaderVirtual_vtable FILEREADER_CLASS_VTABLE = 
  { .nextChar = _nextChar };

static void fileError(FileReaderVirtual this) {
  perror(this->filename);
  fprintf(stderr, "Some error reading file '%s'\n", this->filename);
  exit(2);
}

FileReaderVirtual FileReaderVirtual_constructor(FileReaderVirtual this, const char* fname) {
  this->f = open(fname, O_RDONLY);
  if ( this->f < 0 ) fileError(this);
  this->filename = strdup(fname);

  this->buf = (char*)malloc(BUFLEN*sizeof(char));
  if ( this->buf == NULL ) fileError(this);

  this->bufLen = 0;
  this->bufIndex = 0;

  return this;
}

FileReaderVirtual FileReaderVirtual_new(const char* fname) {
  FileReaderVirtual this = (FileReaderVirtual)malloc(sizeof(struct FileReaderVirtual_st));
  if ( this == NULL ) fileError(this);
  this->vtable = &FILEREADER_CLASS_VTABLE;
  return FileReaderVirtual_constructor(this, fname);
}

char FileReaderVirtual__newBuf(FileReaderVirtual this) {
  if ( this->f < 0 ) fileError(this);

  this->bufLen = read( this->f, this->buf, BUFLEN );
  if ( this->bufLen == -1 ) fileError(this);
  if ( this->bufLen == 0 ) return EOF;
  this->bufIndex = 0;

  return this->buf[this->bufIndex++];
}

void FileReaderVirtual_destructor(FileReaderVirtual this) {
  if ( 0 != close(this->f) ) fileError(this);
  if ( this->filename ) free(this->filename);
  if ( this->buf ) free(this->buf);
}

void FileReaderVirtual_delete(FileReaderVirtual this) {
  FileReaderVirtual_destructor(this);
  free(this);
}
