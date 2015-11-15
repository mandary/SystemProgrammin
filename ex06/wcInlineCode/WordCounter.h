#ifndef WORDCOUNTER_H_
#define WORDCOUNTER_H_

#include "FileReader.h"

class WordCounter {
private:
    int lines;
    int words;
    int chars;

public:
    inline WordCounter(FileReader &reader) {
        lines = 0, words = 0; chars = 0;
        // basically same procedure as the starter code
        typedef enum {IN_WS, IN_WORD} StateType;
        StateType state = IN_WS;
        char c;
        while ((c = reader.nextChar()) != EOF) {
            chars++;
            if ( c == '\n' ) lines++;
            switch (state) {
              case IN_WS:  if ( !isspace(c) ) {
                     words++;
                     state = IN_WORD;
                   }
                           break;
              case IN_WORD:  if ( isspace(c) ) {
                           state = IN_WS;
                             }
                             break;
            }
        }
    };

    // Return the #lines in file
    inline int getLines(void) {
        return lines;
    };

    // Return the #words in file
    inline int getWords(void) {
        return words;
    };

    // Return the #chars in file
    inline int getChars(void) {
        return chars;
    };
};



#endif //WORDCOUNTER_H_