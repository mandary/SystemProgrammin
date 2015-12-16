#ifndef FILEREADER_H
#define FILEREADER_H

#include <stdio.h>
#include <sys/types.h>

typedef struct FileReaderVirtual_st *FileReaderVirtual;

typedef struct FileReaderVirtual_vtable_st {
  char (*nextChar)(FileReaderVirtual this);
} FileReaderVirtual_vtable;

typedef struct FileReaderVirtual_st {
  FileReaderVirtual_vtable *vtable;
  char*   filename;
  int     f;
  char*   buf;
  ssize_t bufLen;
  int     bufIndex;
} * FileReaderVirtual;


FileReaderVirtual FileReaderVirtual_new(const char *filename);
FileReaderVirtual FileReaderVirtual_constructor(FileReaderVirtual this, const char *filename);

char FileReaderVirtual__newBuf(FileReaderVirtual this);

void FileReaderVirtual_delete(FileReaderVirtual this);
void FileReaderVirtual_destructor(FileReaderVirtual this);

#endif // FILEREADER_H
