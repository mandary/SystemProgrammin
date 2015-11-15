// Yufang Sun
// 1334960
// mandary@uw.edu

#include <iostream>
#include <cstdint>
#include <fcntl.h>
#include <unistd.h>

#include "FileReader.h"
#include "WordCounter.h"

using namespace std;

WordCounter::WordCounter(FileReader &reader){
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

}

int WordCounter::getLines() {
    return lines;
}

int WordCounter::getWords() {
    return words;
}

int WordCounter::getChars() {
    return chars;
}
