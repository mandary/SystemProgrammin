#ifndef __EXAMPLE_H
#define __EXAMPLE_H

#include <string>

using namespace std;

class Example {
 private:
  char *strPtr;      // This pointer field causes us to be careful about copying...

 public:
  Example(const Example &other);  // this is a "copy constructor"
  Example(const char *strVal);    // this would prevent compiler synthesis of a copy constructor
  ~Example();  // this is the destructor

  Example &operator=(const Example &other);  // this is an overloaded assignment operator

  Example operator+(const Example &other);   // We overload the "+" operator to mean concatenation

  string toString() const;  // for debug printing

 private:
  void _copyFrom(const Example &other);   // private helper function

 private:
  // Artificial fields used so we can track copies
  unsigned int uid;
  static unsigned int globalUid;
};

#endif // __EXAMPLE_H
