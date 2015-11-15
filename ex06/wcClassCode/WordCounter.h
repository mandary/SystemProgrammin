#ifndef WORDCOUNTER_H_
#define WORDCOUNTER_H_

#include "FileReader.h"

class WordCounter {
private:
	int lines;
	int words;
	int chars;

public:
	WordCounter(FileReader &reader);

	// Return the #lines in file
	int getLines(void);

	// Return the #words in file
	int getWords(void);

	// Return the #chars in file
	int getChars(void);
};



#endif //WORDCOUNTER_H_