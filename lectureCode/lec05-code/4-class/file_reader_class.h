#ifndef FILEREADER_H
#define FILEREADER_H

#include <stdio.h>
#include <sys/types.h>

typedef struct FileReader_st {
  char*   filename;
  int     f;
  char*   buf;
  ssize_t bufLen;
  int     bufIndex;
} * FileReader;


FileReader FileReader_new(const char *filename);
FileReader FileReader_constructor(FileReader this, const char *filename);

#define FileReader_nextChar(this) ( this->bufIndex < this->bufLen ? this->buf[this->bufIndex++] : FileReader__newBuf(this) )
char FileReader__newBuf(FileReader this);

void FileReader_delete(FileReader this);
void FileReader_destructor(FileReader this);

#endif // FILEREADER_H
