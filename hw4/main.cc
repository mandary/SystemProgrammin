#include "Automata.h"
#include <fstream>
#include <cstdlib>

using namespace std;

// Yufang Sun
// 1334960
// mandary@uw.edu

void Usage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        Usage();
        return EXIT_FAILURE;
    }
    string regex(argv[1]);  // regex
    Automata nfa(regex);

    ifstream input;
    input.open(argv[2], ios::in);  // open input file
    string line;
    while (getline(input, line)) {
        for (auto it = line.begin(); it != line.end(); it++) {
            string temp(it, line.end());  // temporaray string for match
            if (nfa.match(temp)) {
                cout << line << endl;
                break;
            }
        }
    }

    input.close();

    return EXIT_SUCCESS;
}

// Prints the usage of program
void Usage() {
    cout << "./regexp <regular expression> <filename>" << endl;
    cout << "Support option:" << endl;
    cout << "   c - match the character c" << endl;
    cout << "   rc - match pattern r followed by character c" << endl;
    cout << "   r* - match 0 or more occurrences of pattern r" << endl;
    cout << "   r+ - match 1 or more occurrences of pattern r" << endl;
}