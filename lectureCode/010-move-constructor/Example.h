#ifndef EXAMPLE_SUB_H
#define EXAMPLE_SUB_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>

//------------------------------------------------------
// Define symbol _USE_MOVE to enable use of move constructor
// and move assign operator.
// We define that symbol on the command line, in the makefile,
// but a somewhat more clumsy way to do it would be to embed
// one of the following two lines here:
// #undef _USE_MOVE
// #define _USE_MOVE
//------------------------------------------------------

class Example {
  private:
    char* nameStr;    // Pointers are common but can be troublesome

    // These are counters for instrumenting this code
    static int nMoveConstructors;
    static int nCopyConstructors;
    static int nMoveAssigns;
    static int nCopyAssigns;

 public:
  Example(const char* str);                  // String constructor
  Example(const Example &other);             // Copy constructor
  Example& operator=(const Example &other);  // Copy assignment operator

//-------------------------------------------------------
#ifdef _USE_MOVE
  Example(Example &&other) noexcept;            // Move constructor
  Example& operator=(Example &&other) noexcept; // Move assignment operator
#endif // _USE_MOVE
//-------------------------------------------------------

  virtual ~Example();  // destructor
  Example exampleFunc(const Example ex);  // example function
  char const * name() const { return nameStr ? nameStr : ""; }
  static std::string countString();  // utility routine to format fn call counts

};

#endif // EXAMPLE_SUB_H
