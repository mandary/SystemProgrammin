#ifndef FILEREADER_H
#define FILEREADER_H

#include <sys/types.h>

extern char    buf[];
extern ssize_t bufLen;
extern int     bufIndex;

void openFile(const char* filename);
#define nextChar() ( bufIndex < bufLen ? buf[bufIndex++] : _newBuf() )
char _newBuf();
void closeFile();

#endif // FILEREADER_H
