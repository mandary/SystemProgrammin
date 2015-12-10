#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include "State.h"

#define START 256

#define FINAL 257

class Automata {
private:
    std::shared_ptr<State> start;

public:
    // Constructor, string should not be empty
    Automata(const std::string &str);

    // Destructor
    ~Automata();

    // Determine a string matched regex
    bool match(const std::string &str);

};

#endif