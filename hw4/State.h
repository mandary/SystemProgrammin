#ifndef STATE_H_
#define STATE_H_

#include <memory>
#include <string>
#include <iostream>

class State {
public:
    // ptr to next state
    std::shared_ptr<State> nextState;
    // ptr to self
    std::weak_ptr<State> selfLoop;
    // char
    int regex;

    // Constructor
    State(const int c);

    // Destructor
    ~State();

};

#endif