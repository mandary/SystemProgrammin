#ifndef FILELISTREADER_H
#define FILELISTREADER_H

// "subclasses" CharSource
#include "CharSource.h"  // not strictly needed for this particular example

#include <stdio.h>
#include <sys/types.h>

typedef struct FileListReader_st *FileListReader;

typedef struct FileListReader_vtable_st {
  char (*nextChar)(FileListReader this);
  void (*delete)(FileListReader this);
} FileListReader_vtable;

typedef struct FileListReader_st  * FileListReader;

FileListReader FileListReader_new(char* argv[], int argc);
FileListReader FileListReader_constructor(FileListReader this, char* argv[], int argc);

void FileListReader_destructor(FileListReader this);

#endif // FILELISTREADER_H