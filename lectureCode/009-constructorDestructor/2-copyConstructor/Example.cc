#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#include "Example.h"

using namespace std;

unsigned int Example::globalUid = 0;

// The copy constructor for this class.
Example::Example(const Example &other) : strPtr(NULL) {
  uid = globalUid++;
  _copyFrom(other);
  cout << "Example copy constructor " << toString() << endl;
}

Example::Example(const char *strVal) {
  strPtr = strdup(strVal);
  uid = globalUid++;
  cout << "Example(const char*) constructor " << toString() << endl;
}

Example::~Example() {
  cout << "   Example destructor" << toString() << ")" << endl;
  free(strPtr);
}

Example &Example::operator=(const Example &other) {
  cout << "operator=(" << other.toString() << ")" << endl;
  _copyFrom(other);
  return *this;
}

// This + operator return a new object, allowing us to write expressions
// in a reasonably natural way.  (See main.cc for an example.)
Example Example::operator+(const Example &other) {
  cout << "operator+: " << this->toString() << " + " << other.toString() << endl;
  Example result(*this);
  char *newStr = (char*)malloc(strlen(result.strPtr) + strlen(other.strPtr) + 1);
  if ( newStr != NULL ) {
    strcpy(newStr, result.strPtr);
    strcat(newStr, other.strPtr);
    free(result.strPtr);
    result.strPtr = newStr;
  }
  return result;
}

// (In this example we don't copy the unique id field.)
void Example::_copyFrom(const Example &other) {
  // if the strdup() fails, leave this Example object unchanged
  char *strCopy = strdup(other.strPtr);
  if( strCopy ) {
    if ( strPtr ) free(strPtr);
    strPtr = strCopy;
  }
}

string Example::toString() const {
  ostringstream result;
  result << "[" << uid << ": strPtr = 0x"
         << hex << (unsigned long int)strPtr << " -> '"
         << strPtr << "']";
  return result.str();
}
