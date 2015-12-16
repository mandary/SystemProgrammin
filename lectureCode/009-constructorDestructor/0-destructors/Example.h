#ifndef __EXAMPLE_H
#define __EXAMPLE_H

#include <string>

#include "Other.h"

using namespace std;

class Example {
 public:
  Example(const char  *strVal);
  ~Example();  // this is the destructor

  string toString();

 private:
  char* strPtr;     // A pointer to some memory outside this object
  Other other;      // An Other embedded in this object
  unsigned int id;  // unique id (uid) of this object

  // Repeating "private" here is legal, but purely
  // stylistic.  I'm doing it because I'm defining a class
  // variable, rather than another of the per-object instance
  // variables above.
 private:
  static unsigned int globalId;

};

#endif // __EXAMPLE_H
