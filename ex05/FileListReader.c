//Yufang Sun
//1334960
//mandary@uw.edu

#define  _POSIX_C_SOURCE  200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "FileListReader.h"

#define BUFLEN 4096

// Make concrete the struct FileListReader_st type
struct FileListReader_st {
  FileListReader_vtable *vtable;
  char*   filename;
  char*   buf;
  ssize_t bufLen;
  int     bufIndex;
  int     f;
  char**  argv; //stores a list of filenames
  int p2f; //pointer to which file in list
  int argc; //total file in list
};

static void FileListReader__fileError(FileListReader this) {
  perror(this->filename);
  fprintf(stderr, "Some error reading file '%s'\n", this->filename);
  exit(2);
}

static char FileListReader__newBuf(FileListReader this) {
  if ( this->f < 0 ) FileListReader__fileError(this);

  this->bufLen = read( this->f, this->buf, BUFLEN );
  if ( this->bufLen == -1 ) FileListReader__fileError(this);
  if ( this->bufLen == 0 ) {//when reaches the file EOF
    this->p2f++;//go to another file in list
    if (this->p2f <= this->argc) { //if there's a new file
      this->f = open(this->argv[this->p2f], O_RDONLY);
      if ( this->f < 0 ) FileListReader__fileError(this);
      this->filename = strdup(this->argv[this->p2f]);
      this->bufLen = read( this->f, this->buf, BUFLEN );
    } else { //list is traversed
      return EOF;
    }
  }
  this->bufIndex = 0;

  return this->buf[this->bufIndex++];
}

static char _nextChar(FileListReader this) {
  return this->bufIndex < this->bufLen ? 
            this->buf[this->bufIndex++] : 
            FileListReader__newBuf(this);
}

static void _delete(FileListReader this) {
  FileListReader_destructor(this);
  free(this);
}

FileListReader_vtable FILELISTREADER_CLASS_VTABLE = 
  { .nextChar = _nextChar,
    .delete = _delete
  };

FileListReader FileListReader_constructor(FileListReader this, char* argv[], int argc) {
  this->argc = argc;
  this->argv = argv;
  this->p2f = 1;
  this->f = open(this->argv[this->p2f], O_RDONLY);
  if ( this->f < 0 ) FileListReader__fileError(this);
  this->filename = strdup(this->argv[this->p2f]);

  this->buf = (char*)malloc(BUFLEN*sizeof(char));
  if ( this->buf == NULL ) FileListReader__fileError(this);

  this->bufLen = 0;
  this->bufIndex = 0;

  return this;
}

FileListReader FileListReader_new(char* argv[], int argc) {
  FileListReader this = (FileListReader)malloc(sizeof(struct FileListReader_st));
  if ( this == NULL ) FileListReader__fileError(this);
  this->vtable = &FILELISTREADER_CLASS_VTABLE;
  return FileListReader_constructor(this, argv, argc);
}

void FileListReader_destructor(FileListReader this) {
  if ( 0 != close(this->f) ) FileListReader__fileError(this);
  if ( this->filename ) free(this->filename);
  if ( this->buf ) free(this->buf);
}


