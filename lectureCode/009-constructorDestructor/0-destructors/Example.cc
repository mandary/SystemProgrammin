#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#include "Example.h"

using namespace std;

unsigned int Example::globalId = 0;

Example::Example(const char *strVal) : other(string("Other") + ":" + strVal) {
  id = globalId++;
  strPtr = strdup(strVal);
  cout << "Example constructor" << toString() << endl;
}

Example::~Example() {
  cout << "   Example destructor" << toString() << ")" << endl;
}

string Example::toString() {
  ostringstream result;
  result << "[" << id << ": strPtr = 0x" << hex << (unsigned long int)strPtr << " -> '"
         << strPtr << "']";
  return result.str();
}
