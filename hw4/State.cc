
#include "State.h"

using namespace std;

// Yufang Sun
// 1334960
// mandary@uw.edu

State::State(const int c) : regex(c) {
    // cout << "State " << (char)c << " initialized" << endl;
}

State::~State() {
    // cout << "State destructed" << endl;
}
