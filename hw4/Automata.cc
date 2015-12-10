
#include "Automata.h"

using namespace std;

// Yufang Sun
// 1334960
// mandary@uw.edu

Automata::Automata(const string &str) {
    start = make_shared<State>(START);
    shared_ptr<State> current = start;
    for (auto it = str.begin(); it != str.end(); it++) {
        switch (*it) {
            case '*':
                // cout << "case *" << endl;
                current->selfLoop = current;
                break;
            case '+':
                // cout << "case +" << endl;
                current->nextState = make_shared<State>(current->regex);
                current = current->nextState;
                current->selfLoop = current;
                break;
            case '\\':
                if (it + 1 != str.end()) {
                    it ++;
                    // cout << "char " << *it << endl;
                    current->nextState = make_shared<State>(*it);
                    current = current->nextState;
                }
                break;
            default:
                // cout << "char " << *it << endl;
                current->nextState = make_shared<State>(*it);
                current = current->nextState;
                break;
        }
    }
    current->nextState = make_shared<State>(FINAL);
}

Automata::~Automata() {
}

bool Automata::match(const string &str) {
    shared_ptr<State> current = start->nextState;
    for (auto it = str.begin(); it != str.end() && current->regex != FINAL; it++) {
        char c = *it;
        if (c != current->regex) {
            if (!current->selfLoop.lock()) {  // no self loop, so not *
                return false;
            } else {  // self loop, check next state
                it--;
            }
        }
        current = current->nextState;  // update current to next
    }
    return true;
}